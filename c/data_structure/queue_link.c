#include <stdio.h>
#include <stdlib.h>


typedef struct Queue
{
    int data;
    struct Queue *next;
}Queue, *pQueue;

typedef struct
{
    pQueue head, tail;
}LinkQueue;

int enqueue(LinkQueue *q, int var)
{
    pQueue s = (pQueue)malloc(sizeof(Queue));
    if (!s)
        return 1;
    s->data = var;
    s->next = NULL;
    q->tail->next = s;

    q->tail = s;

    return 0;
}

int dequeue(LinkQueue *q, int *var)
{
    pQueue p;
    if (q->head == q->tail)
        return 1;
    p = q->head->next;
    *var = p->data;
    q->head->next = p->next;
    
    if (q->head->next == NULL)
        q->tail = q->head;
    free(p);

    return 0;
}

void print(LinkQueue *q)
{
    pQueue tmp = q->head->next;
    while (tmp)
    {
        printf("%-3d", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


int main()
{
    LinkQueue lq;
    Queue q;
    int var = 0;

    lq.head = &q;
    lq.tail = &q;

    for (int i = 0; i < 10; i++)
        enqueue(&lq, i);
    print(&lq);

    dequeue(&lq, &var);
    print(&lq);
    for (int i = 0; i < 12; i++)
        dequeue(&lq, &var);
    print(&lq);


    return 0;
}
