#include "graph.h"
#include <stdio.h>

static bool** graph_edges(G* G)
{
    return (bool**)G->E;
}

int madd_v(G* G, void* data)
{
    assert(G != NULL);
    if (G->size >= G->capacity) {
        G->op->resize(G, G->capacity == 0 ? GRAPH_INIT_SIZE : (2 * G->capacity));
    }

    G->Vs[G->size].data = data;
    G->size += 1;
    return 0;
}

int madd_edge(G* G, uint i, uint j)
{
    assert(G != NULL);
    if (i >= G->size || j >= G->size) {
        return -1;
    }

    graph_edges(G)[i][j] = true;
    return 0;
}

int mrm_edge(G* G, uint i, uint j)
{
    assert(G != NULL);
    if (i >= G->size || j >= G->size) {
        return -1;
    }

    graph_edges(G)[i][j] = false;
    return 0;
}

bool mhas_edge(G* G, uint i, uint j)
{
    assert(G != NULL);
    if (i >= G->size || j >= G->size) {
        return false;
    }

    return graph_edges(G)[i][j];
}

void mresize(G* G, uint ns)
{
    uint i;
    uint j;
    V* new_Vs;
    bool** old_m;
    bool** new_m;

    assert(G != NULL);
    if (ns <= G->capacity) {
        return;
    }

    new_Vs = (V*)calloc(ns, sizeof(V));
    if (new_Vs == NULL) {
        return;
    }

    for (i = 0; i < G->size; i++) {
        new_Vs[i] = G->Vs[i];
    }

    new_m = (bool**)malloc(ns * sizeof(bool*));
    if (new_m == NULL) {
        free(new_Vs);
        return;
    }

    for (i = 0; i < ns; i++) {
        new_m[i] = (bool*)calloc(ns, sizeof(bool));
        if (new_m[i] == NULL) {
            for (j = 0; j < i; j++) {
                free(new_m[j]);
            }
            free(new_m);
            free(new_Vs);
            return;
        }
    }

    old_m = graph_edges(G);
    for (i = 0; i < G->size; i++) {
        for (j = 0; j < G->size; j++) {
            new_m[i][j] = old_m[i][j];
        }
    }

    mdestroy_E(G);
    free(G->Vs);

    G->Vs = new_Vs;
    G->E = new_m;
    G->capacity = ns;
}

void mdestroy_E(G* G)
{
    uint i;
    bool** m;

    assert(G != NULL);
    if (G->E == NULL) {
        return;
    }

    m = graph_edges(G);
    for (i = 0; i < G->capacity; i++) {
        free(m[i]);
    }
    free(m);
    G->E = NULL;
}

void mdestroy_V(G* G)
{
    uint i;

    assert(G != NULL);
    if (G->Vs == NULL) {
        return;
    }

    if (G->free_data != NULL) {
        for (i = 0; i < G->size; i++) {
            if (G->Vs[i].data != NULL) {
                G->free_data(G->Vs[i].data);
            }
        }
    }

    free(G->Vs);
    G->Vs = NULL;
}

void mdestroy(G* G, uint size)
{
    (void)size;
    if (G == NULL) {
        return;
    }

    mdestroy_E(G);
    mdestroy_V(G);
    free(G);
}

/* List-backed graph implementation is intentionally left unimplemented for now. */
int ladd_v(G* G, void* data)
{
    (void)G;
    (void)data;
    return -1;
}

int ladd_edge(G* G, uint i, uint j)
{
    (void)G;
    (void)i;
    (void)j;
    return -1;
}

int lrm_edge(G* G, uint i, uint j)
{
    (void)G;
    (void)i;
    (void)j;
    return -1;
}

bool lhas_edge(G* G, uint i, uint j)
{
    (void)G;
    (void)i;
    (void)j;
    return false;
}

void lresize(G* G, uint ns)
{
    (void)G;
    (void)ns;
}

void ldestroy_E(G* G)
{
    (void)G;
}

void ldestroy_V(G* G)
{
    (void)G;
}

void ldestroy(G* G, uint size)
{
    (void)G;
    (void)size;
}

Operations mGraphOps = {
    .add_v = madd_v,
    .add_edge = madd_edge,
    .rm_edge = mrm_edge,
    .has_edge = mhas_edge,
    .resize = mresize,
    .destroy = mdestroy
};

Operations lGraphOps = {
    .add_v = ladd_v,
    .add_edge = ladd_edge,
    .rm_edge = lrm_edge,
    .has_edge = lhas_edge,
    .resize = lresize,
    .destroy = ldestroy
};

G* mgraph_create()
{
    uint i;
    G* g = (G*)malloc(sizeof(G));
    bool** E;

    if (g == NULL) {
        return NULL;
    }

    g->Vs = (V*)calloc(GRAPH_INIT_SIZE, sizeof(V));
    if (g->Vs == NULL) {
        free(g);
        return NULL;
    }

    E = (bool**)malloc(GRAPH_INIT_SIZE * sizeof(bool*));
    if (E == NULL) {
        free(g->Vs);
        free(g);
        return NULL;
    }

    for (i = 0; i < GRAPH_INIT_SIZE; i++) {
        E[i] = (bool*)calloc(GRAPH_INIT_SIZE, sizeof(bool));
        if (E[i] == NULL) {
            uint k;
            for (k = 0; k < i; k++) {
                free(E[k]);
            }
            free(E);
            free(g->Vs);
            free(g);
            return NULL;
        }
    }

    g->E = E;
    g->size = 0;
    g->capacity = GRAPH_INIT_SIZE;
    g->op = &mGraphOps;
    g->cmp = NULL;
    g->free_data = NULL;

    return g;
}

G* lgraph_create()
{
    return NULL;
}

G* graph_create(GraphImpl impl)
{
    switch (impl) {
        case ADJ_MAT:
            return mgraph_create();
        case ADJ_LST:
            return NULL;
        default:
            return NULL;
    }
}

int graph_add_v(G* G, void* data)
{
    return G->op->add_v(G, data);
}

int graph_add_edge(G* G, uint i, uint j)
{
    return G->op->add_edge(G, i, j);
}

int graph_rm_edge(G* G, uint i, uint j)
{
    return G->op->rm_edge(G, i, j);
}

bool graph_has_edge(G* G, uint i, uint j)
{
    return G->op->has_edge(G, i, j);
}

void graph_print(G* G)
{
    uint i;
    uint j;

    if (G == NULL) {
        return;
    }

    printf("Graph size: %u\n", G->size);
    printf("Adjacency matrix:\n");
    for (i = 0; i < G->size; i++) {
        for (j = 0; j < G->size; j++) {
            printf("%d", graph_edges(G)[i][j] ? 1 : 0);
            if (j + 1 < G->size) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void graph_print_with_data(G* G, void(*print_data)(const void* data))
{
    uint i;
    uint j;

    if (G == NULL) {
        return;
    }

    printf("Graph size: %u\n", G->size);
    printf("Vertices:\n");
    for (i = 0; i < G->size; i++) {
        printf("v%u -> ", i);
        if (G->Vs[i].data != NULL && print_data != NULL) {
            print_data(G->Vs[i].data);
        } else {
            printf("(null)");
        }
        printf("\n");
    }

    printf("Adjacency matrix:\n");
    for (i = 0; i < G->size; i++) {
        for (j = 0; j < G->size; j++) {
            printf("%d", graph_edges(G)[i][j] ? 1 : 0);
            if (j + 1 < G->size) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void graph_destroy(G* G, uint size)
{
    if (G == NULL) {
        return;
    }
    G->op->destroy(G, size);
}


