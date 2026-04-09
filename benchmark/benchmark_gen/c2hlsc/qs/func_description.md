Top-Level Function: `quickSort`
Complete Function Signature of the Top-Level Function: `void quickSort(int* arr, int low, int high);`

Inputs:
- `arr`: an array of integers to be sorted
- `low`: the starting index of the sub-array to be sorted
- `high`: the ending index of the sub-array to be sorted

Outputs:
- none

Important Data Structures and Data Types:
- `int`: a 32-bit signed integer
- `int*`: a pointer to an integer
- `int[]`: an array of integers

Sub-Components:
- `partition`:
    - Signature: `int partition(int* arr, int low, int high);`
    - Details: The partition function rearranges the array such that all elements less than the pivot are on the left of the pivot, and all elements greater than the pivot are on the right. The pivot element is then returned as the partition index.
- `swap`:
    - Signature: `void swap(int* a, int* b);`
    - Details: The swap function swaps the values of two integer pointers.