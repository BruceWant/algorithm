#include <stdio.h>


#define size 10

typedef struct
{
    int data[size];
    unsigned int head;
    unsigned int tail;
}Queue;

int initQueue(Queue *q)
{
    q->head = 0;
    q->tail = 0;
    return 0;
}

int queueLength(Queue *q)
{
    return (q->tail - q->head + size) % size;
}


int enqueue(Queue *q, int var)
{
    // if (tail+1)%size == head the queue is full
    if ((q->tail+1)%size == q->head)
    {
        return 0;
    }

    q->data[q->tail] = var;
    q->tail = (q->tail + 1) % size;
    return q->tail;
}

int dequeue(Queue *q)
{
    int var;
    // if head == (tail-1) the queue is empty
    if (q->head == q->tail)
    {
        return 0;
    }

    var = q->head;
    q->head = (q->head + 1) % size;
    return var;
}

int print(Queue *q)
{
    if (q->tail == q->head)
        return 0;
    int len = queueLength(q);
    int i = q->head;
    while (len > 0)
    {
        printf("%-4d", q->data[i]);
        i++;
        len--;
    }
    printf("\n");
    return 0;
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    print(&q);

    dequeue(&q);
    print(&q);

    return 0;
}
