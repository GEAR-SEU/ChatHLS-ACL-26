Top-Level Function: `outer_product`

Complete Function Signature of the Top-Level Function:
`void outer_product(gradient_t gradient[MAX_HEIGHT][MAX_WIDTH], outer_t outer_product[MAX_HEIGHT][MAX_WIDTH]);`

Inputs:
- `gradient`: A 2D array of `gradient_t` structures, representing the input vectors. Each `gradient_t` contains three `pixel_t` components (x, y, z). The array dimensions are `MAX_HEIGHT` x `MAX_WIDTH`.

Outputs:
- `outer_product`: A 2D array of `outer_t` structures, representing the computed outer products. Each `outer_t` contains six `outer_pixel_t` components, which are the results of the pairwise multiplications of the input vector components. The array dimensions are `MAX_HEIGHT` x `MAX_WIDTH`.

Important Data Structures and Data Types:
- `gradient_t`: A structure containing three `pixel_t` components (x, y, z). Used to represent the input vectors.
- `outer_t`: A structure containing six `outer_pixel_t` components. Used to represent the output vectors.
- `pixel_t`: A fixed-point data type (`ap_fixed<32, 13>`) representing the components of the input vectors.
- `outer_pixel_t`: A fixed-point data type (`ap_fixed<32, 27>`) representing the components of the output vectors.

Sub-Components:
- None