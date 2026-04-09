Top-Level Function: `projection`

Complete Function Signature of the Top-Level Function:
`void projection(Triangle_3D triangle_3d, Triangle_2D *triangle_2d, bit2 angle);`

Inputs:
- `triangle_3d`: a 3D triangle defined by its three vertices, each with x, y, and z coordinates, represented as a `Triangle_3D` struct.
- `triangle_2d`: a pointer to a 2D triangle that will store the projected result, represented as a `Triangle_2D` struct.
- `angle`: the angle of projection, represented as a `bit2` value, which can be 0, 1, or 2.

Outputs:
- `triangle_2d`: the projected 2D triangle, with its vertices' x and y coordinates calculated based on the 3D triangle's vertices and the angle of projection, and its z coordinate calculated as the average of the 3D triangle's vertices' z coordinates.

Important Data Structures and Data Types:
- `Triangle_3D`: a struct representing a 3D triangle, with fields `x0`, `y0`, `z0`, `x1`, `y1`, `z1`, `x2`, `y2`, and `z2`, each of type `bit8`.
- `Triangle_2D`: a struct representing a 2D triangle, with fields `x0`, `y0`, `x1`, `y1`, `x2`, `y2`, and `z`, each of type `bit8`.
- `bit2`: an unsigned 2-bit integer type, used to represent the angle of projection.
- `bit8`: an unsigned 8-bit integer type, used to represent the coordinates of the 3D and 2D triangles.

Sub-Components:
- None