/*******************************************************************
*   queue.c
*   Cameron Brock
*   Programming Assignment 2 trees
*
*   This program is entirely my own work
*******************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include "node.h"
#include "Fatal.h"

void initQueue(queue *q){
    q->head = q->tail = NULL;
}
void initQNode(qNode *n){
    n->data = NULL;
    n->next = NULL;
}
qNode *newQNode(node *data){
    qNode *n;
    if ((n = (qNode *)malloc(sizeof(qNode))) == 0)
        Fatal("out of memory\n");
    initQNode(n);
    n->data = data;
    return n;
}
queue *newQueue(void){
    queue *q;
    if ((q = (queue *)malloc(sizeof(queue))) == 0)
        Fatal("out of memory\n");
    initQueue(q);
    return q;
}
int EmptyQueue(queue *q){
    if(q->head == NULL && q->tail == NULL)
        return true;
    else
        return false;
}
int FullQueue(queue *q){
    return false;
}
void Enqueue(queue *q,node *n)
    {
    if (q->head == NULL && q->tail == NULL)
        {
        q->head = newQNode(n);
        q->tail = q->head;
        }
    else
        {
        q->tail->next = newQNode(n);
        q->tail = q->tail->next;
        }
    }

node *Dequeue(queue *q)
    {
    	if(EmptyQueue(q))
            Fatal("Dequeue Empty Queue\n");
    	node *temp = q->head->data;
    	q->head = q->head->next;
    	if (q->head == NULL)
    		q->tail = NULL;
    	return temp;
    }
// void Enqueue(queue *q,node *n){
//     node *temp = newNode();
//     if(q->head == NULL)
//         q->head = q->tail = temp;
//     else {
//         q->tail->next = temp;
//         q->tail = temp;
//     }
// }
// node *Dequeue(queue *q){
//     if(EmptyQueue(q))
//         return NULL;
//     else {
//         node *temp = q->head;
//         q->head = q->head->next;
//         if(q->head == NULL)
//             q->tail = NULL;
//         return temp;
//     }
// }
// void DestroyQueue(queue *q){
//     if(!EmptyQueue(q)){
//         qNode *temp = q->head;
//         while(temp != NULL){
//             temp = q->head->next;
//             free(q->head);
//             q->head = temp;
//         }
//     }
// }
// void printQueue(queue *q,FILE *fp){
//     if(q == NULL)
//         return;
//     qNode *temp = q->head;
//     if(q->head == NULL)
//         return;
//     displayNode(temp,fp);
//     while(temp->next != NULL){
//         temp = temp->next;
//         displayNode(temp,fp);
//     }
//     printf("\n");
// }
// int queueSize(queue *q){
//     int i = 0;
//     qNode *temp = q->head;
//     while(temp != NULL){
//         i++;
//         temp = temp->next;
//     }
//     return i;
// }
