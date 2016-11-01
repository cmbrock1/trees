#   Makefile
#   Cameron Brock
#   Programming Assignment 1 calculon
#
#   This program is entirely my own work
CC=gcc
CFLAGS=-Wall -g -std=c99 -c
OBJECTS= trees.o scanner.o queue.o node.o Fatal.o tree.o avl.o bst.o
TESTOBJECTS=testing.o scanner.o queue.o node.o Fatal.o tree.o avl.o
BINARYS=testing trees

all: testing trees

trees: ${OBJECTS}
	${CC} -Wall -std=c99 -g -o trees ${OBJECTS}

trees.o: trees.c scanner.h tree.h Fatal.h avl.h bst.h
	${CC} ${CFLAGS} trees.c

testing: ${TESTOBJECTS}
	${CC} -Wall -std=c99 -g -o testing ${TESTOBJECTS}

testing.o: testing.c node.o avl.o tree.o
	${CC} ${CFLAGS} testing.c

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
	rm testing.o ${OBJECTS} ${BINARYS}
