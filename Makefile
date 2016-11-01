#   Makefile
#   Cameron Brock
#   Programming Assignment 2 trees
#
#   This program is entirely my own work
CC=gcc
CFLAGS=-Wall -g -std=c99 -c
OBJECTS=trees.o scanner.o queue.o node.o Fatal.o tree.o avl.o bst.o
BINARYS=trees

all: trees

trees: ${OBJECTS}
	${CC} -Wall -std=c99 -g -o trees ${OBJECTS}

test: trees
	@echo testing BST
	@echo cat data
	@echo
	cat commands
	@echo
	timeout 2s trees -b data commands
	@echo
	@echo testing AVL
	@echo
	timeout 2s trees -a data commands

trees.o: trees.c scanner.h tree.h Fatal.h avl.h bst.h
	${CC} ${CFLAGS} trees.c

node.o: node.c node.h Fatal.h
	${CC} ${CFLAGS} node.c

Fatal.o: Fatal.c Fatal.h
	${CC} ${CFLAGS} Fatal.c

queue.o: queue.c queue.h node.o Fatal.h
	${CC} ${CFLAGS} queue.c

tree.o: tree.c tree.h node.h Fatal.h
	${CC} ${CFLAGS} tree.c

avl.o: avl.c avl.h tree.h node.h
	${CC} ${CFLAGS} avl.c

bst.o: bst.c bst.h tree.h node.h
	${CC} ${CFLAGS} bst.c

scanner.o: scanner.c scanner.h
	${CC} ${CFLAGS} scanner.c

clean:
	rm -r ${OBJECTS} ${BINARYS} trees.dSYM
