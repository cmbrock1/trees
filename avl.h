/*******************************************************************
*   avlTree.h
*   Cameron Brock
*   Programming Assignment 1 calculon
*
*   This program is entirely my own work
*******************************************************************/
#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <stdbool.h>
#include "tree.h"
#include "node.h"

extern bool AVL;
extern bool avlDelete(tree *t,char *key);
extern bool avlInsert(tree *t,node *n);
extern node *favorite(node *n);
#endif // AVL_TREE_H
