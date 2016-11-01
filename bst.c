/*******************************************************************
*   bst.c
*   Cameron Brock
*   Programming Assignment 2 trees
*
*   This program is entirely my own work
*******************************************************************/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "tree.h"
#include "node.h"
#include "Fatal.h"

bool bstDelete(tree *t,char *key){
    if(t->root == NULL)
        Fatal("Delete from Empty Tree\n");
    node *w = findNode(t,key);
    if(w != NULL){
        node *z = swapToLeaf(t,w);
        prune(t,z);
        return true;
    }
    else
        return false;
}
bool bstInsert(tree *t,node *n){
    return Insert(t,n);
}
