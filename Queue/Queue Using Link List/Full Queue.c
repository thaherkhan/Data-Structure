#include<stdio.h>
#include<stdlib.h>

struct queueNode
{
    int data;
    struct queueNode *next;
};

struct queueNodePointer
{
    struct queueNode *front;
    struct queueNode *rear;
};

struct queueNode *makeQN(int item)
{
    struct queueNode *temp = (struct queueNode *)malloc(sizeof(struct queueNode));
    temp->data = item;
    temp->next = NULL;
    return temp;
}

struct queueNodePointer *makeQNP()
{
    struct queueNodePointer *qnp = (struct queueNodePointer *)malloc(sizeof(struct queueNodePointer));
    qnp->front = NULL;
    qnp->rear = NULL;
    return qnp;
}

int isEmpty(struct queueNodePointer *qnp)
{
    return (qnp->front = NULL);
}

void enQueue(struct queueNodePointer *qnp, int item)
{
    struct queueNode *temp = makeQN(item);
    if(qnp->rear == NULL)
    {
        qnp->front = temp;
        qnp->rear = temp;
        return;
    }
    qnp->rear->next = temp;
    qnp->rear = temp;
}

int deQueue(struct queueNodePointer *qnp)
{
    if(isEmpty(qnp))
    {
        printf("Queue Underflow.\n");
        return;
    }
    int item = qnp->front->data;
    struct queueNode *temp = qnp->front;
    qnp->front = temp->next;
    if(qnp->front == NULL)
    {
        qnp->rear = NULL;
    }
    free(temp);
    return item;
}

int main()
{
    struct queueNodePointer *qnp = makeQNP();
    int data;
    scanf("%d", &data);
    while(data>0)
    {
        enQueue(qnp,data);
        scanf("%d", &data);
    }
    printf("\nDequeuing...\n\n");
    while( ! isEmpty(qnp))
    {
        printf("%d\n",deQueue(qnp));
    }
}
