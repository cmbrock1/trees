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
#include <stdio.h>
#include "node.h"
#include "queue.h"
#include "Fatal.h"
#include "tree.h"

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
    node *dupNode = newNode();
    dupNode->left = NULL;
    dupNode->right = NULL;
    return dupNode;
}
node *Search(tree *t,char *key){
    node *temp = t->root;
    while((temp != NULL) && (strcmp(temp->key,key) != 0))
    {
        if(strcmp(key,temp->key) < 0)
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
    newNode->freq = 1;
    while(temp != NULL)
    {
        back = temp;
        if(strcmp(newNode->key,temp->key) == 0){
            temp->freq++;
            return false;
        }
        if(strcmp(newNode->key,temp->key) < 0)
            temp = temp->left;
        else
            temp = temp->right;
    }
    // Now attach the new node to the node that back points to
    if(back == NULL){
        t->root = newNode;
        newNode->parent = NULL;
    }
    else
    {
        if(strcmp(newNode->key,back->key) < 0){
            back->left = newNode;
            newNode->parent = back;
        }
        else {
            back->right = newNode;
            newNode->parent = back;
        }
    }
   return true;
}
void moveToLeaf(node *x,node *child){
    node *temp = x->left;
    while(temp != NULL){
        temp = temp->right;
    }
    temp->key = x->key;
}
void prune(tree *t,node *n){
    if(t->root == n){
        t->root = NULL;
    }
    else{
        if(n->parent->left == n)
            n->parent->left = NULL;
        else
            n->parent->right = NULL;
    }
}
void swap(node *n,node *succ){
	char *tempKey = n->key;
	int tempFreq = n->freq;
	n->key = succ->key;
	succ->key = tempKey;
	n->freq = succ->freq;
	succ->freq = tempFreq;
}
node *swapToLeaf(tree *t,node *n){
    if(n->left == NULL && n->right == NULL)
        return n;
    else if(n->right != NULL){
        node *succ = n->right;
        if (succ->left == NULL){
            swap(n,succ);
            return swapToLeaf(t,succ);
        }
        while ( succ->left != NULL )
            succ = succ->left;
        swap(n,succ);
        return swapToLeaf(t,succ);
    }
    else {
        node *succ = n->left;
        if (succ->right == NULL){
            swap(n,succ);
            return swapToLeaf(t,succ);
        }
        while ( succ->right != NULL )
            succ = succ->right;
        swap(n,succ);
        return swapToLeaf(t,succ);
    }
}
node *findNode(tree *t,char *key){
    node *temp = t->root;
    while((temp != NULL) && (strcmp(temp->key,key) != 0))
    {
        if(strcmp(key,temp->key) < 0)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(temp == NULL)
        return NULL;
    else if(temp->freq > 1){
        temp->freq--;
        return NULL;
    }
    else
        return temp;
}

int getLevelUtil(node *node, char* key, int level){
    if (node == NULL)
        return -1;

    if (strcmp(node->key,key) == 0)
        return level;

    int downlevel = getLevelUtil(node->left, key, level+1);
    if (downlevel != -1)
        return downlevel;

    downlevel = getLevelUtil(node->right, key, level+1);
    return downlevel;
}
int getLevel(node *n,char *data){
    return getLevelUtil(n,data,0);
}
static void printAll(node *root,node *n){
    if(n != NULL){
        //int level = getLevel(root,n->key);
        displayNode(n,stdout);
        printAll(root,n->left);
        printAll(root,n->right);
    }
}
void displayTree(tree *t){
    printAll(t->root,t->root);
}
void printLevelOrder(tree *t,FILE *fp)
{
    if (t->root == NULL)  return;
    queue *q = newQueue();
    node *temp = t->root;
    Enqueue(q,temp);
    int level = 0;
    while(!EmptyQueue(q)){
        int levelNodes = queueSize(q);
        fprintf(fp,"%d:",level);
        level++;
	    while(levelNodes > 0){
		    node *n = Dequeue(q);
		    displayNode(n,fp);
		    if(n->left != NULL) Enqueue(q,n->left);
		    if(n->right != NULL) Enqueue(q,n->right);
		    levelNodes--;
	   }
       fprintf(fp,"\n");
    }


    //     displayNode(temp,stdout);
    //
    //     /*Enqueue left child */
    //     if (temp->left)
    //         Enqueue(q,temp->left);
    //
    //     /*Enqueue right child */
    //     if (temp->right)
    //         Enqueue(q,temp->right);
    //
    //     /*Dequeue node and make it temp*/
    //     temp = Dequeue(q);
    // }
}
