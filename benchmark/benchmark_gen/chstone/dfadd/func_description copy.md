Top-Level Function: `float64_add`

Complete Function Signature of the Top-Level Function:
`float64 float64_add(float64 a, float64 b);`

Inputs:
- `a`: a 64-bit floating-point number, represented as an unsigned long long integer.
- `b`: a 64-bit floating-point number, represented as an unsigned long long integer.

Outputs:
- `result`: the sum of `a` and `b`, represented as a 64-bit floating-point number.

Important Data Structures and Data Types:
- `float64`: a 64-bit floating-point number, represented as an unsigned long long integer.
- `int8`: an 8-bit integer, used to represent the float_rounding_mode variable and exception flags.
- `int16`: a 16-bit integer, used to represent the exponent component of a floating-point number.
- `bits64`: an unsigned 64-bit integer, used to represent the significand component of a floating-point number.

Sub-Components:
- `addFloat64Sigs`:
    - Signature: `float64 addFloat64Sigs(float64 a, float64 b, flag zSign);`
    - Details: performs the addition of two significands, based on the signs of the input numbers.
- `subFloat64Sigs`:
    - Signature: `float64 subFloat64Sigs(float64 a, float64 b, flag zSign);`
    - Details: performs the subtraction of two significands, based on the signs of the input numbers.
- `normalizeRoundAndPackFloat64`:
    - Signature: `float64 normalizeRoundAndPackFloat64(flag zSign, int16 zExp, bits64 zSig);`
    - Details: normalizes the result and packs it back into a floating-point number, handling rounding and exception handling.