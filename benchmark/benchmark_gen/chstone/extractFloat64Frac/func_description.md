Top-Level Function: `extractFloat64Frac`

Complete Function Signature of the Top-Level Function:
`bits64 extractFloat64Frac(float64 a);`

Inputs:
- `a`: A 64-bit unsigned integer representing a floating-point number in IEEE 754 double precision format. The input is expected to be in the form of an `unsigned long long int` to facilitate bitwise operations.

Outputs:
- The function returns a 64-bit unsigned integer (`bits64`) that contains the fractional part of the input floating-point number. The returned value is obtained by masking out the sign and exponent bits, leaving only the 52-bit fractional part.

Important Data Structures and Data Types:
- `bits64`: An unsigned 64-bit integer type (`unsigned long long int`) used to represent the fractional part of the floating-point number.
- `float64`: An unsigned 64-bit integer type (`unsigned long long int`) used to represent the input floating-point number in IEEE 754 double precision format.

Sub-Components:
- None