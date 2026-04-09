Top-Level Function: `fft`

Complete Function Signature of the Top-Level Function:
`void fft(double real[FFT_SIZE], double img[FFT_SIZE], double real_twid[FFT_SIZE / 2], double img_twid[FFT_SIZE / 2]);`

Inputs:
- `real`: an array of `FFT_SIZE` (1024) `double` values representing the real component of the input sequence.
- `img`: an array of `FFT_SIZE` (1024) `double` values representing the imaginary component of the input sequence.
- `real_twid`: an array of `FFT_SIZE/2` (512) `double` values representing the real component of the twiddle factors.
- `img_twid`: an array of `FFT_SIZE/2` (512) `double` values representing the imaginary component of the twiddle factors.

Outputs:
- The transformed real and imaginary components are stored in the input arrays `real` and `img`, respectively.

Important Data Structures and Data Types:
- `double`: a 64-bit floating-point data type used to represent the real and imaginary components of the input sequence and twiddle factors.
- `FFT_SIZE`: a constant integer value (1024) representing the size of the input sequence.

Sub-Components:
- `outer`: the outer loop that iterates over the span of the input sequence, dividing it into smaller segments for processing.
    - Signature: `for (span = FFT_SIZE >> 1; span; span >>= 1, log++)`
    - Details: The outer loop is used to divide the input sequence into smaller segments, with each segment being processed independently.
- `inner`: the inner loop that iterates over the odd indices of the input sequence, applying the butterfly operation to combine adjacent elements.
    - Signature: `for (odd = span; odd < FFT_SIZE; odd++)`
    - Details: The inner loop is used to apply the butterfly operation to each segment of the input sequence, combining adjacent elements to produce a new set of elements.
- `twiddle factor multiplication`: the component that performs the complex multiplication of the input elements with the precomputed twiddle factors.
    - Signature: `temp = real_twid[rootindex] * real[odd] - img_twid[rootindex] * img[odd];`
    - Details: The twiddle factor multiplication component is used to combine the results of the butterfly operation with the precomputed twiddle factors, producing the final transformed output.