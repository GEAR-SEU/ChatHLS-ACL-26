Top-Level Function: `blockmatmul`

Complete Function Signature of the Top-Level Function:
`void blockmatmul(hls::stream<blockvec> &Arows, hls::stream<blockvec> &Bcols, blockmat &ABpartial, int it);`

Inputs:
- `Arows`: A stream of `blockvec` elements representing blocks of rows from matrix A. Each `blockvec` contains `BLOCK_SIZE` elements of type `DTYPE`.
- `Bcols`: A stream of `blockvec` elements representing blocks of columns from matrix B. Each `blockvec` contains `BLOCK_SIZE` elements of type `DTYPE`.
- `ABpartial`: A reference to a `blockmat` structure where the partial product of the block multiplication will be stored. The `blockmat` structure contains a `BLOCK_SIZE x BLOCK_SIZE` matrix of type `DTYPE`.
- `it`: An integer representing the current iteration count, used to determine when to load new rows from matrix A.

Outputs:
- `ABpartial`: The partial product of the block multiplication is stored in the `out` field of the `blockmat` structure. The `out` field is a `BLOCK_SIZE x BLOCK_SIZE` matrix of type `DTYPE`.

Important Data Structures and Data Types:
- `blockvec`: A structure representing a block of elements from matrix A or B. It contains an array `a` of size `BLOCK_SIZE` with elements of type `DTYPE`.
- `blockmat`: A structure representing the partial output matrix. It contains a 2D array `out` of size `BLOCK_SIZE x BLOCK_SIZE` with elements of type `DTYPE`.

Sub-Components:
- None