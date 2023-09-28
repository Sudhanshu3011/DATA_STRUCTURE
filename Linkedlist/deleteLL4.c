#include <stdio.h>
#include <stdlib.h>
// delete a element to the next of given index
struct node
{
    int data;
    struct node *next;
};
struct node *atnext(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data == value && q->next == NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->next == NULL)
    {
        p->next = q->next;
        free(q);
    }
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

    head = atnext(head, 2);

    linkedlist(head);

    return 0;
}