#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
// function that check the stack is empty.
int empty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// function that check the stack is full.
int full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// pushing an elememt is a stack.
int push(struct stack *ptr, int value)
{
    if (full(ptr))
    {
        printf("stack is overflow.");
        return -1;
    }
    else
    {
        ptr->top++;
        return ptr->arr[ptr->top] = value;
    }
}
// poping an element in the stack
int pop(struct stack *ptr)
{
    if (empty(ptr))
    {
        printf("stack is under flow.");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
// value at top
int peep(struct stack *ptr,int index){
    
}
int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top ];
}
// value at end
int stackbot(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 8;

    s->top++;
    printf("Before pushing empty: %d.\n", empty(s));
    printf("Before pushing full: %d.\n", full(s));

    if (empty(s))
    {
        printf("the stack is empty.\n");
    }
    else
    {
        printf("the stack is not empty.\n");
    }
    // pushing elements
    printf("the element is %d\n", push(s, 12));
    printf("the element is %d\n", push(s, 3));
    printf("the element is %d\n", push(s, 6));
    printf("the element is %d\n", push(s, 7));
    printf("the element is %d\n", push(s, 82));
    printf("the element is %d\n", push(s, 100));
    //element at top display
    printf("the element at the top %d.\n", stacktop(s));

    printf("after pushing empty: %d.\n", empty(s));
    printf("after pushing full: %d.\n", full(s));

    // poping elements
    printf("the element is %d\n", pop(s));
    printf("the element is %d\n", pop(s));
    printf("the element is %d\n", pop(s));
    printf("the element is %d\n", pop(s));
    printf("the element is %d\n", pop(s));
    printf("the element is %d\n", pop(s));
    // here as we know that the last poing element should be 12 after that the element arr[0]=8 get poped out and
    // the stack get under flow
    printf("after pop empty: %d.\n", empty(s));
    printf("after pop full: %d.\n", full(s));

    printf("the element at the top %d.\n", stacktop(s));
    printf("the element at the bottom %d.\n", stackbot(s));

    return 0;
}