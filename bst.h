/*******************************************************************
*   bst.h
*   Cameron Brock
*   Programming Assignment 2 trees
*
*   This program is entirely my own work
*******************************************************************/
#ifndef BST_H
#define BST_H
#include <stdbool.h>
#include "tree.h"
extern bool bstDelete(tree *t,char *key);
extern bool bstInsert(tree *t,node *n);
#endif // BST_H
