Top-Level Function: `gemm`

Complete Function Signature of the Top-Level Function:
`void gemm(double m1[4096], double m2[4096], double prod[4096]);`

Inputs:
- `m1`: A 2D matrix of size 64x64, represented as a 1D array of `double` values, with a total of 4096 elements. The matrix is stored in row-major order, with each row contiguous in memory.
- `m2`: A 2D matrix of size 64x64, represented as a 1D array of `double` values, with a total of 4096 elements. The matrix is stored in row-major order, with each row contiguous in memory.

Outputs:
- `prod`: A 2D matrix of size 64x64, represented as a 1D array of `double` values, with a total of 4096 elements. The matrix is stored in row-major order, with each row contiguous in memory.

Important Data Structures and Data Types:
- `TYPE`: A `double` data type, used to represent the elements of the input and output matrices.
- `N`: A constant integer value, representing the total number of elements in each matrix (4096).

Sub-Components:
- `outer loop`: A loop that iterates over the rows of the input matrices, with a loop counter `i` ranging from 0 to 63.
- `middle loop`: A loop that iterates over the columns of the input matrices, with a loop counter `j` ranging from 0 to 63.
- `inner loop`: A loop that performs the actual matrix multiplication, iterating over the elements of the input matrices and accumulating the products in a temporary variable `sum`.
- `matrix indexing`: A mechanism that calculates the memory addresses of the input and output matrices, using the loop counters `i`, `j`, and `k` to access the correct elements.