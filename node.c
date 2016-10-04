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
}
node *newNode(void){
    node *n;
    if ((n = malloc(sizeof(node))) == 0)
        Fatal("out of memory\n");
    initNode(n);
    return n;
}
node *newTreeNode(char *key){
    node *n;
    if ((n = malloc(sizeof(node))) == 0)
        Fatal("out of memory\n");
    initNode(n);
    n->key = key;
    return n;
}
void displayNode(node *n,FILE *fp){
    fprintf(fp,"key = %s",n->key);
}
