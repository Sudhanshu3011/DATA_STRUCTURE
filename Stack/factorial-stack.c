#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int top=-1;
int size=20;
int arr[20];

// function that check the stack is empty.
int empty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// function that check the stack is full.
int full()
{
    if (top ==size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// pushing an elememt is a stack.
void push( int value)
{
    if (full(top))
    {
        printf("stack is overflow.");
        return;
    }
    else
    {
        top++;
        arr[top] = value;
        
    }
}
// poping an element in the stack
int pop()
{
    if (empty(top))
    {
        printf("stack is under flow.");
        return -1;
    }
    else
    {
        int value = arr[top];
        top--;
        return value;
    }
}
//display function for the stack
void display()
{
    while (!empty(top))
    {
        printf("%d\n", arr[top]);
        top--;
    }
}
int main()
{

   
    int num;
    long fact = 1;

    printf("enter the number: ");
    scanf("%d", &num);
    
    
    for(int i=1;i<=num;i++)
    {
        push(i);
    }
    for(int i=1;i<=num;i++)
    {
        fact =fact*pop();
    }
    //thr stack must be empty at the end of operation
    if (empty(top))
    {
    printf("The factorial of number is%d.", fact);
    }

    return 0;
}