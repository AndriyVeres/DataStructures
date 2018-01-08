#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

typedef struct Node {
int            value;
struct Node  * pNext;
struct Node  * pPrevious;
}Node;

typedef struct Queue {
   struct Node * pHead;
   struct Node * pTail;
   struct Node * pNode;
   int8_t        IsEmpty;
}Queue;

int InitQueue(struct Queue **pQueue);
int DeleteQueue(struct Queue **pQueue);
int             enqueue(struct Queue * pQueue,int value);
int dequeue(struct Queue * pQueue);
unsigned int      count();
int                peek();
void show(struct Queue * pQueue);
int IsEmpty(struct Queue * pQueue);

#endif // QUEUE_H
