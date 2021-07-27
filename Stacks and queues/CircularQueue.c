#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int *arr;
    int size;
    int rear;
    int front;
};
void enqueue(struct queue *q, int n)
{
    if ((q->rear + 1) % (q->size) == q->front)
    {
        printf("Queue is full");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = n;
    }
}
void dequeue(struct queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("queue empty");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}

int main()
{
    struct queue *q;
}