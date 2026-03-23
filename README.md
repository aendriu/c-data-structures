# c-data-structures

Project layout:

- `include/`: public headers
- `src/`: source code
- `tests/`: test files

## Build

```sh
make
```

## Run test

```sh
./test_list
./test_graph
```

## Clean

```sh
make clean
```

## API

### List (`include/list.h`)

- `Node* alloc_node(void* data)`
- `List* alloc_list(void)`
- `void* get_first(List* list)`
- `void* get_last(List* list)`
- `void* get_nth(List* list, int n)`
- `void add_first(List* list, void* data)`
- `void add_last(List* list, void* data)`
- `void remove_specific(List* list, void* data, void(*free_func)(void*), int(*cmp_func)(void*, void*))`
- `void remove_first(List* list, void(*free_func)(void*))`
- `void remove_last(List* list, void(*free_func)(void*))`
- `void empty_list(List* list, void(*free_func)(void*))`
- `void print_list(List* list, void(*print_func)(void*))`
- `void free_list(List* list, void(*free_func)(void*))`

### Graph (`include/graph.h`)

Creation and dispatch:

- `G* mgraph_create(void)`
- `G* lgraph_create(void)`
- `G* graph_create(GraphImpl impl)`

Generic graph API:

- `int graph_add_v(G* G, void* data)`
- `int graph_add_edge(G* G, uint i, uint j)`
- `int graph_rm_edge(G* G, uint i, uint j)`
- `bool graph_has_edge(G* G, uint i, uint j)`
- `void graph_print(G* G)`
- `void graph_destroy(G* G, uint size)`

Matrix implementation (`ADJ_MAT`):

- `int madd_v(G* G, void* data)`
- `int madd_edge(G* G, uint i, uint j)`
- `int mrm_edge(G* G, uint i, uint j)`
- `bool mhas_edge(G* G, uint i, uint j)`
- `void mresize(G* G, uint ns)`
- `void mdestroy_E(G* G)`
- `void mdestroy_V(G* G)`
- `void mdestroy(G* G, uint size)`

List implementation (`ADJ_LST`):

- `int ladd_v(G* G, void* data)`
- `int ladd_edge(G* G, uint i, uint j)`
- `int lrm_edge(G* G, uint i, uint j)`
- `bool lhas_edge(G* G, uint i, uint j)`
- `void lresize(G* G, uint ns)`
- `void ldestroy_E(G* G)`
- `void ldestroy_V(G* G)`
- `void ldestroy(G* G, uint size)`

Note: `ADJ_LST` functions are currently placeholders and not implemented yet.
