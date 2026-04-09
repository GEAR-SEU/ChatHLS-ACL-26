Top-Level Function: `Overlapping`

Complete Function Signature of the Top-Level Function:
`void Overlapping(double *result, int epsilon[N]);`

Inputs:
- `result`: A pointer to a double where the computed chi-square statistic will be stored. The data type is `double` to accommodate the potential range of the chi-square value.
- `epsilon`: An array of integers of size `N` (10320) representing the binary dataset. Each element in the array is either 0 or 1.

Outputs:
- `result`: The computed chi-square statistic is stored in the location pointed to by `result`.

Important Data Structures and Data Types:
- `nu`: An array of unsigned integers of size 6 used to count the number of windows with 0 to 4 matches and a combined count for 5 or more matches. The data type is `unsigned int` and the size is 6.
- `pi`: An array of doubles of size 6 containing predefined weights used in the chi-square computation. The data type is `double` and the size is 6.
- `sequence`: An array of characters of size 9 representing the pattern to be matched. The data type is `char` and the size is 9.

Sub-Components:
- None