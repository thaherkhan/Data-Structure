#include<stdio.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *makeNode(int item)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->prev = NULL;
    p->data = item;
    p->next = NULL;
    return p;
}

void push(struct node **HeadRef, int item)
{
    struct node *temp = makeNode(item);
    temp->prev = NULL;
    temp->data = item;
    temp->next = *HeadRef;
    *HeadRef = temp;
}

void DubbleTraverse(struct node *Head)
{
    struct node *ptr = Head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *Head = NULL;
    int number;
    scanf("%d",&number);
    while(number!=0)
    {
        push(&Head,number);
        scanf("%d",&number);
    }
    printf("\n\nTraversing....\n");
    DubbleTraverse(Head);
}
