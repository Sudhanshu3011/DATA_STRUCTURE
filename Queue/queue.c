#include <stdio.h>
#include <stdlib.h>
// fifo princple is used here
struct queue
{
    int front;
    int back;
    int size;
    int *arr;
};
//emputy function
int isempty(struct queue *q)
{
    if (q->back == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//full function
int isfull(struct queue *q)
{
    if (q->back == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//enqueue function
void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("The queue is full.\n");
    }
    else
    {
        q->back++;
        q->arr[q->back] = val;
        printf("Enqueued element is %d.\n", q->arr[q->back]);
    }
}
//dequeue function
int dequeue(struct queue *q)
{
    int a;
    if (isempty(q))
    {
        printf("The queue is empty.\n");
    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main()
{
    struct queue q;
    q.front = -1;
    q.back = -1;
    q.size = 100;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 2);
    enqueue(&q, 4);
    enqueue(&q, 5);
    printf("Dequeing the element %d.\n", dequeue(&q));
    printf("Dequeing the element %d.\n", dequeue(&q));
    // printf("Dequeing the element %d.\n", dequeue(&q));
    // printf("Dequeing the element %d.\n", dequeue(&q));
    // printf("Dequeing the element %d.\n", dequeue(&q));
    if (isempty(&q))
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("The queue is not empty.\n");
    }

    return 0;
}