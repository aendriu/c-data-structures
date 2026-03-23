#include "../include/graph.h"
#include <stdio.h>

static void print_string_data(const void* data)
{
    const char* s = (const char*)data;
    printf("%s", s);
}

int main() 
{
    G* g = graph_create(ADJ_MAT);
    graph_add_v(g, "Ciao!");
    graph_add_v(g, "Incredibile!");
    graph_add_v(g, "Ok magari questo puo essere utile");
    graph_print(g);

    graph_add_v(g, NULL);
    graph_add_v(g, NULL);
    graph_add_v(g, NULL);
    graph_print(g);

    graph_add_v(g, NULL);
    graph_add_v(g, NULL);
    graph_add_v(g, NULL);
    graph_print(g);

    graph_add_v(g, NULL);
    graph_add_v(g, NULL);
    graph_add_v(g, NULL);
    graph_print(g);

    graph_add_v(g, NULL);
    graph_add_v(g, "Tentativo 1");
    graph_add_v(g, NULL);
    graph_print(g);
    
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 1, 2);
    graph_print_with_data(g, print_string_data);
    graph_destroy(g, g->size);
    return 0;
}
