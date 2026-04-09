Top-Level Function: `md`

Complete Function Signature of the Top-Level Function:
`void md(int n_points[blockSide][blockSide][blockSide], dvector_t force[blockSide][blockSide][blockSide][densityFactor], dvector_t position[blockSide][blockSide][blockSide][densityFactor])`

Inputs:
- `n_points`: a 3D array of integers, where `n_points[i][j][k]` represents the number of points in block `(i, j, k)`. Each element is a 32-bit integer.
- `position`: a 4D array of `dvector_t` structures, where `position[i][j][k][l]` represents the position of point `l` in block `(i, j, k)`. Each `dvector_t` structure contains three `TYPE` (double) fields: `x`, `y`, and `z`.
- `force`: a 4D array of `dvector_t` structures, where `force[i][j][k][l]` represents the force acting on point `l` in block `(i, j, k)`. Each `dvector_t` structure contains three `TYPE` (double) fields: `x`, `y`, and `z`.

Outputs:
- `force`: the updated force array, where each element `force[i][j][k][l]` represents the new force acting on point `l` in block `(i, j, k)`.

Important Data Structures and Data Types:
- `dvector_t`: a structure containing three `TYPE` (double) fields: `x`, `y`, and `z`, used to represent 3D vectors.
- `ivector_t`: a structure containing three 32-bit integer fields: `x`, `y`, and `z`, used to represent 3D integer vectors.
- `TYPE`: a type definition for `double`, used to represent floating-point numbers.

Sub-Components:
- `loop_grid0`: a set of three nested loops that iterate over the 3D grid of blocks.
- `loop_grid1`: a set of three nested loops that iterate over the 3x3x3 cube of blocks around a given block.
- `loop_p`: a loop that iterates over the points in a block.
- `loop_q`: a loop that iterates over the points in a neighboring block.