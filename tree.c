/*******************************************************************
*   tree.c
*   Cameron Brock
*   Programming Assignment 1 calculon
*
*   This program is entirely my own work
*******************************************************************/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "node.h"
#include "Fatal.h"

static void initTree(tree *t){
    if(t != NULL){
        t->root = NULL;
    }
}
tree *newTree(){
    tree *t;
    if ((t = malloc(sizeof(tree))) == 0)
        Fatal("out of memory\n");
    initTree(t);
    return t;
}
bool EmptyTree(tree *t){
    if(t->root == NULL)
        return true;
    else
        return false;
}
static node *DupNode(node *n){
    node *dupNode = newNode(n->val);
    dupNode->val = n->val;
    dupNode->left = NULL;
    dupNode->right = NULL;
    return dupNode;
}
node *Search(tree *t,char *key){
    node *temp = t->root;
    while((temp != NULL) && (strcmp(temp->key,key) != 0))
    {
        if(key < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(temp == NULL)
        return NULL;
    else
        return(DupNode(temp));
}
bool Insert(tree *t,node *newNode){
    node *temp = t->root;
    node *back = NULL;
    while(temp != NULL)
    {
        back = temp;
        if(newNode->key < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    // Now attach the new node to the node that back points to
    if(back == NULL)
        t->root = newNode;
    else
    {
        if(newNode->key < back->key)
            back->left = newNode;
        else
            back->right = newNode;
    }
   return true;
}
bool Delete(tree *t,char *key){
    node *delParent;
    node *delNode;
    node *temp = t->root;
    node *back = NULL;
    while((temp != NULL) && (strcmp(key,temp->key) != 0)){
        back = temp;
        if(key < temp->key)
            temp = temp->left;
            else
            temp = temp->right;
        }
        if(temp == NULL){
            printf("Key not found. Nothing deleted.\n");
            return false;
        }
        else {
            if(temp == t->root){ // Deleting the root
                delNode = t->root;
                delParent = NULL;
            }
            else {
                delNode = temp;
                delParent = back;
            }
        }
        // Case 1: Deleting node with no children or one child
        if(delNode->right == NULL){
            if(delParent == NULL){
                t->root = delNode->left;
                free(delNode);
                return true;
            }
            else {
                if(delParent->left == delNode)
                    delParent->left = delNode->left;
                else
                    delParent->right = delNode->left;
                free(delNode);
                return true;
            }
        }
        else { // There is at least one child
            if(delNode->left == NULL){
                if(delParent == NULL){
                    t->root = delNode->right;
                    free(delNode);
                    return true;
                }
                else {
                    if(delParent->left == delNode)
                        delParent->left = delNode->right;
                    else
                        delParent->right = delNode->right;
                    free(delNode);
                    return true;
                }
            }
            else { // Case 2: Deleting node with two children
                temp = delNode->left;
                back = delNode;
                while(temp->right != NULL){
                        back = temp;
                        temp = temp->right;
                    }
                delNode->key = temp->key;
                delNode->val = temp->val;
                if(back == delNode)
                    back->left = temp->left;
                    else
                        back->right = temp->left;
                    free(temp);
                    return true;
                }
            }
        }
static void printAll(node *n){
    if(n != NULL){
        printAll(n->left);
        displayNode(n,stdout);
        printf("\n");
        printAll(n->right);
    }
}
void displayTree(tree *t){
    printAll(t->root);
}
