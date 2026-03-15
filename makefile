CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -Iinclude

TARGET=test_list
GRAPH_TARGET=test_graph
TEST_SRC=tests/test_list.c
GRAPH_TEST_SRC=tests/test_graph.c
LIST_SRC=src/list.c
GRAPH_SRC=src/graph.c
SRC=$(LIST_SRC) $(GRAPH_SRC)
GRAPH_OBJ=graph.o

.PHONY: all clean

all: $(TARGET) $(GRAPH_TARGET) $(GRAPH_OBJ)

$(TARGET): $(TEST_SRC) $(SRC) include/list.h
	$(CC) $(CFLAGS) $(TEST_SRC) $(SRC) -o $@

$(GRAPH_TARGET): $(GRAPH_TEST_SRC) $(GRAPH_SRC) $(LIST_SRC) include/graph.h include/list.h
	$(CC) $(CFLAGS) $(GRAPH_TEST_SRC) $(GRAPH_SRC) $(LIST_SRC) -o $@

$(GRAPH_OBJ): $(GRAPH_SRC)
	$(CC) $(CFLAGS) -c $(GRAPH_SRC) -o $@

clean:
	rm -f $(TARGET) $(GRAPH_TARGET) $(GRAPH_OBJ)

