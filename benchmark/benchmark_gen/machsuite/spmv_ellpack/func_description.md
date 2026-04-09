Top-Level Function: `ellpack`

Complete Function Signature of the Top-Level Function:
`void ellpack(TYPE nzval[N * L], int32_t cols[N * L], TYPE vec[N], TYPE out[N])`

Inputs:
- `nzval`: a 2D array of size N x L, where N is the number of rows in the sparse matrix and L is the maximum number of non-zero elements per row. Each element is of type `TYPE` (double precision floating point). The array stores the non-zero values of the sparse matrix.
- `cols`: a 2D array of size N x L, where N is the number of rows in the sparse matrix and L is the maximum number of non-zero elements per row. Each element is of type `int32_t`. The array stores the column indices of the non-zero elements in the sparse matrix.
- `vec`: a 1D array of size N, where N is the number of rows in the sparse matrix. Each element is of type `TYPE` (double precision floating point). The array stores the dense vector to be multiplied with the sparse matrix.

Outputs:
- `out`: a 1D array of size N, where N is the number of rows in the sparse matrix. Each element is of type `TYPE` (double precision floating point). The array stores the result of the matrix-vector product.

Important Data Structures and Data Types:
- `TYPE`: a double precision floating point data type used to represent the elements of the sparse matrix and the dense vector.
- `int32_t`: a 32-bit integer data type used to represent the column indices of the non-zero elements in the sparse matrix.

Sub-Components:
- `ellpack_1`: a loop that iterates over the rows of the sparse matrix, computing the dot product of each row with the dense vector.
- `ellpack_2`: a nested loop that iterates over the non-zero elements of each row, computing the product of each non-zero element with the corresponding element of the dense vector and accumulating the results.