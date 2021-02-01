#include<stdio.h>

struct stackNode
{
    int data;
    struct stackNode *next;
};

struct stackNode *makeStack(int item)
{
    struct stackNode *temp = (struct stackNode *)malloc(sizeof(struct stackNode));
    temp->data = item;
    temp->next = NULL;
    return temp;
}

void push(struct stackNode **HeadRef, int item)
{
    struct stackNode *temp = makeStack(item);
    temp->next = *HeadRef;
    *HeadRef = temp;
}

int isEmpty(struct stackNode *Head)
{
    return !Head;
}

int pop(struct stackNode **HeadRef)
{
    if(isEmpty(*HeadRef))
    {
        printf("Stack Underflow.\n");
        return;
    }
    struct stackNode *temp = *HeadRef;
    int item = temp->data;
    *HeadRef = (*HeadRef)->next;
    free(temp);
    return item;
}

int main()
{
    struct stack *stackHead = NULL;
    int data;
    scanf("%d", &data);
    while(data>0)
    {
        push(&stackHead, data);
        scanf("%d", &data);
    }
    printf("\n\nPopping...\n");
    while( ! isEmpty(stackHead) )
    {
        printf("%d\n", pop(&stackHead));
    }
}
