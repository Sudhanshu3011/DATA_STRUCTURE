//stack using the linked list
#include <stdio.h>
#include <stdlib.h>
//stack using linked list 

void push();
void display();
void pop();

struct node
{
    int data;
    struct node *next;
};

struct node *head;
void main()
{
    push();
    push();
    push();
    push();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
}
void push()
{
    int val;

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("No element to push.\n");
    }
    else
    {
        printf("Enter the element:");
        scanf("%d", &val);

        if (head == NULL)
        {
            ptr->data = val;
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->data = val;
            ptr->next = head;
            head = ptr;
        }
        printf("Item is pushed.\n");
    }
}
void pop()
{
    int *ptr;
    if (head == NULL)
    {
        printf("NO element  to pop.\n");
    }
    else
    {
        *(ptr) = head->data;
        head = head->next;
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
