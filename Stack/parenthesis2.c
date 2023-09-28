#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr)
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
int isfull(struct stack *ptr)
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

void push(struct stack *ptr, char val)
{
    if (isfull(ptr))
    {
        printf("The stack overflow.\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The stack is underflow.\n");
        return -1;
    }
    else
    {
        char ch;
        ch = ptr->arr[ptr->top];
        ptr->top--;
        return ch;
    }
}
int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}
int parenmatching(char *str)
{
    struct stack *ptr;
    char x;
    ptr->top = -1;
    ptr->size = 100;
    ptr->arr = (char *)malloc(ptr->size * sizeof(char));

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {

            push(ptr, str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (isEmpty(ptr))
            {
                return 0;
            }
            x = pop(ptr);
            if (match(x, str[i]))
            {
                return 1;
            }
        }
    }
    if (isEmpty(ptr))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char *s;
    s = "({[hs*&&k]})";
    if (parenmatching(s))
    {
        printf("The parenthesis is matching.\n");
    }
    else
    {
        printf("The parenthesis is not matching.\n");
    }

    return 0;
}