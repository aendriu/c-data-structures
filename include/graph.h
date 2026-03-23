#ifndef GRAPH
#define GRAPH

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "../include/list.h"

#define GRAPH_INIT_SIZE 10

typedef unsigned int uint;

typedef enum {
    ADJ_MAT,
    ADJ_LST
} GraphImpl;

typedef struct V {
    void* data;
}V;

typedef struct G G;

typedef struct Operations {
    int(*add_v)(G* G, void* data);
    int(*add_edge)(G* G, uint i, uint j);
    int(*rm_edge)(G* G, uint i, uint j);
    bool(*has_edge)(G* G, uint i, uint j);
    void(*resize)(G* G, uint ns);
    void(*destroy)(G* G, uint size);
}Operations;

extern Operations mGraphOps;
extern Operations lGraphOps;

int madd_v(G* G, void* data);
int madd_edge(G* G, uint i, uint j);
int mrm_edge(G* G, uint i, uint j);
bool mhas_edge(G* G, uint i, uint j);
void mresize(G* G, uint ns);
void mdestroy_E(G* G);
void mdestroy_V(G* G); 
void mdestroy(G* G, uint size);


int ladd_v(G* G, void* data);
int ladd_edge(G* G, uint i, uint j);
int lrm_edge(G* G, uint i, uint j);
bool lhas_edge(G* G, uint i, uint j);
void lresize(G* G, uint ns);
void ldestroy(G* G, uint size);
void ldestroy_E(G* G);
void ldestroy_V(G* G);

typedef struct G {
    V* Vs;
    void *E;
    uint size; // how many elements
    uint capacity; // max number of elements
    
    Operations* op;
    int(*cmp)(const void* a, const void* b);
    int(*free_data)(void*);
}G;

// Graph creation
G* mgraph_create();
G* lgraph_create();
// Helpers
G* graph_create(GraphImpl impl);

// Specific member functions

int graph_add_v(G* G, void* data);
int graph_add_edge(G* G, uint i, uint j);
int graph_rm_edge(G* G, uint i, uint j);
bool graph_has_edge(G* G, uint i, uint j);
void graph_print(G* G);
void graph_print_with_data(G* G, void(*print_data)(const void* data));
void graph_destroy(G* G, uint size);

#endif
