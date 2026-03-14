#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    void* data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct List {
    struct Node* first;
    struct Node* last;
} List;

Node* alloc_node(void*);
List* alloc_list();

void* get_first(List*);
void* get_last(List*);

void add_first(List*, void*);
void add_last(List*, void*);

void remove_specific(List*, void*, void(*free_func)(void*), int(*cmp_func)(void*,void*));
void remove_first(List*, void(*free_func)(void*));
void remove_last(List*, void(*free_func)(void*));

void empty_list(List*, void(*free_func)(void*));
void print_list(List*, void(*print_func)(void*));
void free_list(List*, void(*free_func)(void*));

#endif /* LIST_H */

