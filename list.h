#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <error.h>
#include <time.h>

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

void remove_specific(List*, void*);
void remove_first(List*);
void remove_last(List*);

void empty_list(List*, void(*free_func)(void*));

void print_list(List*, void(*print_func)(void*));
void int_print_list(void *d);
void char_print_list(void *d);

void free_int(void* d);
void free_char(void* d);

void free_list(List*);

#endif /* LIST_H */

