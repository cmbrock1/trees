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
    struct node *parent;
    int freq;
    int height;
    int lheight;
    int rheight;
    char *key;
}node;

extern node *newNode(void);
extern node *newTreeNode(char *key);
extern void displayNode(node *n,FILE *fp);

#endif // NODE_H
