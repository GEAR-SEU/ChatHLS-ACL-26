#include "compute_neighbor_tables.h"

static int in_degree_table[MAX_NODES];
static int out_degree_table[MAX_NODES];
static int neighbor_table_offsets[MAX_NODES];
static int neighbor_table[MAX_EDGES];

int main() {
    int num_nodes = 50;
    int num_edges = 500;

    int edge_list[MAX_NODES][2];
    for (int i = 0; i < num_edges; i++) {
        edge_list[i][0] = i % num_nodes;
        edge_list[i][1] = (i + num_edges / 2) % num_nodes;
    }

    compute(
        edge_list,
        in_degree_table,
        out_degree_table,
        neighbor_table_offsets,
        neighbor_table,
        num_nodes,
        num_edges);

    return 0;
}