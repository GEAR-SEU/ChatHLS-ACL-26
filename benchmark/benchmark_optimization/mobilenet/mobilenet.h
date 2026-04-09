#ifndef MOBILENET_H
#define MOBILENET_H

#include <stdint.h>
#include "weights.h"
#include <hls_half.h>


typedef int8_t fm_t;
typedef int8_t wt_t;
typedef int32_t bias_t;
typedef int32_t acc_t;
typedef int32_t final_wide_t;

final_wide_t approximate_multiply(fm_t a, wt_t b);

//
#define IMG_DIM 128
#define IMG_CH 3
#define INPUT_IMG_SIZE (IMG_DIM * IMG_DIM * IMG_CH)

// Conv1 (stride=2)
#define CONV1_OUT_CH 16
#define CONV1_OUT_DIM 64

// Block 0 (stride=1)
#define BLOCK0_IN_CH CONV1_OUT_CH
#define BLOCK0_OUT_CH 32
#define BLOCK0_IN_DIM CONV1_OUT_DIM
#define BLOCK0_OUT_DIM 64

// Block 1 (stride=2)
#define BLOCK1_IN_CH BLOCK0_OUT_CH
#define BLOCK1_OUT_CH 64
#define BLOCK1_IN_DIM BLOCK0_OUT_DIM
#define BLOCK1_OUT_DIM 32

// Block 2 (stride=2)
#define BLOCK2_IN_CH BLOCK1_OUT_CH
#define BLOCK2_OUT_CH 128
#define BLOCK2_IN_DIM BLOCK1_OUT_DIM
#define BLOCK2_OUT_DIM 16

// Block 3 (stride=2)
#define BLOCK3_IN_CH BLOCK2_OUT_CH
#define BLOCK3_OUT_CH 256
#define BLOCK3_IN_DIM BLOCK2_OUT_DIM
#define BLOCK3_OUT_DIM 8

// Block 4 (stride=2)
#define BLOCK4_IN_CH BLOCK3_OUT_CH
#define BLOCK4_OUT_CH 512
#define BLOCK4_IN_DIM BLOCK3_OUT_DIM
#define BLOCK4_OUT_DIM 4

#define FC_IN_FEATURES BLOCK4_OUT_CH
#define NUM_CLASSES 5

#define MAX_FM_SIZE (BLOCK0_OUT_CH * BLOCK0_OUT_DIM * BLOCK0_OUT_DIM)

#endif
