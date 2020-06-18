#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <stdlib.h>

struct link
{
    int cnt;
    struct link *next;
};

typedef struct link Link;


Link* create(int n);
void change(Link *list, int n);
void delet(Link *list, int n);
void insert(Link *list, int n);
void print(Link *list);
void destroy(Link *list);


#endif
