Top-Level Function: `BlockFrequency`

Complete Function Signature of the Top-Level Function:
`void BlockFrequency(double *result, int epsilon[M * N]);`

Inputs:
- `result`: A pointer to a double where the computed sum of squared deviations will be stored. The data type is `double` to accommodate the precision of the statistical measure.
- `epsilon`: A 2D array of integers with dimensions \( M \times N \) (flattened into a 1D array of size \( M \times N \)). Each element in the array is either 0 or 1, representing the binary matrix.

Outputs:
- `result`: The computed sum of squared deviations of block frequencies from 0.5, stored in the location pointed to by the `result` pointer.

Important Data Structures and Data Types:
- `epsilon`: A 1D array of integers with a size of \( M \times N \). Each element is either 0 or 1, representing the binary matrix. The data type is `int`.

Sub-Components:
- None