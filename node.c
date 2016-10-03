/*******************************************************************
*   node.c
*   Cameron Brock
*   Programming Assignment 1 calculon
*
*   This program is entirely my own work
*******************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "Fatal.h"
void initNode(node *n){
    n->next = NULL;
    n->left = NULL;
    n->right = NULL;
    n->key = NULL;
    n->val = NULL;
}
node *newNode(value *v){
    node *n;
    if ((n = malloc(sizeof(node))) == 0)
        Fatal("out of memory\n");
    initNode(n);
    n->val = v;
    return n;
}
node *newTreeNode(value *v,char *key){
    node *n;
    if ((n = malloc(sizeof(node))) == 0)
        Fatal("out of memory\n");
    initNode(n);
    n->val = v;
    n->key = key;
    return n;
}
void displayNode(node *n,FILE *fp){
    displayValue(fp,n->val);
}
