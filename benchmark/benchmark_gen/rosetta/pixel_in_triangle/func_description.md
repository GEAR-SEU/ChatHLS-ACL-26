Top-Level Function: `pixel_in_triangle`

Complete Function Signature of the Top-Level Function:
`bit1 pixel_in_triangle(bit8 x, bit8 y, Triangle_2D triangle_2d);`

Inputs:
- `x`: The x-coordinate of the pixel, represented as an 8-bit unsigned integer (`bit8`).
- `y`: The y-coordinate of the pixel, represented as an 8-bit unsigned integer (`bit8`).
- `triangle_2d`: A struct containing the coordinates of the triangle's vertices, represented as 8-bit unsigned integers (`bit8`). The struct has the following fields: `x0`, `y0`, `x1`, `y1`, `x2`, `y2`, and `z`.

Outputs:
- `return value`: A boolean value indicating whether the pixel is inside the triangle, represented as a 1-bit unsigned integer (`bit1`).

Important Data Structures and Data Types:
- `Triangle_2D`: A struct representing a 2D triangle, with fields `x0`, `y0`, `x1`, `y1`, `x2`, `y2`, and `z`, all of type `bit8`. The `z` field is not used in the current implementation.
- `bit1`: A 1-bit unsigned integer type, used to represent boolean values.
- `bit8`: An 8-bit unsigned integer type, used to represent the coordinates of the pixel and the triangle's vertices.

Sub-Components:
- None