#include <stdio.h>
#include <stdlib.h>


typedef struct Tree
{
    int cnt;
    struct Tree *l, *r;
} Tree;

void createTree(Tree *t)
{
    int ch;
    scanf("%d", &ch);
    if (ch == 0)
    {
        t = NULL;
    }
    else
    {
        t = malloc(sizeof(Tree));
        t->cnt = ch;

        createTree(t->l);
        createTree(t->r);
    }
}


int main()
{
    Tree *t = NULL;
    createTree(t);

    return 0;
}
