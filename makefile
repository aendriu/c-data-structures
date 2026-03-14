CC=gcc
CFLAGS=-Wall -Wextra -std=c11

.PHONY: all clean

all: list_test

list_test: list_test.o list.o
	$(CC) $(CFLAGS) -o $@ $^

list_test.o: list_test.c list_test.h list.h
	$(CC) $(CFLAGS) -c $< -o $@

list.o: list.c list.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o list_test

