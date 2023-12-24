#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *push(struct node *top)
{
    int data;
    printf("Enter the element : ");
    scanf("%d", &data);

    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return top; // or handle failure appropriately
    }

    new->data = data;
    new->next = NULL;

    if (top == NULL)
    {
        new->prev = NULL;
    }
    else
    {
        new->prev = top;
        top->next = new;
    }

    top = new;
    return top;
}

struct node *pop(struct node *top)
{
    if (top == NULL)
    {
        printf("Stack is Empty.");
    }
    else
    {
        int data = top->data;
        struct node *newTop = top->prev;

        if (newTop != NULL)
        {
            newTop->next = NULL;
        }

        free(top);
        top = newTop;

        printf("\n Popped element is %d", data);
    }

    return top;
}

void peep(struct node *top)
{
    if (top == NULL)
    {
        printf("\nNothing to Display.");
    }
    else
    {
        printf("Topmost element of stack is %d", top->data);
    }
}

void display(struct node *top)
{
    struct node *temp = top;
    printf("Elements in stack : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    };
}

int main()
{
    // Write C code here
    struct node *top = NULL;
    int choice;
    printf("1.Push\t 2.Pop\t 3.Peep\t 4.Display\t 5.Exit");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            top = push(top);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            peep(top);
            break;
        case 4:
            display(top);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.");
        }
    };
    return 0;
}