Top-Level Function: `check_clockwise`

Complete Function Signature of the Top-Level Function:
`int check_clockwise(Triangle_2D triangle_2d);`

Inputs:
- `triangle_2d`: a `Triangle_2D` struct containing the coordinates of the triangle's vertices, with fields:
  - `x0`: the x-coordinate of the first vertex, represented as an 8-bit unsigned integer (`bit8`)
  - `y0`: the y-coordinate of the first vertex, represented as an 8-bit unsigned integer (`bit8`)
  - `x1`: the x-coordinate of the second vertex, represented as an 8-bit unsigned integer (`bit8`)
  - `y1`: the y-coordinate of the second vertex, represented as an 8-bit unsigned integer (`bit8`)
  - `x2`: the x-coordinate of the third vertex, represented as an 8-bit unsigned integer (`bit8`)
  - `y2`: the y-coordinate of the third vertex, represented as an 8-bit unsigned integer (`bit8`)
  - `z`: a reserved field, represented as an 8-bit unsigned integer (`bit8`)

Outputs:
- `cw`: an integer representing the orientation of the triangle, with a positive value indicating a counterclockwise orientation, a negative value indicating a clockwise orientation, and a zero value indicating collinear vertices

Important Data Structures and Data Types:
- `Triangle_2D`: a struct representing a 2D triangle, with fields `x0`, `y0`, `x1`, `y1`, `x2`, `y2`, and `z`, all represented as 8-bit unsigned integers (`bit8`)
- `bit8`: an 8-bit unsigned integer type, used to represent the coordinates of the triangle's vertices

Sub-Components:
- None