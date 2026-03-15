#include "../include/graph.h"
#include <stdio.h>

void m_print_adj(mGraph* mg)
{
    if(mg == NULL) { return; }
    for(int i=0; i<mg->n_el; i++) {
        for(int j=0; j<mg->n_el; j++) {
            printf("%d ", mg->adj[i][j]);
        }
        printf("\n");
    }
}


int main() {
    mGraph* mg = create_mGraph(10);
    madd_adj(mg, 0, 1);
    madd_adj(mg, 0, 2);
    madd_adj(mg, 0, 3); 
    m_print_adj(mg); printf("\n"); 
    mremove_adj(mg, 0, 2);
    m_print_adj(mg); printf("\n"); 
    destroy_mGraph(mg, free);
    return 0;
}
