Top-Level Function: `update_knn`

Complete Function Signature of the Top-Level Function:
`void update_knn(WholeDigitType test_inst, WholeDigitType train_inst, int min_distances[K_CONST]);`

Inputs:
- `test_inst`: a 256-bit unsigned integer representing the test instance.
- `train_inst`: a 256-bit unsigned integer representing the training instance.
- `min_distances`: an array of integers of size `K_CONST` representing the minimum distances.

Outputs:
- None (the kernel updates the `min_distances` array in-place).

Important Data Structures and Data Types:
- `WholeDigitType`: a 256-bit unsigned integer type used to represent the test and training instances.
- `min_distances`: an array of integers of size `K_CONST` used to store the minimum distances.

Sub-Components:
- `popcount`:
    - Signature: `int popcount(WholeDigitType x);`
    - Details: a function that counts the number of set bits in a given 256-bit unsigned integer. This function is used to calculate the Hamming distance between the test instance and the training instance.