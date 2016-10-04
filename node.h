/*******************************************************************
*   node.h
*   Cameron Brock
*   Programming Assignment 1 calculon
*
*   This program is entirely my own work
*******************************************************************/
#ifndef NODE_H
#define NODE_H
#include <stdio.h>
typedef struct node{
    struct node *next;
    struct node *left;
    struct node *right;
    char *key;
}node;

extern node *newNode(void);
extern void displayNode(node *n,FILE *fp);

#endif // NODE_H
