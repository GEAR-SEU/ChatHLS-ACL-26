Top-Level Function: `compute`

Complete Function Signature of the Top-Level Function:
`void compute(int edge_list[MAX_EDGES][2], int in_degree_table[MAX_NODES], int out_degree_table[MAX_NODES], int neighbor_table_offsets[MAX_NODES], int neighbor_table[MAX_EDGES], int num_nodes, int num_edges);`

Inputs:
- `edge_list`: A 2D array of integers representing the edge list of the graph. Each element `edge_list[i][0]` is the source node and `edge_list[i][1]` is the destination node of the i-th edge. The data type is `int` and the layout is a 2D array with dimensions `[MAX_EDGES][2]`.
- `in_degree_table`: An array of integers representing the in-degree of each node. The data type is `int` and the layout is a 1D array with size `MAX_NODES`.
- `out_degree_table`: An array of integers representing the out-degree of each node. This input is not used in the current implementation but is included in the function signature. The data type is `int` and the layout is a 1D array with size `MAX_NODES`.
- `neighbor_table_offsets`: An array of integers that will store the starting index for each node's neighbors in the neighbor table. The data type is `int` and the layout is a 1D array with size `MAX_NODES`.
- `neighbor_table`: An array of integers that will store the source nodes for each destination node. The data type is `int` and the layout is a 1D array with size `MAX_EDGES`.
- `num_nodes`: An integer representing the number of nodes in the graph. The data type is `int`.
- `num_edges`: An integer representing the number of edges in the graph. The data type is `int`.

Outputs:
- `neighbor_table_offsets`: An array of integers that stores the starting index for each node's neighbors in the neighbor table. The data type is `int` and the layout is a 1D array with size `MAX_NODES`.
- `neighbor_table`: An array of integers that stores the source nodes for each destination node. The data type is `int` and the layout is a 1D array with size `MAX_EDGES`.

Important Data Structures and Data Types:
- `neightbor_table_offsets_temp`: An array of integers used to temporarily store the cumulative sums of the in-degree table. The data type is `int` and the layout is a 1D array with size `MAX_NODES`.

Sub-Components:
- None
