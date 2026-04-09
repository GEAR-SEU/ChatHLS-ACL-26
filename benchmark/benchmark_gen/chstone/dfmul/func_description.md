Top-Level Function: `float64_mul`

Complete Function Signature of the Top-Level Function:
`float64 float64_mul(float64 a, float64 b);`

Inputs:
- `a`: a 64-bit floating-point number, represented as an unsigned 64-bit integer.
- `b`: a 64-bit floating-point number, represented as an unsigned 64-bit integer.

Outputs:
- `return value`: the product of `a` and `b`, represented as a 64-bit floating-point number.

Important Data Structures and Data Types:
- `float64`: a 64-bit floating-point number, represented as an unsigned 64-bit integer.
- `bits64`: an unsigned 64-bit integer.
- `int16`: a signed 16-bit integer.
- `int8`: a signed 8-bit integer.
- `flag`: a boolean value, represented as a signed integer.

Sub-Components:
- `extractFloat64Frac`:
    - Signature: `bits64 extractFloat64Frac(float64 a);`
    - Details: extracts the significand from a 64-bit floating-point number.
- `extractFloat64Exp`:
    - Signature: `int16 extractFloat64Exp(float64 a);`
    - Details: extracts the exponent from a 64-bit floating-point number.
- `extractFloat64Sign`:
    - Signature: `flag extractFloat64Sign(float64 a);`
    - Details: extracts the sign from a 64-bit floating-point number.
- `packFloat64`:
    - Signature: `float64 packFloat64(flag zSign, int16 zExp, bits64 zSig);`
    - Details: packs a 64-bit floating-point number from its sign, exponent, and significand.
- `roundAndPackFloat64`:
    - Signature: `float64 roundAndPackFloat64(flag zSign, int16 zExp, bits64 zSig);`
    - Details: rounds a 64-bit floating-point number and packs it into a 64-bit floating-point number.
- `normalizeFloat64Subnormal`:
    - Signature: `void normalizeFloat64Subnormal(bits64 aSig, int16 *zExpPtr, bits64 *zSigPtr);`
    - Details: normalizes a subnormal 64-bit floating-point number.
- `mul64To128`:
    - Signature: `void mul64To128(bits64 a, bits64 b, bits64 *z0Ptr, bits64 *z1Ptr);`
    - Details: performs 64-bit by 64-bit multiplication and produces a 128-bit product.
- `shift64RightJamming`:
    - Signature: `void shift64RightJamming(bits64 a, int16 count, bits64 *zPtr);`
    - Details: shifts a 64-bit integer to the right and jams the result into a 64-bit integer.