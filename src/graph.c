#include "../include/graph.h"
#include <stdbool.h>

V* alloc_vertex(void* data);
void free_vertex(void* v, void(*free_func)(void*));

mGraph* create_mGraph(uint n_el)
{
    mGraph* mg = (mGraph*)malloc(sizeof(mGraph));
    V* v = (V*)malloc(n_el*sizeof(V));
    bool **adj = (bool**)malloc(n_el*sizeof(bool*));
    for(int i=0; i<n_el;i++) {
        adj[i] = (bool*)malloc(n_el*sizeof(bool));
        v->data = NULL;
    }
    for(int i=0; i<n_el;i++) {
        for(int j=0; j<n_el;j++) {
            adj[i][j] = 0;
        }
    }
    mg->n_el = n_el;
    mg->adj = adj;
    mg->v = v;
    return mg;
}
void destroy_mGraph(mGraph* mg, void(*free_func)(void*))
{
    for(int i=0; i<mg->n_el; i++) {
        free_func(mg->v[i].data);
        free(mg->adj[i]);
    }
    free(mg->adj);
    free(mg->v);
    free(mg);
}

void madd_adj(mGraph* mg, uint i, uint j) 
{
    mg->adj[i][j] = 1;
}
void mremove_adj(mGraph* mg, uint i, uint j)
{
    mg->adj[i][j] = 0;
}


lGraph* create_lGraph(uint n_el);
void destroy_lGraph(lGraph* lg, void(*free_func)(void*));

void ladd_adj(lGraph* lg, uint i, uint j);
void lremove_adj(lGraph* lg, uint i, uint j);

















