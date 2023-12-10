#include <stdio.h>
#include <stdlib.h>
// trasversal in both direction in a doubly linked list.
struct node
{
    int data;
    struct node *pre;
    struct node *next;
};


struct node *delatlast(struct node *head)
{

    struct node *ptr = head;
    struct node *p = head->next;

    while (p->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;

    free(p);

    return head;
}
int *trasversalf(struct node *ptr)
{
    printf("Trasvering in forward direction\n");
    do
    {
        printf("Element :%d\n", ptr->data);
        ptr = ptr->next;
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
    printf("Before deletion.");
    trasversalf(head);

    head = delatlast(head);
    
    printf("After deletion.");
    trasversalf(head);

    return 0;
}
