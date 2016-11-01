#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "node.h"
#include "avl.h"
int main(void){
    tree *t = newTree();
    node *n5 = newTreeNode("e");
    node *n4 = newTreeNode("d");
    node *n3 = newTreeNode("c");
    node *n2 = newTreeNode("b");
    node *n1 = newTreeNode("a");
    avlInsert(t,n1);
    avlInsert(t,n2);
    avlInsert(t,n3);
    avlInsert(t,n4);
    avlInsert(t,n5);
    AVL = true;
    FILE *fp = fopen("test","w");
    //printLevelOrder(t,fp);
    avlDelete(t,"b");
    printLevelOrder(t,fp);
    //bstDelete(t,"b");
    //printf("After: \n");
    //displayTree(t);
    return 0;
}
