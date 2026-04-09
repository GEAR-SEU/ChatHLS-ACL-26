Top-Level Function: `add128`

Complete Function Signature of the Top-Level Function:
`void add128(bits64 a0, bits64 a1, bits64 b0, bits64 b1, bits64 *z0Ptr, bits64 *z1Ptr);`

Inputs:
- `a0`: the low 64 bits of the first input number, represented as an unsigned 64-bit integer.
- `a1`: the high 64 bits of the first input number, represented as an unsigned 64-bit integer.
- `b0`: the low 64 bits of the second input number, represented as an unsigned 64-bit integer.
- `b1`: the high 64 bits of the second input number, represented as an unsigned 64-bit integer.
- `z0Ptr`: a pointer to store the low 64 bits of the result, represented as an unsigned 64-bit integer.
- `z1Ptr`: a pointer to store the high 64 bits of the result, represented as an unsigned 64-bit integer.

Outputs:
- `*z0Ptr`: the low 64 bits of the result, stored in the memory location pointed to by `z0Ptr`.
- `*z1Ptr`: the high 64 bits of the result, stored in the memory location pointed to by `z1Ptr`.

Important Data Structures and Data Types:
- `bits64`: an unsigned 64-bit integer type, used to represent the input numbers and the result.

Sub-Components:
- None