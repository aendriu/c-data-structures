#ifndef GRAPH_ALGS_H
#define GRAPH_ALGS_H
#include "../include/graph_algs.h"

void dfs(G* g, int start, void (*visit)(const void* data));
void bfs(G* g, int start, void (*visit)(const void* data));

void hamolonian_graph(G* g, int start, void (*visit)(const void* data));

#endif // GRAPH_ALGS_H