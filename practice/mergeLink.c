#include <stdio.h>
#include <stdlib.h>


struct Link
{
    int value;
    struct Link *next;
};

typedef struct Link Link;

Link* merge(Link *left, Link *right)
{
    Link head, *l, *r = right, *tmp;
    l = &head;

    head.next = left;
    while (l->next != NULL && r != NULL)
    {
        if (l->next->value > r->value)
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
        
    if (l->next == NULL)
    {
        l->next = r;
    }

    return head.next;
}


Link* sort(Link *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Link *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Link *left = head, *right = slow->next;
    slow->next = NULL;

    left = sort(left);
    right = sort(right);
    return merge(left, right);
}


int main()
{
    Link *head = malloc(sizeof(Link));
    Link *tail = head, *node;

    for (int i = 0; i < 10; i++)
    {
        node = malloc(sizeof(Link));
        node->value = 10 - i;

        tail->next = node;
        tail = node;
    }
    tail->next = NULL;

    sort(head);

    node = head->next;
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");

    return 0;
}
