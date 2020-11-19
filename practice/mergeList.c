#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int val;
    struct List *next;
} List;


List* merge(List *left, List *right)
{
    List head;
    List *l = &head, *r = right;
    List *tmp = NULL;

    head.next = left;
    while (l->next != NULL && r != NULL)
    {
        if (l->next->val > r->val)
        {
            tmp = r->next;
            r->next = l->next;
            l->next = r;

            l = r;
            r = tmp;
        }
        else
        {
            l = l->next;
        }
    }

    while (l->next == NULL)
    {
        l->next = r;
    }

    return head.next;
}

List* sort(List *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    List *slow = head, *fast = head;
    List *tmp = NULL, *l, *r;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    l = head, r = slow->next;
    slow->next = NULL;

    l = sort(l);
    r = sort(r);
    return merge(l, r);
}

int main()
{
    List *head = malloc(sizeof(List));
    List *tail = head, *node;

    for (int i = 0; i < 10; i++)
    {
        node = malloc(sizeof(List));
        node->val = 10 - i;

        tail->next = node;
        tail = node;
    }
    tail->next = NULL;

    head->next = sort(head->next);

    node = head->next;
    while (node != NULL)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");

    return 0;
}
