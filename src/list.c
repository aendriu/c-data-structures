#include "../include/list.h"
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
void* get_nth(List*l, int n) {
    assert(l!=NULL);
    Node* s = l->first;
    while(s!=NULL && n-- > 0) {
        s=s->next;
    }
    if(s==NULL) {
        return NULL;
    }
    else {
        return s->data;
    }
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

void remove_specific(List* l, void* d, void(*free_func)(void*), int(*cmp_func)(void*,void*)) 
{
    assert(l!=NULL);
    if(l->first==NULL) { return; }
    Node* s=l->first;
    while(s!=NULL && cmp_func(s->data,d) != 0) { s=s->next;}
    if(s==NULL) { 
        return; 
    }
    else if(s == l->first) {
        l->first = s->next;
        if(l->first != NULL) { l->first->prev = NULL; } 
        else { l->last = NULL; }
    } 
    else if(s == l->last) {
        l->last = s->prev;
        l->last->next = NULL;
    } 
    else {
        s->prev->next = s->next;
        s->next->prev = s->prev;
    }
    
    free_func(s->data);
    free(s);
}

void remove_first(List* l, void(*free_func)(void*))
{
    assert(l!=NULL);
    if(l->first==NULL) { return; }
    Node* tmp = l->first;
    if(l->first == l->last) {
        l->last = NULL;
        l->first = NULL;
        free_func(tmp->data);
        free(tmp);
        return;
    }
    l->first->next->prev = NULL;
    l->first = l->first->next;
    free_func(tmp->data);
    free(tmp);
}
void remove_last(List* l, void(*free_func)(void*))
{
    assert(l!=NULL);
    if(l->first==NULL) { return; }
    Node* tmp = l->last;
    if(l->first == l->last) {
        l->last = NULL;
        l->first = NULL;
        free_func(tmp->data);
        free(tmp);
        return;
    }
    l->last->prev->next = NULL;
    l->last = l->last->prev;
    free_func(tmp->data);
    free(tmp);
}

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
}

void free_list(List* l, void(*free_func)(void*)) 
{
    empty_list(l, free_func);
    free(l);
}


