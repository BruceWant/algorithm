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
	if (ch == 9)
		return;

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

void print(Tree *t)
{
	printf("print\n");
    if (t == NULL)
    {
		return;
    }
    else
    {

		printf("%c", t->cnt);
        print(t->l);
        print(t->r);
    }
}

int main()
{
    Tree *t = NULL;
    createTree(t);
	printf("test\n");
	print(t);
	printf("test2\n");

    return 0;
}
