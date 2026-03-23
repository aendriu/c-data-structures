CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -Iinclude

TARGET=test_list
GRAPH_TARGET=test_graph
GRAPH_ALGS_TARGET=test_graph_algs
TEST_SRC=tests/test_list.c
GRAPH_TEST_SRC=tests/test_graph.c
GRAPH_ALGS_TEST_SRC=tests/test_graph_algs.c
LIST_SRC=src/list.c
GRAPH_SRC=src/graph.c
GRAPH_ALGS_SRC=src/graph_algs.c
SRC=$(LIST_SRC) $(GRAPH_SRC) $(GRAPH_ALGS_SRC)
GRAPH_OBJ=graph.o
GRAPH_ALGS_OBJ=graph_algs.o
HAS_GRAPH_ALGS_TEST=$(shell [ -s $(GRAPH_ALGS_TEST_SRC) ] && echo 1)

.PHONY: all clean

all: $(TARGET) $(GRAPH_TARGET) $(GRAPH_OBJ) $(GRAPH_ALGS_OBJ) $(if $(HAS_GRAPH_ALGS_TEST),$(GRAPH_ALGS_TARGET))

$(TARGET): $(TEST_SRC) $(SRC) include/list.h
	$(CC) $(CFLAGS) $(TEST_SRC) $(SRC) -o $@

$(GRAPH_TARGET): $(GRAPH_TEST_SRC) $(GRAPH_SRC) $(LIST_SRC) include/graph.h include/list.h
	$(CC) $(CFLAGS) $(GRAPH_TEST_SRC) $(GRAPH_SRC) $(LIST_SRC) -o $@

$(GRAPH_ALGS_TARGET): $(GRAPH_ALGS_TEST_SRC) $(GRAPH_ALGS_SRC) $(GRAPH_SRC) $(LIST_SRC) include/graph_algs.h include/graph.h include/list.h
	$(CC) $(CFLAGS) $(GRAPH_ALGS_TEST_SRC) $(GRAPH_ALGS_SRC) $(GRAPH_SRC) $(LIST_SRC) -o $@

$(GRAPH_OBJ): $(GRAPH_SRC)
	$(CC) $(CFLAGS) -c $(GRAPH_SRC) -o $@

$(GRAPH_ALGS_OBJ): $(GRAPH_ALGS_SRC)
	$(CC) $(CFLAGS) -c $(GRAPH_ALGS_SRC) -o $@

clean:
	rm -f $(TARGET) $(GRAPH_TARGET) $(GRAPH_ALGS_TARGET) $(GRAPH_OBJ) $(GRAPH_ALGS_OBJ)

