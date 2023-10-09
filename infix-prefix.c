#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct stack
{
    int top;
    int size;
    char *arr;
};
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
char *intopre(char *infix)
{
    struct stack *v = (struct stack *)malloc(sizeof(struct stack));
    v->top = -1;
    v->size = 100;
    v->arr = (char *)malloc(v->size * sizeof(char));
    char *prefix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0')
    {

    }
}
int main()
{
    char *str;
    str="A+B*C+D/G";

    printf("The prefix of the given is %s.",intopre(str));
     
     return 0;
}