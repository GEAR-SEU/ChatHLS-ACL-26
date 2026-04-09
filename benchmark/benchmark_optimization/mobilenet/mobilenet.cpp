#include "mobilenet.h"
#include <hls_half.h>
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <fstream>


inline int relu6_int8(final_wide_t x, const int quantized_six) {
    const final_wide_t zero = 0;
    final_wide_t result = std::min((final_wide_t)quantized_six, std::max(zero, x));
    return (int)result;
}


void conv2d(
    fm_t *in, fm_t *out, const wt_t *weights, const bias_t *bias,
    const int multiplier,
    const int shift,
    const int input_zp,
    const int quantized_six,
    int InCh, int OutCh, int InDim, int OutDim, int K, int S
) {

    const int P = K / 2;

    OCH: for (int och = 0; och < OutCh; ++och) {
        ROW: for (int r = 0; r < OutDim; ++r) {
          COL: for (int c = 0; c < OutDim; ++c) {
                acc_t acc = 0;
				KR: for (int kr = 0; kr < K; ++kr) {
					KC: for (int kc = 0; kc < K; ++kc) {
						ICH: for (int ich = 0; ich < InCh; ++ich) {
                            int in_r = r * S + kr - P;
                            int in_c = c * S + kc - P;
                            fm_t pixel_q = 0;
                            if (in_r >= 0 && in_r < InDim && in_c >= 0 && in_c < InDim) {
                                pixel_q = in[in_r * InDim * InCh + in_c * InCh + ich];
                            }
                            wt_t weight_q = weights[och*InCh*K*K + ich*K*K + kr*K + kc];

                            acc += (pixel_q - input_zp) * weight_q;

                        }
                    }
                }
                acc += bias[och];
                final_wide_t rescaled_acc = (final_wide_t)acc * multiplier;
                rescaled_acc = rescaled_acc >> shift;

                out[och * OutDim * OutDim + r * OutDim + c] = relu6_int8(rescaled_acc, quantized_six);
            }
        }
    }
}


void depthwise_conv2d(
    fm_t *in, fm_t *out, const wt_t *weights, const bias_t *bias,
    const int multiplier,
    const int shift,
    const int quantized_six,
    int Ch, int InDim, int OutDim, int K, int S
) {
    const int P = K / 2;

    ROW: for (int r = 0; r < OutDim; ++r) {
        COL: for (int c = 0; c < OutDim; ++c) {
            CH: for (int ch = 0; ch < Ch; ++ch) {
                acc_t acc = 0;
                KR: for (int kr = 0; kr < K; ++kr) {
                    KC: for (int kc = 0; kc < K; ++kc) {
                        int in_r = r * S + kr - P;
                        int in_c = c * S + kc - P;
                        fm_t pixel_q = 0;
                        if (in_r >= 0 && in_r < InDim && in_c >= 0 && in_c < InDim) {
                            pixel_q = in[ch * InDim * InDim + in_r * InDim + in_c];
                        }
                        wt_t weight_q = weights[ch*K*K + kr*K + kc];
                        acc += pixel_q * weight_q;
                    }
                }
                acc += bias[ch];

                final_wide_t rescaled_acc = (final_wide_t)acc * multiplier;
                rescaled_acc = rescaled_acc >> shift;

                out[ch * OutDim * OutDim + r * OutDim + c] = relu6_int8(rescaled_acc, quantized_six);
            }
        }
    }

}

void pointwise_conv2d(
    fm_t *in, fm_t *out, const wt_t *weights, const bias_t *bias,
    const int multiplier,
    const int shift,
    const int quantized_six,
    int InCh, int OutCh, int Dim
) {
	OCH: for (int och = 0; och < OutCh; ++och) {
		ROW_COL: for (int i = 0; i < Dim * Dim; ++i) {
            acc_t acc = 0;
            ICH: for (int ich = 0; ich < InCh; ++ich) {
                wt_t weight_q = weights[och * InCh + ich];
                fm_t pixel_q = in[ich * Dim * Dim + i];
                acc += pixel_q * weight_q;
            }
            acc += bias[och];

            final_wide_t rescaled_acc = (final_wide_t)acc * multiplier;
            rescaled_acc = rescaled_acc >> shift;

            out[och * Dim * Dim + i] = relu6_int8(rescaled_acc, quantized_six);
        }
    }
}

void avg_pool(fm_t *in, fm_t *out, int Ch, int Dim) {
    const int pool_size = Dim * Dim;
    const int MULT_FACTOR = 21;
    const int SHIFT_FACTOR = 5;

    POOL_CH: for (int ch = 0; ch < Ch; ++ch) {
        acc_t sum = 0;
        POOL_IN: for (int i = 0; i < pool_size; ++i) {
            sum += in[ch * pool_size + i];
        }
        int64_t scaled_sum = (int64_t)sum * MULT_FACTOR;
        int avg_val = scaled_sum >> SHIFT_FACTOR;

        if (avg_val > 127) avg_val = 127;
        else if (avg_val < -128) avg_val = -128;
        out[ch] = (fm_t)avg_val;
    }
}

