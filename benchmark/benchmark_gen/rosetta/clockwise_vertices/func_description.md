Top-Level Function: `clockwise_vertices`

Complete Function Signature of the Top-Level Function:
`void clockwise_vertices(Triangle_2D *triangle_2d);`

Inputs:
- `triangle_2d`: a pointer to a `Triangle_2D` struct, which represents the 2D triangle to be reordered. The struct contains the following fields:
  - `x0`, `y0`: the x and y coordinates of the first vertex, represented as 8-bit unsigned integers.
  - `x1`, `y1`: the x and y coordinates of the second vertex, represented as 8-bit unsigned integers.
  - `x2`, `y2`: the x and y coordinates of the third vertex, represented as 8-bit unsigned integers.
  - `z`: the z-coordinate of the triangle, represented as an 8-bit unsigned integer.

Outputs:
- None, the kernel modifies the input `triangle_2d` struct in-place.

Important Data Structures and Data Types:
- `Triangle_2D`: a struct representing a 2D triangle, containing the x and y coordinates of the three vertices, as well as a z-coordinate. The struct is composed of 8-bit unsigned integers, and is used as the input and output data structure for the kernel.
- `bit8`: an 8-bit unsigned integer type, used to represent the coordinates of the triangle vertices.

Sub-Components:
- None