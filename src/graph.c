#include "graph.h"

/* : def
typedef struct G {
    V* Vs;
    void *E;
    uint size; // how many elements
    uint capacity; // max number of elements
    
    Operations* op;
    int(*cmp)(const void* a, const void* b);
    int(*free_data)(void*);
}G;
*/

// : ops
/*
typedef struct Operations {
    int(*add_v)(void *E);
    int(*add_edge)(void *E, uint i, uint j);
    int(*rm_edge)(void *E, uint i, uint j);
    bool(*has_edge)(void *E, uint i, uint j);
    int(*resize)(void *E, uint ns);
    void(*destroy)(void *E, uint size);
}Operations;
*/

int madd_v(void *E);
int madd_edge(void *E, uint i, uint j);
int mrm_edge(void *E, uint i, uint j);
bool mhas_edge(void *E, uint i, uint j);
int mresize(void* E, uint ns);
void mdestroy(void *E, uint size);


int ladd_v(void *E);
int ladd_edge(void *E, uint i, uint j);
int lrm_edge(void *E, uint i, uint j);
bool lhas_edge(void *E, uint i, uint j);
int lresize(void* E, uint ns);
void ldestroy(void *E, uint size);

// : mops
Operations mGraphOps = {
    .add_v = madd_v,
    .add_edge = madd_edge,
    .rm_edge = mrm_edge,
    .has_edge = mhas_edge,
    .resize = mresize,
    .destroy = mdestroy
};

// : lops
Operations lGraphOps = {
    .add_v = ladd_v,
    .add_edge = ladd_edge,
    .rm_edge = lrm_edge,
    .has_edge = lhas_edge, 
    .resize = lresize,
    .destroy = ldestroy
};

// Helpers
G* graph_create(GraphImpl impl);

// Specific member functions

int graph_add_v(void *E);
int graph_add_edge(void *E, uint i, uint j);
int graph_rm_edge(void *E, uint i, uint j);
bool graph_has_edge(void *E, uint i, uint j);
void graph_destroy(void *E, uint size);


