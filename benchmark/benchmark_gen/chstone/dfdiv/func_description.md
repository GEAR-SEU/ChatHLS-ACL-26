Top-Level Function: `float64_div`

Complete Function Signature of the Top-Level Function:
`float64 float64_div(float64 a, float64 b);`

Inputs:
- `a`: a 64-bit floating-point number, the dividend.
- `b`: a 64-bit floating-point number, the divisor.

Outputs:
- `return value`: a 64-bit floating-point number, the quotient of `a` and `b`.

Important Data Structures and Data Types:
- `float64`: a 64-bit floating-point number, represented as an unsigned long long integer.
- `bits64`: an unsigned 64-bit integer.
- `sbits64`: a signed 64-bit integer.
- `int8`: an 8-bit signed integer.
- `int16`: a 16-bit signed integer.
- `bits16`: an unsigned 16-bit integer.
- `bits32`: an unsigned 32-bit integer.

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
    - Details: rounds and packs a 64-bit floating-point number from its sign, exponent, and significand.
- `normalizeFloat64Subnormal`:
    - Signature: `void normalizeFloat64Subnormal(bits64 aSig, int16 *zExpPtr, bits64 *zSigPtr);`
    - Details: normalizes a subnormal 64-bit floating-point number.
- `estimateDiv128To64`:
    - Signature: `bits64 estimateDiv128To64(bits64 a0, bits64 a1, bits64 b);`
    - Details: estimates the quotient of a 128-bit by 64-bit division.
- `mul64To128`:
    - Signature: `void mul64To128(bits64 a, bits64 b, bits64 *z0Ptr, bits64 *z1Ptr);`
    - Details: multiplies two 64-bit numbers to produce a 128-bit result.
- `add128`:
    - Signature: `void add128(bits64 a0, bits64 a1, bits64 b0, bits64 b1, bits64 *z0Ptr, bits64 *z1Ptr);`
    - Details: adds two 128-bit numbers.
- `sub128`:
    - Signature: `void sub128(bits64 a0, bits64 a1, bits64 b0, bits64 b1, bits64 *z0Ptr, bits64 *z1Ptr);`
    - Details: subtracts two 128-bit numbers.
- `shift64RightJamming`:
    - Signature: `void shift64RightJamming(bits64 a, int16 count, bits64 *zPtr);`
    - Details: shifts a 64-bit number right with jamming.