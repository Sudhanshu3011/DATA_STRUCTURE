//infix and postfix manner
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int top;
    int size;
    char *arr;
};
int operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int stacktop(struct stack *s)
{
    return s->arr[s->top];
}
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
char *intopost(char *infix)
{
    // not know reason
    struct stack *v = (struct stack *)malloc(sizeof(struct stack));
    v->top = -1;
    v->size = 100;
    v->arr = (char *)malloc(v->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i=0;
    int j=0;
    while (infix[i] != '\0')
    {
        if (!operator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stacktop(v)))
            {
                push(v, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(v);
                j++;
            }
        }
    }
    while (!isEmpty(v))
    {
        postfix[j] = pop(v);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *str;
    str = "a+b*c/d";
    printf("The postfix is %s.\n", intopost(str));

    return 0;
}