#include <stdio.h>
#include <stdlib.h>
// trasversal in both direction in a doubly linked list.
struct node
{
    int data;
    struct node *pre;
    struct node *next;
};

struct node *createnew(int data)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = new->pre = NULL;

    return new;
}
struct node *insertatlast(struct node *head, int data)
{
    struct node *newhead = createnew(data);
    struct node *ptr = head;
    newhead->next = NULL;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newhead->pre = ptr;
    ptr->next = newhead;

    return head;
}
int *trasversalf(struct node *ptr)
{
    printf("Trasvering in forward didection\n");
    do
    {
        printf("Element :%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}
int *trasversalb(struct node *ptr)
{
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    printf("Trasvering in backward didection\n");
    do
    {
        printf("Element :%d\n", ptr->data);
        ptr = ptr->pre;
    } while (ptr != NULL);
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

    head->data = 1;
    head->next = first;
    head->pre = NULL;

    first->data = 2;
    first->next = second;
    first->pre = head;

    second->data = 3;
    second->next = third;
    second->pre = first;

    third->data = 4;
    third->next = NULL;
    third->pre = second;
    head = insertatlast(head, 0);

    trasversalf(head);
    trasversalb(head);

    return 0;
}