/*******************************************************************
*   node.c
*   Cameron Brock
*   Programming Assignment 1 calculon
*
*   This program is entirely my own work
*******************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "node.h"
#include "Fatal.h"
#include "avl.h"
void initNode(node *n){
    n->next = NULL;
    n->left = NULL;
    n->right = NULL;
    n->key = NULL;
    n->freq = 0;
    n->height = 0;
    n->lheight = 0;
    n->rheight = 0;
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
bool isLeaf(node *n){
    if(n->left == NULL && n->right == NULL)
        return true;
    else
        return false;
}
bool isRoot(node *n){
    if(n->parent == NULL)
        return true;
    else
        return false;
}
bool isLeftChild(node *n){
    if(n->parent->left == n)
        return true;
    else
        return false;
}
void displayNode(node *n,FILE *fp){
    fprintf(fp," ");
    if(isLeaf(n))
        fprintf(fp,"=");
    if(n->left != NULL && favorite(n) == n->left)
        fprintf(fp,"%s-",n->key);
    else if(n->right != NULL && favorite(n) == n->right)
        fprintf(fp,"%s+",n->key);
    else
        fprintf(fp,"%s",n->key);
    if(isRoot(n)){
        if(n->left != NULL && favorite(n) == n->left)
            fprintf(fp,"(%s-)",n->key);
        else if(n->right != NULL && favorite(n) == n->right)
            fprintf(fp,"(%s+)",n->key);
        else
            fprintf(fp,"(%s)",n->key);
    }
    else {
        if(n->parent->left != NULL && favorite(n->parent) == n->parent->left)
            fprintf(fp,"(%s-)",n->parent->key);
        else if(n->parent->right != NULL && favorite(n->parent) == n->parent->right)
            fprintf(fp,"(%s+)",n->parent->key);
        else
            fprintf(fp,"(%s)",n->parent->key);
    }
    fprintf(fp,"%d",n->freq);
    if(isRoot(n))
        fprintf(fp,"X");
    else if(isLeftChild(n))
        fprintf(fp,"L");
    else
        fprintf(fp,"R");
}
