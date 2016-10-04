CC=gcc
CFLAGS=-Wall -g -std=c99 -c
TESTOBJECTS=testing.o tree.o node.o Fatal.o
all: testing

testing: ${TESTOBJECTS}
	${CC} -Wall -std=c99 -g -o testing ${TESTOBJECTS}

testing.o: testing.c tree.h node.h
	${CC} ${CFLAGS} testing.c

tree.o: tree.c tree.h node.h Fatal.h
	${CC} ${CFLAGS} tree.c

node.o: node.c node.h Fatal.h
	${CC} ${CFLAGS} node.c

Fatal.o: Fatal.h
	${CC} ${CFLAGS} Fatal.c

clean:
	rm ${TESTOBJECTS}
	rm -r testing.dSYM
