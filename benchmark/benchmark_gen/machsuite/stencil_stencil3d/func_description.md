Top-Level Function: `stencil3d`

Complete Function Signature of the Top-Level Function:
`void stencil3d(TYPE C[2], TYPE orig[SIZE], TYPE sol[SIZE]);`

Inputs:
- `C`: a 1D array of two coefficients, `C[0]` and `C[1]`, of type `int32_t`, used for weighting the stencil operation.
- `orig`: a 3D array of input values, of size `SIZE` (row_size x col_size x height_size), of type `int32_t`, representing the original data.
- `sol`: a 3D array of output values, of size `SIZE` (row_size x col_size x height_size), of type `int32_t`, representing the solution.

Outputs:
- `sol`: the 3D array of output values, of size `SIZE` (row_size x col_size x height_size), of type `int32_t`, representing the solution.

Important Data Structures and Data Types:
- `TYPE`: an alias for `int32_t`, used to represent the data type of the input and output arrays.
- `SIZE`: a constant representing the total size of the 3D array, computed as `row_size * col_size * height_size`.
- `INDX`: a macro used to compute the index of an element in the 3D array, given its row, column, and height indices.

Sub-Components:
- `Boundary condition handling`: a set of nested loops that fill the output array with original values at the boundaries.
- `Stencil computation`: a set of nested loops that apply the stencil operation to each element of the input array, using the coefficient array and the original values.