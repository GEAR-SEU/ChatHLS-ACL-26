Top-Level Function: `packFloat64`

Complete Function Signature of the Top-Level Function:
`float64 packFloat64(flag zSign, int16 zExp, bits64 zSig);`

Inputs:
- `zSign`: A single-bit flag representing the sign of the floating-point number. It is of type `flag` (int), where 0 indicates a positive number and 1 indicates a negative number.
- `zExp`: An 11-bit signed integer representing the exponent of the floating-point number. It is of type `int16` (int).
- `zSig`: A 52-bit unsigned integer representing the significand (mantissa) of the floating-point number. It is of type `bits64` (unsigned long long int).

Outputs:
- `output`: A 64-bit floating-point number constructed from the sign, exponent, and significand. It is of type `float64` (unsigned long long int).

Important Data Structures and Data Types:
- `flag`: A single-bit integer used to represent the sign of the floating-point number. It is of type `int`.
- `int16`: A 16-bit signed integer used to represent the exponent of the floating-point number. It is of type `int`.
- `bits64`: A 64-bit unsigned integer used to represent the significand and the final floating-point number. It is of type `unsigned long long int`.
- `float64`: A 64-bit unsigned integer used to represent the final floating-point number. It is of type `unsigned long long int`.

Sub-Components:
- None