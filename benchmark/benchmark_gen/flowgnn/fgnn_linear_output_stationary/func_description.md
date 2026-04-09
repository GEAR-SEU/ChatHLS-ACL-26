Top-Level Function: `linear`

Complete Function Signature of the Top-Level Function:
`void linear(FM_TYPE input[DIM_IN], WT_TYPE weight[DIM_OUT][DIM_IN], WT_TYPE bias[DIM_OUT], hls::stream<array<FM_TYPE, PARALLEL>> &output);`

Inputs:
- `input`: An array of `FM_TYPE` (float) with a size of `DIM_IN` (32). This array represents the input feature map to the linear layer.
- `weight`: A 2D array of `WT_TYPE` (float) with dimensions `DIM_OUT` (16) x `DIM_IN` (32). This array represents the weight matrix of the linear layer.
- `bias`: An array of `WT_TYPE` (float) with a size of `DIM_OUT` (16). This array represents the bias vector of the linear layer.

Outputs:
- `output`: A stream of `array<FM_TYPE, PARALLEL>` (array of float with size 4). This stream outputs the computed results in parallel slices of size `PARALLEL`.

Important Data Structures and Data Types:
- `array<FM_TYPE, PARALLEL>`: A fixed-size array of `FM_TYPE` (float) with a size of `PARALLEL` (4). This data structure is used to store and transmit parallel slices of the output.

Sub-Components:
- None