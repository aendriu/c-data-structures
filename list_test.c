#include <stdio.h>
#include <time.h>
#include "list.h"
#include "list_test.h"

#define TEST_SIZE 100

void int_print_list(void *d)
{
    printf("%d -> ", *(int*)d);
}
void char_print_list(void *d)
{
    printf("%c -> ", *(char*)d);
}
void string_print_list(void *d)
{
    printf("%s -> ", (char*)d);
}

void free_int(void* d){free(d);}
void free_char(void* d){free(d);}
void free_string(void* d){free(d);}


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

    remove_specific(list, v3, free_int); printf("\n");

    print_list(list, int_print_list); printf("\n");
    
    remove_first(list, free_int);
    remove_last(list, free_int);

    print_list(list, int_print_list); printf("\n");
    
    remove_first(list, free_int);
    print_list(list, int_print_list); printf("\n");
    remove_first(list, free_int);
    print_list(list, int_print_list); printf("\n");
    remove_first(list, free_int);
    print_list(list, int_print_list); printf("\n");
    remove_first(list, free_int);
    print_list(list, int_print_list); printf("\n");
    remove_first(list, free_int);
    remove_last(list, free_int);
    remove_last(list, free_int);
    remove_last(list, free_int);
    remove_last(list, free_int);
    remove_last(list, free_int);
    
    char* c1=(char*)malloc(sizeof(char));
    char* c2=(char*)malloc(sizeof(char));
    char* c3=(char*)malloc(sizeof(char));
    char* c4=(char*)malloc(sizeof(char));
    char* c5=(char*)malloc(sizeof(char));

    *c1='a';
    *c2='b';
    *c3='c';
    *c4='d';
    *c5='e';

    add_last(list, c1);
    add_last(list, c2);
    add_last(list, c3);
    add_last(list, c4);
    add_last(list, c5);

    print_list(list, char_print_list); printf("\n");
    
    for(int i=0; i<TEST_SIZE; i++) {
        char* c=(char*)malloc(sizeof(char));
        *c='a'+(rand()%26);
        add_last(list, c);
    }
    print_list(list, char_print_list); printf("\n");

    empty_list(list, free_char); printf("\n");

    for(int i=0; i<TEST_SIZE; i++) {
        int* n=(int*)malloc(sizeof(int));
        *n='a'+(rand()%100);
        add_last(list, n);
    }

    empty_list(list, free_int); printf("\n");

    for(int i=0; i<TEST_SIZE; i++) {
        char* s=(char*)malloc(20*sizeof(char));
        sprintf(s, "String%d", i);
        add_last(list, s);
    }

    print_list(list, string_print_list); printf("\n");

    free_list(list, free_string);
    return 0;
}



