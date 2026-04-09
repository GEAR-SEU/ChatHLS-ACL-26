Top-Level Function: `dotProduct`

Complete Function Signature of the Top-Level Function:
`FeatureType dotProduct(FeatureType param[NUM_FEATURES], DataType feature[NUM_FEATURES]);`

Inputs:
- `param`: an array of `NUM_FEATURES` elements of type `FeatureType`, representing the first input vector.
- `feature`: an array of `NUM_FEATURES` elements of type `DataType`, representing the second input vector.

Outputs:
- `result`: a single value of type `FeatureType`, representing the dot product of the input vectors.

Important Data Structures and Data Types:
- `FeatureType`: a 32-bit fixed-point number with 13 integer bits and 19 fractional bits, used to represent the elements of the `param` vector.
- `DataType`: a 16-bit fixed-point number with 4 integer bits and 12 fractional bits, used to represent the elements of the `feature` vector.

Sub-Components:
- None