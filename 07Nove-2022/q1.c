// WAP to do the following in queue data structure enqueue dequeue
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void enqueue(struct queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("\nQueue is Full");
    else
    {   
        q->Q[++q->rear] = x;
    }
}
int dequeue(struct queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("\nQueue is Empty\n");
    else
    {
        x = q->Q[++q->front];
    }
    return x;
}
void Display(struct queue q)
{
    int i;
    for (i = q.front+1 ; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}
bool isEmpty(struct queue *q)
{
    return (q->front == q->rear) ? true : false;
}
bool isFull(struct queue* q)
{
    return (q->rear == q->size-1) ? true : false;
}
int main()
{
    struct queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    printf("\nDisplaying :");
    Display(q);
    printf("\nDequeue begin:\n");
    printf("%d ",dequeue(&q));printf("\n");
    printf("%d ",dequeue(&q));printf("\n");
    printf("%d ",dequeue(&q));printf("\n");
    printf("%d ",dequeue(&q));printf("\n");
    printf("%d ",dequeue(&q));printf("\n");
    printf("%d ",dequeue(&q));printf("\n");
    return 0;
}