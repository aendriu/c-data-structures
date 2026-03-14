CC=gcc
CFLAGS=-Wall -Wextra -std=c11

.PHONY: all clean

all: list

list: list.o
	$(CC) $(CFLAGS) -o $@ $^

list.o: list.c list.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o list

