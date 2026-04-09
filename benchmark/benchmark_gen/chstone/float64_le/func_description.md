Top-Level Function: `float64_le`

Complete Function Signature of the Top-Level Function:
`flag float64_le(float64 a, float64 b);`

Inputs:
- `a`: A 64-bit unsigned integer representing the first floating-point number in IEEE 754 double precision format.
- `b`: A 64-bit unsigned integer representing the second floating-point number in IEEE 754 double precision format.

Outputs:
- `output`: A flag (integer) indicating the result of the comparison. The value is 1 if `a` is less than or equal to `b`, and 0 otherwise.

Important Data Structures and Data Types:
- `flag`: An integer type used to represent boolean values (0 or 1).
- `int16`: A 16-bit signed integer type used to represent the exponent part of the floating-point number.
- `bits64`: A 64-bit unsigned integer type used to represent the fraction part of the floating-point number.
- `float64`: A 64-bit unsigned integer type used to represent the entire floating-point number.

Sub-Components:
- `extractFloat64Sign`:
    - Signature: `flag extractFloat64Sign(float64 a);`
    - Details: Extracts the sign bit from the 64-bit floating-point number `a` by right-shifting the number by 63 bits.
- `extractFloat64Exp`:
    - Signature: `int16 extractFloat64Exp(float64 a);`
    - Details: Extracts the exponent bits from the 64-bit floating-point number `a` by right-shifting the number by 52 bits and masking the lower 11 bits.
- `extractFloat64Frac`:
    - Signature: `bits64 extractFloat64Frac(float64 a);`
    - Details: Extracts the fraction bits from the 64-bit floating-point number `a` by masking the lower 52 bits.