void fully_connected(
    fm_t *in, int *out, const wt_t *weights, const bias_t *bias,
	const int multiplier,
	const int shift
) {
    FC_OUT: for (int i = 0; i < NUM_CLASSES; ++i) {
    	final_wide_t acc = 0;
        FC_IN: for (int j = 0; j < FC_IN_FEATURES; ++j) {
            wt_t weight_q = weights[i * FC_IN_FEATURES + j];
            fm_t input_q = in[j];
            acc += input_q * weight_q;
        }
        acc += bias[i];

        final_wide_t scaled_acc = acc * multiplier;
        out[i] = scaled_acc >> shift;
    }
}

void mobilenet(
	int image_in_stream[INPUT_IMG_SIZE],
	int prediction[NUM_CLASSES]
) {

    static fm_t buffer1[MAX_FM_SIZE];
    static fm_t buffer2[MAX_FM_SIZE];
    static fm_t quantized_input_buffer[INPUT_IMG_SIZE];

	LOAD_INPUT: for(int i = 0; i < INPUT_IMG_SIZE; ++i) {
		quantized_input_buffer[i] = image_in_stream[i];
	}

    // --- 2. Conv1 ---
    conv2d(quantized_input_buffer, buffer1, conv1_weights, conv1_bias,
           conv1_output_multiplier, conv1_output_shift, conv1_input_zp, conv1_quantized_six,
           IMG_CH, CONV1_OUT_CH, IMG_DIM, CONV1_OUT_DIM, 3, 2);

    // --- 3. Blocks ---
    // Block 0
    depthwise_conv2d(buffer1, buffer2, block0_dw_weights, block0_dw_bias,
                     block0_dw_output_multiplier, block0_dw_output_shift, block0_dw_quantized_six,
                     BLOCK0_IN_CH, BLOCK0_IN_DIM, BLOCK0_OUT_DIM, 3, 1);

    pointwise_conv2d(buffer2, buffer1, block0_pw_weights, block0_pw_bias,
                     block0_pw_output_multiplier, block0_pw_output_shift, block0_pw_quantized_six,
                     BLOCK0_IN_CH, BLOCK0_OUT_CH, BLOCK0_OUT_DIM);

    // Block 1
    depthwise_conv2d(buffer1, buffer2, block1_dw_weights, block1_dw_bias,
                     block1_dw_output_multiplier, block1_dw_output_shift, block1_dw_quantized_six,
                     BLOCK1_IN_CH, BLOCK1_IN_DIM, BLOCK1_OUT_DIM, 3, 2);

    pointwise_conv2d(buffer2, buffer1, block1_pw_weights, block1_pw_bias,
                     block1_pw_output_multiplier, block1_pw_output_shift, block1_pw_quantized_six,
                     BLOCK1_IN_CH, BLOCK1_OUT_CH, BLOCK1_OUT_DIM);

    // Block 2
    depthwise_conv2d(buffer1, buffer2, block2_dw_weights, block2_dw_bias,
                     block2_dw_output_multiplier, block2_dw_output_shift, block2_dw_quantized_six,
                     BLOCK2_IN_CH, BLOCK2_IN_DIM, BLOCK2_OUT_DIM, 3, 2);

    pointwise_conv2d(buffer2, buffer1, block2_pw_weights, block2_pw_bias,
                     block2_pw_output_multiplier, block2_pw_output_shift, block2_pw_quantized_six,
                     BLOCK2_IN_CH, BLOCK2_OUT_CH, BLOCK2_OUT_DIM);

    // Block 3
    depthwise_conv2d(buffer1, buffer2, block3_dw_weights, block3_dw_bias,
                     block3_dw_output_multiplier, block3_dw_output_shift, block3_dw_quantized_six,
                     BLOCK3_IN_CH, BLOCK3_IN_DIM, BLOCK3_OUT_DIM, 3, 2);

    pointwise_conv2d(buffer2, buffer1, block3_pw_weights, block3_pw_bias,
                     block3_pw_output_multiplier, block3_pw_output_shift, block3_pw_quantized_six,
                     BLOCK3_IN_CH, BLOCK3_OUT_CH, BLOCK3_OUT_DIM);

    // Block 4
    depthwise_conv2d(buffer1, buffer2, block4_dw_weights, block4_dw_bias,
                     block4_dw_output_multiplier, block4_dw_output_shift, block4_dw_quantized_six,
                     BLOCK4_IN_CH, BLOCK4_IN_DIM, BLOCK4_OUT_DIM, 3, 2);

    pointwise_conv2d(buffer2, buffer1, block4_pw_weights, block4_pw_bias,
                     block4_pw_output_multiplier, block4_pw_output_shift, block4_pw_quantized_six,
                     BLOCK4_IN_CH, BLOCK4_OUT_CH, BLOCK4_OUT_DIM);

    fm_t* final_conv_out = buffer1;

    // --- 4. Pooling ---
    fm_t pool_out[FC_IN_FEATURES];
    avg_pool(final_conv_out, pool_out, BLOCK4_OUT_CH, BLOCK4_OUT_DIM);

    // --- 5. Fully Connected ---
    fully_connected(pool_out, prediction, fc_weights, fc_bias, fc_final_multiplier, fc_final_shift);

}
