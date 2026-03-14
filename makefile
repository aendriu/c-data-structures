CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -Iinclude

TARGET=test_list
TEST_SRC=tests/test_list.c
SRC=src/list.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TEST_SRC) $(SRC) include/list.h
	$(CC) $(CFLAGS) $(TEST_SRC) $(SRC) -o $@

clean:
	rm -f $(TARGET)

