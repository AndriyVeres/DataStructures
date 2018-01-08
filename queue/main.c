#include <stdio.h>
#include "queue.h"


int main()
{
    struct Queue * queue = NULL;
    InitQueue(&queue);
    for(int i=0;i<20;++i)
    {
      enqueue(queue,i);
      show(queue);
      printf("\nIsEmpty:%d\n",IsEmpty(queue));
    }

    for(int i=0;i<20;++i)
    {
      dequeue(queue);
      show(queue);
      printf("\nIsEmpty:%d\n",IsEmpty(queue));
    }

    DeleteQueue(&queue);
    printf("TEST\n");
    return 0;
}
