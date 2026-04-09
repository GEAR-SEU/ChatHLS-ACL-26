Top-Level Function: `mul64To128`

Complete Function Signature of the Top-Level Function:
`void mul64To128(bits64 a, bits64 b, bits64 *z0Ptr, bits64 *z1Ptr);`

Inputs:
- `a`: A 64-bit unsigned integer representing the first multiplicand.
- `b`: A 64-bit unsigned integer representing the second multiplicand.

Outputs:
- `z0Ptr`: A pointer to a 64-bit unsigned integer where the lower 64 bits of the product will be stored.
- `z1Ptr`: A pointer to a 64-bit unsigned integer where the upper 64 bits of the product will be stored.

Important Data Structures and Data Types:
- `bits64`: An unsigned 64-bit integer type used for the inputs and outputs of the multiplication.
- `bits32`: An unsigned 32-bit integer type used for intermediate calculations to split the 64-bit inputs into manageable parts.

Sub-Components:
- None