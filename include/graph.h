#ifndef GRAPH
#define GRAPH

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "../include/list.h"

typedef unsigned int uint;


typedef struct V {
    void *data;
} V;

//

typedef struct mGraph {
    uint n_el;
    V *v;
    bool **adj;
} mGraph;

// *

typedef struct lGraph {
    uint n_el;
    List **adj;
} lGraph;

// *


V* alloc_vertex(void* data);
void free_vertex(void* v, void(*free_func)(void*));

mGraph* create_mGraph(uint n_el);
void destroy_mGraph(mGraph* mg, void(*free_func)(void*));

void madd_adj(mGraph* ,uint, uint);
void mremove_adj(mGraph*, uint, uint);

lGraph* create_lGraph(uint n_el);
void destroy_lGraph(lGraph* lg, void(*free_func)(void*));

void ladd_adj(lGraph* lg, uint i, uint j);
void lremove_adj(lGraph* lg, uint i, uint j);




#endif

