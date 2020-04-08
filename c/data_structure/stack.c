#include <stdio.h>

#define size 10

typedef struct Stack
{
    int data[size];
    int top;
}Stack;

int push(struct Stack *stack, int var)
{
    if (stack->top > size - 1)
    {
        return 0;
    }

    stack->data[stack->top++] = var;

    return var;
}

int pop(Stack *stack)
{
    if (stack->top <= 0)
    {
        return 0;
    }

    return stack->data[--stack->top];
}

int isEmpty(Stack *stack)
{
    // top <= 0, the stack is empty
    if (stack->top <= 0)
    {
        return 1;
    }
    return 0;
}

int isFull(Stack *stack)
{
    // if top >= size, the stack is full
    if (stack->top > size - 1)
    {
        return 1;
    }
    return 0;
}

void print(Stack *s)
{
    for (int i = 0; i < s->top; i++)
        printf("%-3d", s->data[i]);
    printf("\n");
}

int main()
{
    Stack s;
    s.top = 0;

    for (int i = 0; i < size; i++)
    {
        push(&s, i);
    }
    print(&s);
    if (isFull(&s))
    {
        printf("stack is full\n");
    }

    pop(&s);
    print(&s);
    for (int i = 0; i < size; i++)
    {
        pop(&s);
    }

    if (isEmpty(&s))
    {
        printf("stack is empty\n");
    }

    return 0;
}
