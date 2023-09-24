#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int linkedlist(struct node *ptr)
{
    int a[100], i = 0, j = 0, b = 0;
    while (ptr != NULL)
    {
        // printf("the element is %d.\n", ptr->data);
        a[i] = ptr->data;
        ptr = ptr->next;
        i++;
    }
    
    while (ptr->next != NULL)
    {
        printf("the element is %d.\n", ptr->data);
        ptr = ptr->next;


    }
    // struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *p=ptr;

    for (int j = i; j > 0; j--)
    {
        p->data = a[j];
        p = p->next;
        b++;
    }
    if (j == 0)
    {
        p->next = NULL;
    }
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

    linkedlist(head);

    return 0;
}