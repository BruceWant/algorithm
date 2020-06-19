#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode
{
    int value;
    struct ListNode *next;
} ListNode;

ListNode *mergeSortedList(ListNode *L1, ListNode *L2)
{
    ListNode dummy, *p1 = &dummy, *p2 = L2;  //L1的辅助头结点dummy，因为可能在头部插入
    dummy.next = L1;
    while(p1->next != NULL && p2 != NULL)  //停止条件，也包括了判断两个链表是否为空
    {
        if(p1->next->value >= p2->value)
        {
            L2 = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = L2;
        }
        else
        {
            p1 = p1->next;
        }
    }
    if(p1->next == NULL)    //L2可能还有未处理的结点，直接加在L1尾部即可
    {
        p1->next = p2;
    }

    return dummy.next;
}



ListNode *listMergeSort(ListNode *head)
{
    if(head == NULL || head->next == NULL)   //链表为空，或者只有一个结点，直接返回
        return head;
    
    ListNode *slow = head, *fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *leftHead = head, *rightHead = slow->next;
    slow->next = NULL;      //需要把左半链表的尾结点的next赋空值，所以用一个变量来记录右半链表的头

    leftHead  = listMergeSort(leftHead);
    rightHead = listMergeSort(rightHead);

    return mergeSortedList(leftHead, rightHead);
}


int main()
{
    ListNode *head = malloc(sizeof(ListNode));
    ListNode *tail = head, *node;

    for (int i = 0; i < 10; i++)
    {
        node = malloc(sizeof(ListNode));
        node->value = 10 - i;

        tail->next = node;
        tail = node;
    }
    tail->next = NULL;

    listMergeSort(head);

    node = head->next;
    while (node != NULL)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");

    return 0;
}
