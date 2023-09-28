#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
//delete at the index
struct node *atindex(struct node *head, int ind)
{
    struct node *p = head;
    struct node *q = head->next;
    int i;
    while (i != ind -1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
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

    first->data = 11;
    first->next = second;

    second->data = 12;
    second->next = third;

    third->data = 14;
    third->next = NULL;

    head = atindex(head, 2);

    linkedlist(head);

    return 0;
}