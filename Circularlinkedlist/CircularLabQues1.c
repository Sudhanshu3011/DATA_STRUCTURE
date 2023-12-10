#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert_atlast(struct node *head, int data)
{
    printf("Element inserted is %d.\n", data);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    
    if (head == NULL)
    {

        head = ptr;
        ptr->next = head;
    }
    else
    {
        struct node *p = head->next;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
    }

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
    struct node *head = NULL;
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

    head = insert_atlast(head, 24);

    printf("After insertion.\n");
    traversal(head);

    return 0;
}
