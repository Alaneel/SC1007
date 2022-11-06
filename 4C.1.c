#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct queue {
    int num[MAX];
    int front;
    int rear;
    int size;
} Queue;

int isFullQueue(Queue *q);
int isEmptyQueue(Queue *q);
int enqueue(Queue *q, int value);
int dequeue(Queue *q);
int peek(Queue *q);

int main()
{
    Queue q;
    q.front = 0;
    q.rear = 0;
    q.size = 0;
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);

    while (!isEmptyQueue(&q))
        printf("%d ", dequeue(&q));
    printf("\n");
    return 0;
}

int isFullQueue(Queue *q)
{
    if (q->size == MAX) return 1;
    else return 0;
}

int isEmptyQueue(Queue *q)
{
    if (q->size == 0) return 1;
    else return 0;
}

int enqueue(Queue *q, int value)
{
    if (q->rear < MAX - 1)
    {
        if (q->size == 0)
            q->num[q->rear] = value;
        else
        {
            q->rear++;
            q->num[q->rear] = value;
        }
        q->size++;
        return 1;
    }
    else return -1;
}

/* enqueue() FOR CIRCULAR ARRAY

int enqueue(Queue *q, int value)
{
    if (q->size < MAX)
    {
        if(q->size == 0)
            q->num[q->rear] = value;
        else
        {
            q->rear = (q->rear + 1) % MAX;
            q->num[q->rear] = value;
        }
        q->size++;
        return 1;
    }
    else return -1;
}

*/

int dequeue(Queue *q)
{
    int temp;
    if (!isEmptyQueue(q))
    {
        temp = q->num[q->front];
        q->size--;
        if (q->size > 0) q->front++;
        return temp;
    }
    else return 0;
}

/* dequeue() FOR CIRCULAR ARRAY

int dequeue(Queue *q)
{
    int temp;
    if (!isEmptyQueue(q))
    {
        temp = q->num[q->front];
        q->size--;
        if (q->size > 0)
            q->front = (q->front + 1) % MAX;
        return temp;
    }
    else return 0;
}

*/

int peek(Queue *q)
{
    if (!isEmptyQueue(q))
        return q->num[q->front];
    else return -1;
}
