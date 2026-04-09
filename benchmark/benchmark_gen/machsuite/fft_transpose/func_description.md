Top-Level Function: `fft1D_512`

Complete Function Signature of the Top-Level Function:
`void fft1D_512(TYPE work_x[512], TYPE work_y[512]);`

Inputs:
- `work_x`: an array of 512 `TYPE` elements representing the real part of the input signal
- `work_y`: an array of 512 `TYPE` elements representing the imaginary part of the input signal

Outputs:
- `work_x`: an array of 512 `TYPE` elements representing the real part of the output signal in the frequency domain
- `work_y`: an array of 512 `TYPE` elements representing the imaginary part of the output signal in the frequency domain

Important Data Structures and Data Types:
- `TYPE`: a data type representing a double-precision floating-point number
- `complex_t`: a struct representing a complex number with real and imaginary parts of type `TYPE`

Sub-Components:
- `twiddles8`: a function that calculates the twiddle factors for an 8-point FFT
  - Signature: `void twiddles8(TYPE a_x[8], TYPE a_y[8], int i, int n);`
  - Details: This function calculates the twiddle factors for an 8-point FFT using the following equation: $W_{N}^{k} = e^{-j2\pi k/N}$. The twiddle factors are used to perform the complex multiplications required by the FFT algorithm.
- `FFT8`: a function that performs an 8-point FFT on a complex input signal
  - Signature: `void FFT8(TYPE a_x[8], TYPE a_y[8]);`
  - Details: This function performs an 8-point FFT on a complex input signal using the Cooley-Tukey FFT algorithm. The function uses a series of complex multiplications, additions, and twiddle factor calculations to transform the input signal into the frequency domain.
- `loadx8` and `loady8`: functions that load 8 complex numbers from an input array into a local array
  - Signature: `void loadx8(TYPE a_x[8], TYPE x[512], int offset, int sx);` and `void loady8(TYPE a_y[8], TYPE x[512], int offset, int sx);`
  - Details: These functions load 8 complex numbers from an input array into a local array. The functions are used to prepare the input data for the FFT algorithm.