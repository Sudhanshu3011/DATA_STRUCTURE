#include <stdio.h>
#include<stdlib.h>
// when we have to insert the first element
struct node
{
    int data;
    struct node *next;
};

int linkedlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("the element is %d.\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *instfirst(struct node *head , int data)
{
    struct node *ptr =(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
    

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
    head = instfirst(head ,50);
    linkedlist(head);

    return 0;
}