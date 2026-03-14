#include "list.h"
#define TEST_SIZE 20

Node* alloc_node(void* d)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->next=NULL;
    node->prev=NULL;
    node->data=d;
    return node;
}

List* alloc_list() 
{   
    List* list = (List*)malloc(sizeof(List));
    list->first=NULL;
    list->last=NULL;
    return list;
}

void* get_first(List* l)
{
    return l->first->data;
}

void* get_last(List* l)
{
    return l->last->data;
}

void add_first(List* l, void* d)
{
    assert(l!=NULL);
    Node* n = alloc_node(d);
    if(l->first == NULL) {
        l->first = n;
        l->last = n;
    } else {
        n->next = l->first;
        l->first->prev = n;
        l->first = n;
    }
}
void add_last(List* l, void* d)
{
    assert(l!=NULL);
    Node* n=alloc_node(d);
    if(l->first==NULL) {
        l->first = n;
        l->last = n;
    } else {
        l->last->next = n;
        n->prev = l->last;
        l->last = n;
    }
}

void remove_specific(List*, void*);
void remove_first(List*);
void remove_last(List*);

void empty_list(List* list, void(*free_func)(void*))
{
    while(list->first!=NULL) {
        Node* tmp;
        tmp = list->first;
        list->first = list->first->next;
        free_func(tmp->data);
        free(tmp);
    }
    list->last=NULL;
}

void print_list(List* l, void(*print_func)(void*))
{
    Node* s;
    for(s=l->first; s!=NULL; s=s->next) {
        print_func(s->data);
    }
    printf("NULL");
}
void int_print_list(void *d)
{
    printf("%d -> ", *(int*)d);
}
void char_print_list(void *d)
{
    printf("%c -> ", *(char*)d);
}

void free_list(List*);
void free_int(void* d){free(d);}
void free_char(void* d){free(d);}

int main() 
{
    srand(time(NULL));
    List* list = alloc_list();
    
    /*
    for(int i = TEST_SIZE; i>0; i--) {
        int* val = (int*)malloc(sizeof(int));
        *val=rand()%100;
        add_first(list, val); 
    }
    */
    int *v1=(int*)malloc(sizeof(int));
    int *v2=(int*)malloc(sizeof(int));
    int *v3=(int*)malloc(sizeof(int));
    int *v4=(int*)malloc(sizeof(int));
    int *v5=(int*)malloc(sizeof(int));

    *v1=1;
    *v2=2;
    *v3=3;
    *v4=4;
    *v5=5;

    add_first(list, v1);
    add_first(list, v2);
    add_first(list, v3);
    add_first(list, v4);
    add_first(list, v5);
    
    print_list(list, int_print_list); printf("\n");
    int f=*((int*)get_first(list));
    int l=*((int*)get_last(list));
    printf("First: %d, Last: %d\n", f, l);

    empty_list(list, free_int); printf("\n");

    print_list(list, int_print_list); printf("\n");

    v1=(int*)malloc(sizeof(int));
    v2=(int*)malloc(sizeof(int));
    v3=(int*)malloc(sizeof(int));
    v4=(int*)malloc(sizeof(int));
    v5=(int*)malloc(sizeof(int));

    *v1=1;
    *v2=2;
    *v3=3;
    *v4=4;
    *v5=5;

    add_last(list, v1);
    add_last(list, v2);
    add_last(list, v3);
    add_last(list, v4);
    add_last(list, v5);

    print_list(list, int_print_list);

    return 0;
}

