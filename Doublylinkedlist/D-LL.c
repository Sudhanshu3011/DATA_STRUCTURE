#include <stdio.h>
#include <stdlib.h>
// trasversal in both direction in a doubly linked list.
struct node
{
    int data;
    struct node *pre;
    struct node *next;
};
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

    trasversalf(head);
    trasversalb(third);

    return 0;
}