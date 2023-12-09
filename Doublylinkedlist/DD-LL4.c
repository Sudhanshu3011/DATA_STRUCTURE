#include <stdio.h>
#include <stdlib.h>
// trasversal in both direction in a doubly linked list.
struct node
{
    int data;
    struct node *pre;
    struct node *next;
};

struct node *delatind1(struct node *head, int index)
{
    struct node *p = head;
    struct node *ptr = NULL;
    int ind = 0;

    if (index == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->pre = NULL;
        }
        free(p);
        return head;
    }

    while (ind < index - 1 && p != NULL)
    {
        ptr = p;
        p = p->next;
        ind++;
    }

    if (p == NULL)
    {
        // Index out of bounds
        return head;
    }

    ptr->next = p->next;

    if (p->next != NULL)
    {
        p->next->pre = ptr;
    }

    free(p);

    return head;
}


void *trasversalf(struct node *ptr)
{
    printf("Trasvering in forward didection\n");
    
    do
    {
        printf("Element :%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}
void *trasversalb(struct node *ptr)
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
    head = delatind1(head, 3);

    trasversalf(head);
    trasversalb(head);

    return 0;
}