#include "link.h"

Link* create(int n)
{
    Link *head, *node, *tail;

    head = malloc(sizeof(Link));
    tail = head;
    for (int i = 0; i < n; i++)
    {
        node = malloc(sizeof(Link));
        node->cnt = 0;

        tail->next = node;
        tail = node;
    }
    tail->next = NULL;

    return head;
}

void change(Link *list, int n)
{
    Link *tmplst = list->next;

    for (int i = 0; i < n && tmplst != NULL; i++)
    {
        tmplst = tmplst->next;
    }
    if (tmplst != NULL)
    {
        tmplst->cnt++;
    }
}

void delet(Link *list, int n)
{
    Link *tmplst = list->next, *last = list;

    for (int i = 0; i < n && tmplst != NULL; i++)
    {
        last = tmplst;
        tmplst = tmplst->next;
    }

    if (tmplst != NULL)
    {
        last->next = tmplst->next;
        free(tmplst);
    }
}

void insert(Link *list, int n)
{
    Link *tmplst = list;

    for (int i = 0; i < n && tmplst != NULL; i++)
    {
        tmplst = tmplst->next;
    }

    if (tmplst != NULL)
    {
        Link *newlst = malloc(sizeof(Link));
        newlst->cnt = 5;
        // new->next = NULL;

        newlst->next = tmplst->next;
        tmplst->next = newlst;
    }
}

void print(Link *list)
{
    Link *tmp = list->next;

    while (tmp != NULL)
    {
        printf("%d ", tmp->cnt);
        tmp = tmp->next;
    }
    printf("\n");
}

void destroy(Link *list)
{
    Link *del = list->next;
    Link *head = list;
    int i = 0;
    while (del != NULL && i < 10)
    {
        head = del->next;
        del->next = NULL;
        free(del);
        del = head;
    }
    free(list);
}
