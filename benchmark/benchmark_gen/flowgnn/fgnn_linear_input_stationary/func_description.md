Top-Level Function: `linear`

Complete Function Signature of the Top-Level Function:
`void linear(hls::stream<array<FM_TYPE, PARALLEL>> &input, WT_TYPE weight[DIM_OUT][DIM_IN], WT_TYPE bias[DIM_OUT], FM_TYPE output[DIM_OUT]);`

Inputs:
- `input`: A stream of arrays of type `FM_TYPE` with size `PARALLEL`. This represents the input data that is streamed into the kernel in chunks of size `PARALLEL`.
- `weight`: A 2D array of type `WT_TYPE` with dimensions `DIM_OUT x DIM_IN`. This represents the weight matrix used in the linear transformation.
- `bias`: An array of type `WT_TYPE` with size `DIM_OUT`. This represents the bias vector added to the result of the matrix-vector multiplication.

Outputs:
- `output`: An array of type `FM_TYPE` with size `DIM_OUT`. This represents the output of the linear transformation after applying the bias and, if enabled, the ReLU activation function.

Important Data Structures and Data Types:
- `array<FM_TYPE, PARALLEL>`: A fixed-size array of type `FM_TYPE` with size `PARALLEL`. This is used to represent chunks of the input data that are streamed into the kernel.
- `FM_TYPE`: A floating-point type (typically `float`) used to represent the elements of the input data and the output.
- `WT_TYPE`: A floating-point type (typically `float`) used to represent the elements of the weight matrix and the bias vector.

Sub-Components:
- None