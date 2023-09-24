#include <stdio.h>
#include <stdlib.h>
// insert a linked list at last
struct node
{
    int data;
    struct node *next;
};
struct node *instlast(struct node *head, int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = value;
    p->next = ptr;
    ptr->next = NULL;

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
    head = instlast(head, 50);

    linkedlist(head);

    return 0;
}