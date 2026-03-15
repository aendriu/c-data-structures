#include "../include/graph.h"
#include <stdbool.h>

V* alloc_vertex(void* data)
{
    V* v=(V*)malloc(sizeof(V));
    v->data = data;
    return v;
}
void free_vertex(V* v, void(*free_func)(void*))
{
    free_func(v->data);
    free(v);
}

mGraph* create_mGraph(uint n_el)
{
    mGraph* mg = (mGraph*)malloc(sizeof(mGraph));
    V** v = (V**)malloc(n_el*sizeof(V*));
    bool **adj = (bool**)malloc(n_el*sizeof(bool*));
    for(int i=0; i<n_el;i++) {
        adj[i] = (bool*)malloc(n_el*sizeof(bool));
        v[i] = alloc_vertex(NULL);
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
        free_func(mg->v[i]->data);
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


lGraph* create_lGraph(uint n_el)
{
    lGraph* lg = (lGraph*)malloc(sizeof(lGraph));
    lg->n_el = n_el;
    lg->lVs = alloc_list();
    for(int i=0; i<n_el;i++) {
        V* v = alloc_vertex(NULL);
        add_last(lg->lVs, v);
    }
    return lg;
}
void destroy_lGraph(lGraph* lg, void(*free_func)(void*))
{
    for(int i=0; i<lg->n_el; i++) {
        V* v = (V*)get_nth(lg->lVs, i);
        free_vertex(v, free_func);
    }
    free(lg);
}

void ladd_adj(lGraph* lg, uint i, uint j);
void lremove_adj(lGraph* lg, uint i, uint j);

















