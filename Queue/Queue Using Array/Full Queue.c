#include<stdio.h>

struct queue
{
    unsigned capacity;
    unsigned size;
    int *array;
    int front;
    int rear;
};

struct queue *makeQueue(unsigned c)
{
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    temp->capacity = c;
    temp->size = 0;
    temp->array = (int *)malloc(c * sizeof(int));
    temp->front = 0;
    temp->rear = c-1;
    return temp;
}

int isFull( struct queue *q)
{
    return (q->capacity == q->size);
}

int isEmpty(struct queue *q)
{
    return (q->size ==0);
}

void enQueue(struct queue *q, int item)
{
    if(isFull(q))
    {
        printf("Queue Overflow.\n");
        return;
    }
    q->rear = (q->rear+1) % q->capacity;
    q->array[q->rear] = item;
    q->size = q->size+1;
}

int deQueue(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue Underflow.\n");
        return;
    }
    int item = q->array[q->front];
    q->front = (q->front+1) % (q->capacity);
    q->size = q->size-1;
    return item;
}

int main()
{
    unsigned capacity;
    printf("Capacity of the Array = ");
    scanf("%u",&capacity);
    struct queue *q = makeQueue(capacity);
    int data;
    scanf("%d", &data);
    while(data>0)
    {
        enQueue(q, data);
        if(isFull(q))
        {
            printf("Queue is Full.Can't Insert.\n");
            break;
        }
        scanf("%d", &data);
    }
    printf("\nDequeuing...\n");
    while( ! isEmpty(q))
    {
        printf("%d\n", deQueue(q));
    }
}
