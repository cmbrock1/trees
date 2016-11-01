/*******************************************************************
*   queue.h
*   Cameron Brock
*   Programming Assignment 2 trees
*
*   This program is entirely my own work
*******************************************************************/
#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
typedef struct qNode{
    node *data;
    struct qNode *next;
}qNode;
typedef struct queue{
    qNode *head;
    qNode *tail;
}queue;

extern queue *newQueue();
extern int EmptyQueue(queue *q);
extern int FullQueue(queue *q);
extern void Enqueue(queue *q,node *n);
extern node *Dequeue(queue *q);
extern void DestroyQueue(queue *q);
extern void printQueue(queue *q,FILE *fp);
extern int queueSize(queue *q);
#endif // QUEUE_H
