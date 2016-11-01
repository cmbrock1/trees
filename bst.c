/*******************************************************************
*   bst.c
*   Cameron Brock
*   Programming Assignment 1 calculon
*
*   This program is entirely my own work
*******************************************************************/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "tree.h"
#include "node.h"

bool bstDelete(tree *t,char *key){
    node *w = findNode(t,key);
    if(w != NULL){
        node *z = swapToLeaf(t,w);
        prune(t,z);
    }
    return true;
}
bool bstInsert(tree *t,node *n){
    return Insert(t,n);
}
