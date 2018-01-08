#include "queue.h"
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int          InitQueue(Queue** pQueue) {
//printf("InitQueue()\n");
  /* Memory allocation for struct */
  *pQueue = (struct Queue *)malloc(sizeof(struct Queue));

  /* Node initialization */
  (*pQueue)->pHead = NULL;
  (*pQueue)->pTail = NULL;
  (*pQueue)->pNode = NULL;

  (*pQueue)->IsEmpty = TRUE;
//printf("~InitQueue()\n");
  if (*pQueue == NULL)
    return -1;
  else
    return  0;
}

int         DeleteQueue(Queue **pQueue){
    struct Node * pTemp;
//printf("DeleteQueue(),ADDR:%X\n",*pQueue);
  pTemp = (*pQueue)->pTail;

  if(!((*pQueue)->IsEmpty))
  {
    while(pTemp->pNext != NULL)
    {
      (*pQueue)->pNode = pTemp->pNext;
      free(pTemp);
      pTemp = (*pQueue)->pNode;
    }

    /* Delete head node */
    free((*pQueue)->pNode);
  }

  (*pQueue)->pHead = NULL;
  (*pQueue)->pTail = NULL;
  (*pQueue)->pNode = NULL;

  /* Delete queue struct */
  free(*pQueue);
  *pQueue = NULL;
//printf("~DeleteQueue()\n");
  return 0;
}
int             enqueue(struct Queue * pQueue,int value){
//printf("enqueue(),ADDR:%X\n",pQueue);
  /* Memory allocaton for next node */
//printf("malloc()\n");
pQueue->pNode = (struct Node *)malloc(sizeof(struct Node));
//printf("pQueue->pNode:%X\n",pQueue->pNode);
//printf("~malloc()\n");
  /* if is queue is empty */
  if(pQueue->IsEmpty)
  {
//printf("if is queue is empty \n");
    pQueue->pHead = pQueue->pNode;
    pQueue->pTail = pQueue->pNode;
    pQueue->pNode->pNext = NULL;
    pQueue->pNode->pPrevious = NULL;
    pQueue->IsEmpty = FALSE;
  }
  else
  {
    /* reassign tail pointer pointer */
    pQueue->pNode->pNext = pQueue->pTail;
    pQueue->pTail->pPrevious = pQueue->pNode;
//printf("pQueue->pTail->pPrevious:%X\n",pQueue->pTail->pPrevious);
    pQueue->pTail = pQueue->pNode;
  }
  /*insert value in to tail*/
  pQueue->pTail->value = value;

//printf("pQueue:%X\n",pQueue);
//printf("pQueue->pHead:%X\n",pQueue->pHead);
//printf("pQueue->pTail:%X\n",pQueue->pTail);
//printf("pQueue->pNode->pNext:%X\n",pQueue->pNode->pNext);
//printf("pQueue->pNode->pPrevious:%X\n",pQueue->pNode->pPrevious);
//printf("pQueue->pTail->value:%d\n",pQueue->pTail->value);
//printf("~enqueue()\n");
  return 0;
}

int            dequeue(struct Queue * pQueue){
  int value = 0;
//printf("dequeue(),ADDR:%X\n",pQueue);

      /* if is queue is empty */
      if(pQueue->IsEmpty)
      {
//printf("if is queue is empty \n");
        return value;
      }
      else
      {
        /* reassign head pointer, get value and delete last node */
        pQueue->pNode = pQueue->pHead;
        pQueue->pHead = pQueue->pNode->pPrevious;
        value = pQueue->pNode->value;
        free(pQueue->pNode);

        if(pQueue->pHead == NULL)
            pQueue->IsEmpty = TRUE;
        else
           pQueue->pHead->pNext = NULL;
      }
//printf("~dequeue()\n");
  return value;
}

unsigned int      count(){
return 0;
}

int                peek(){
return 0;
}

void show(struct Queue * pQueue){
//printf("show()\n");
  pQueue->pNode = pQueue->pTail;

  while(pQueue->pNode->pNext != NULL)
  {
    printf("%d ",pQueue->pNode->value);
    pQueue->pNode = pQueue->pNode->pNext;
//printf("pQueue->pNode->pNext:%X\n",pQueue->pNode->pNext);
  }
  if(pQueue->pNode->pNext != NULL)
    printf("%d\n",pQueue->pNode->value);
//printf("~show()\n");
}

int IsEmpty(struct Queue * pQueue){\
return (int)(pQueue->IsEmpty);
}
