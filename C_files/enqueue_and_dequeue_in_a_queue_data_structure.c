#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int size;
    int front;
    int rare;
} queue;

int is_Empty(queue *q)
{
    if (q->rare == q->front)
        return 1;
    else
        return 0;
}

int is_Full(queue *q)
{
    if (q->rare == (q->size - 1))
        return 1;
    else
        return 0;
}

queue *intiallised(int size)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = size;
    q->arr = (int *)malloc(size * sizeof(int));
    q->rare = -1;
    q->front = -1;
    return q;
}

void enqueue(queue *q, int a)
{
    if (is_Full(q))
    {
        printf("queue is full.So %d is not enqueue in queue\n", a);
        return;
    }
    q->rare++;
    q->arr[q->rare] = a;
    return;
}

int dequeue(queue *q)
{
    if (is_Empty(q))
    {
        printf("queue is empty.So dequeue not possible\n");
        return -1;
    }
    else
    {
        q->front++;
        return q->arr[q->front];
    }
}

void del(queue *q)
{
    free(q->arr);
    free(q);
    return;
}

int main()
{
    queue *q = intiallised(6);

    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1);
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    enqueue(q, 45);
    enqueue(q, 45);
    enqueue(q, 45);
    enqueue(q, 35);

    if (is_Empty(q))
    {
        printf("Queue is empty\n");
    }
    if (is_Full(q))
    {
        printf("Queue is full\n");
    }
    del(q);
    return 0;
}

