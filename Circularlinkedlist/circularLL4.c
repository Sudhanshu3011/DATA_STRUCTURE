#include <stdio.h>
#include <stdlib.h>
// insert at given node in circular linked list
struct node
{
    int data;
    struct node *next;
};
struct node *insert_atnode(struct node *head, struct node *prenode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prenode->next;
    prenode->next = ptr;
    return head;
}
void trasversal(struct node *head)
{
    struct node *ptr = head;
    printf("Element :%d\n", ptr->data);
    ptr = ptr->next;
    do
    {
        printf("Element :%d\n", ptr->data);
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
    third->next = NULL;
    head = insert_atnode(head, first, 24);
    trasversal(head);

    return 0;
}