#include <stdio.h>
#include <stdlib.h>
// insert at given index in circular linked list
struct node
{
    int data;
    struct node *next;
};
struct node *insertbefindex(struct node *head, int data, int ind)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i = 1;
    while (i < ind - 1)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}
void traversal(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = head;
    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
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

    first->data = 102;
    first->next = second;

    second->data = 12;
    second->next = third;

    third->data = 14;
    third->next = head;
    printf("Before insertion.\n");
    traversal(head);
    head = insertbefindex(head, 24, 2);
    printf("After insertion.\n");
    traversal(head);

    return 0;
}

