Top-Level Function: `linear`

Complete Function Signature of the Top-Level Function:
`void linear(FM_TYPE input[DIM_IN], WT_TYPE weight[DIM_OUT][DIM_IN], WT_TYPE bias[DIM_OUT], FM_TYPE output[DIM_OUT]);`

Inputs:
- `input`: A vector of size `DIM_IN` (32) containing the input features. Each element is of type `FM_TYPE` (float).
- `weight`: A matrix of size `DIM_OUT x DIM_IN` (16 x 32) containing the weights for the linear transformation. Each element is of type `WT_TYPE` (float).
- `bias`: A vector of size `DIM_OUT` (16) containing the bias terms for the linear transformation. Each element is of type `WT_TYPE` (float).

Outputs:
- `output`: A vector of size `DIM_OUT` (16) containing the transformed output features. Each element is of type `FM_TYPE` (float).

Important Data Structures and Data Types:
- `FM_TYPE`: A floating-point data type (float) used for input and output features.
- `WT_TYPE`: A floating-point data type (float) used for weights and biases.

Sub-Components:
- None