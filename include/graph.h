#ifndef GRAPH
#define GRAPH

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "../include/list.h"

typedef unsigned int uint;

typedef enum {
    ADJ_MAT,
    ADJ_LST
} GraphImpl;

typedef struct V {
    void* data;
}V;

typedef struct Operations {
    int(*add_v)(void *E);
    int(*add_edge)(void *E, uint i, uint j);
    int(*rm_edge)(void *E, uint i, uint j);
    bool(*has_edge)(void *E, uint i, uint j);
    int(*resize)(void *E, uint ns);
    void(*destroy)(void *E, uint size);
}Operations;

extern Operations mGraphOps;
extern Operations lGraphOps;

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



typedef struct G {
    V* Vs;
    void *E;
    uint size; // how many elements
    uint capacity; // max number of elements
    
    Operations* op;
    int(*cmp)(const void* a, const void* b);
    int(*free_data)(void*);
}G;

// Helpers
G* graph_create(GraphImpl impl);

// Specific member functions

int graph_add_v(void *E);
int graph_add_edge(void *E, uint i, uint j);
int graph_rm_edge(void *E, uint i, uint j);
bool graph_has_edge(void *E, uint i, uint j);
void graph_destroy(void *E, uint size);

#endif
