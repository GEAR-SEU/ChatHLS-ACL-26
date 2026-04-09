Top-Level Function: `ms_mergesort`

Complete Function Signature of the Top-Level Function:
`void ms_mergesort(TYPE a[SIZE]);`

Inputs:
- `a`: an array of `SIZE` elements of type `TYPE` (int32_t), representing the input array to be sorted.

Outputs:
- `a`: the sorted array of `SIZE` elements of type `TYPE` (int32_t), representing the output of the merge sort algorithm.

Important Data Structures and Data Types:
- `TYPE`: an integer data type (int32_t) used to represent the elements of the input array.
- `SIZE`: a constant integer value (2048) representing the size of the input array.
- `temp`: a temporary array of `SIZE` elements of type `TYPE` used to store intermediate results during the merge process.

Sub-Components:
- `merge`:
    - Signature: `void merge(TYPE a[SIZE], int start, int m, int stop);`
    - Details: The `merge` sub-component implements the merge step of the merge sort algorithm, taking three indices (`start`, `m`, and `stop`) and the input array `a` as inputs, and producing a merged and sorted subarray as output. The `merge` sub-component consists of three loops: `merge_label1` and `merge_label2` copy the left and right halves of the input array into a temporary array, respectively, and `merge_label3` merges the two halves into a single sorted array.