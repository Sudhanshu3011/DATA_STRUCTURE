#include <stdio.h>
#include <stdlib.h>
// insert a linked list at a given index
struct node
{
    int data;
    struct node *next;
};
struct node *instind(struct node *head, int value, int ind)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int i = 1;
    struct node *p = head;
    while (i < ind -1)
    {
        p = p->next;
        i++;
    }
    ptr->data = value;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}
int linkedlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("the element is %d.\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{

    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = first;

    first->data = 10;
    first->next = second;

    second->data = 12;
    second->next = third;

    third->data = 14;
    third->next = NULL;
    head = instind(head, 50, 3);

    linkedlist(head);

    return 0;
}