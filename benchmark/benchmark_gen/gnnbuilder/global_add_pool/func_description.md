Top-Level Function: `add_pool`

Complete Function Signature of the Top-Level Function:
`void add_pool(int num_nodes, T_data node_embedding_table[MAX_NODES][EMB_SIZE], T_data pooled_embedding[EMB_SIZE]);`

Inputs:
- `num_nodes`: An integer representing the number of nodes in the graph. It specifies how many rows of the `node_embedding_table` should be considered for the summation. The value of `num_nodes` should be between 1 and `MAX_NODES` (inclusive).
- `node_embedding_table`: A 2D array of type `T_data` with dimensions `MAX_NODES x EMB_SIZE`. Each row of this table represents the embedding of a node in the graph. The actual number of rows used is determined by `num_nodes`.

Outputs:
- `pooled_embedding`: A 1D array of type `T_data` with size `EMB_SIZE`. This array will store the result of summing the embeddings of all nodes. Each element of this array is the sum of the corresponding elements from all node embeddings.

Important Data Structures and Data Types:
- `node_embedding_table`: A 2D array of type `T_data` with dimensions `MAX_NODES x EMB_SIZE`. Each element of this array is a `float` representing a component of a node's embedding.
- `pooled_embedding`: A 1D array of type `T_data` with size `EMB_SIZE`. Each element of this array is a `float` representing the sum of the corresponding components from all node embeddings.

Sub-Components:
- None