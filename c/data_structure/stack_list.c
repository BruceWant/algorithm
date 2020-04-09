#include <stdio.h>
#include <stdlib.h>



typedef struct Stack
{
    int data;
    struct Stack *next;
}Stack, *pStack;

typedef struct LinkStack
{
    pStack top;
    int count;
}LinkStack;

int isEmpty(LinkStack *s)
{
    if (s->count <= 0)
        return 1;
    return 0;
}

int push(LinkStack *s, int var)
{
    pStack stack = (pStack)malloc(sizeof(Stack));
    stack->data = var;
    stack->next = s->top;
    s->top = stack;
    s->count++;

    return s->count;
}

int pop(LinkStack *s, int *var)
{
    pStack stack;
    int tmp;
    if (isEmpty(s))
        return 1;
    if (var != NULL)
        *var = s->top->data;
    tmp = s->top->data;
    stack = s->top;
    s->top = s->top->next;
    free(stack);
    s->count--;

    return tmp;
}

void print(LinkStack *s)
{
    pStack stack = s->top;
    for (int i = 0; i < s->count; i++)
    {
        printf("%-3d", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int main()
{
    LinkStack s;
    s.count = 0;
    s.top = NULL;

    for (int i = 0; i < 10; i++)
    {
        push(&s, i);
    }
    print(&s);

    pop(&s, NULL);
    print(&s);
    for (int i = 0; i < 10; i++)
    {
        pop(&s, NULL);
    }

    if (isEmpty(&s))
    {
        printf("stack is empty\n");
    }

    return 0;
}
