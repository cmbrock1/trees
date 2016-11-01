/*******************************************************************
*   tree.h
*   Cameron Brock
*   Programming Assignment 2 trees
*
*   This program is entirely my own work
*******************************************************************/
#ifndef TREE_H
#define TREE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
typedef struct tree{
    node *root;
}tree;

extern tree *newTree();
extern bool EmptyTree(tree *t);
extern node *Search(tree *t,char *key);
extern bool Insert(tree *t,node *newNode);
extern void displayTree(tree *t);
extern void printLevelOrder(tree *t,FILE *fp);
extern node *findNode(tree *t,char *key);
extern node *swapToLeaf(tree *t,node *n);
extern void prune(tree *t,node *n);
extern int getFreq(tree *t,char *key);
extern int getNumberOfNodes(node *root);
extern int getMinDepth(node *root);
extern int getMaxDepth(node *root);
#endif // TREE_H
