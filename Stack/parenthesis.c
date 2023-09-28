#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isfull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *s, char x)
{
    if (isfull(s))
    {
        printf("The stack is overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top] = x;
    }
}
char pop(struct stack *s)
{

    if (isEmpty(s))
    {
        printf("The stack is underflow");
        return -1;
    }
    else
    {
        char ch;
        ch = s->arr[s->top];
        s->top--;
        return ch;
    }
}

int matchparen(char *ptr)
{
    struct stack *sp;
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == '(')
        {
            push(sp, '(');
        }
        else if (ptr[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
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
    char *str = "((st80)))";

    if (matchparen(str))
    {
        printf("The parrentheis is matching.");
    }
    else
    {
        printf("The parrentheis is not matching.");
    }

    return 0;
}