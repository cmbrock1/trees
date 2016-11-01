/*******************************************************************
*   avlTree.c
*   Cameron Brock
*   Programming Assignment 1 calculon
*
*   This program is entirely my own work
*******************************************************************/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "avl.h"
#include "node.h"

bool AVL;
void setBalance(node *n){
    if(n->left != NULL)
        n->lheight = n->left->height;
    else
        n->lheight = 0;
    if(n->right != NULL)
        n->rheight = n->right->height;
    else
        n->rheight = 0;
    if(n->lheight > n->rheight)
        n->height = n->lheight+1;
    else
        n->height = n->rheight+1;
}
int getBalFact(node *n){
	if(n != NULL)
		return n->lheight - n->rheight;
	else return 0;
}
node *sibling(node *n){
	if(n != NULL && n->parent != NULL){
		if(n == n->parent->left)
			return n->parent->right;
		else
			return n->parent->left;
	}
	else
		return NULL;
}
node *favorite(node *n){
    if(getBalFact(n) == 1)
        return n->left;
    else if(getBalFact(n) == -1)
        return n->right;
    else
        return NULL;
}
bool linear(node *c,node *p,node *gp){
    return (gp->left == p && p->left == c)
            || (gp->right == p && p->right == c);
}
void leftRotate(tree *t,node *x){
    node *y = x->right;
    x->right = y->left;
    if(y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == NULL)
        t->root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}
void rightRotate(tree *t,node *x){
    node *y = x->left;
    x->left = y->right;
    if(y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if(x->parent == NULL)
        t->root = y;
    else if(x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}
void rotate(tree *t,node *y,node *x){
    if(y == x->right)
        leftRotate(t,x);
    else
        rightRotate(t,x);
}
void insertFixup(tree *t,node *x){
    while(x != t->root){
    	if(sibling(x) != NULL && favorite(x->parent) == sibling(x)){
    		setBalance(x->parent);
    		break;
    	}
    	else if (favorite(x->parent) == NULL){
    		setBalance(x->parent);
    		x = x->parent;
    		//continue looping
    	}
        else {
            node *y = favorite(x);
            node *p = x->parent;
            if (y != NULL && !linear(y,x,p)){
                rotate(t,y,x);
                rotate(t,y,p);
                setBalance(x);
                setBalance(p);
                setBalance(y);
            }
            else {
                rotate(t,x,p);
                setBalance(p);
                setBalance(x);
            }
            break;
        }
    }
}
void delFixup(tree *t,node *x){
    x->height = 0; //since it will be deleted
    while (x != t->root){
        if (favorite(x->parent) == x){
            setBalance(x->parent);
            x = x->parent;
            //continue looping
        }
        else if(favorite(x->parent) == NULL){
            setBalance(x->parent);
            break;
        }
        else {
            node *p = x->parent;
            node *z = sibling(x);
            node *y = favorite(z);
            if (y != NULL && !linear(y,z,p)){
                rotate(t,y,z);
                rotate(t,y,p);
                setBalance(p);
                setBalance(z);
                setBalance(y);
                x = y;
                //continue looping
            }
            else {
                rotate(t,z,p);
                setBalance(p);
                setBalance(z);
                if (y == NULL)
                    break;
                x = z;
                //continue looping
            }
        }
    }
}
bool avlDelete(tree *t,char *key){
    node *w = findNode(t,key);
    if(w != NULL){
        node *z = swapToLeaf(t,w);
        delFixup(t,z);
        prune(t,z);
    }
    return true;
}
bool avlInsert(tree *t,node *n){
    bool status = Insert(t,n);
    if(status){
        setBalance(n);
        insertFixup(t,n);
    }
    return true;
}
