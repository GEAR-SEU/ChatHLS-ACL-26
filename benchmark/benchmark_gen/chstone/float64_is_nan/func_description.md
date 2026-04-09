Top-Level Function: `float64_is_nan`

Complete Function Signature of the Top-Level Function:
`flag float64_is_nan(float64 a);`

Inputs:
- `a`: A 64-bit floating-point number (IEEE 754 double precision) of type `float64`. This input is the number to be checked for NaN.

Outputs:
- The function returns a `flag` indicating whether the input number is a NaN. The return value is 0 if the number is not NaN, and a non-zero value if the number is NaN.

Important Data Structures and Data Types:
- `float64`: An unsigned 64-bit integer type representing a 64-bit floating-point number (IEEE 754 double precision). It is used to store the input number.
- `bits64`: An unsigned 64-bit integer type used for bitwise operations. It is used to perform the NaN check by comparing the shifted bits of the input number.
- `flag`: An integer type used to return the result of the NaN check. It is 0 if the number is not NaN, and a non-zero value if the number is NaN.

Sub-Components:
- None