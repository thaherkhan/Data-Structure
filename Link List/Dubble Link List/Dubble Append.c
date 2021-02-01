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

void append(struct node **HeadRef, int item)
{
    struct node *temp = makeNode(item);
    //When Head is Empty.
    if(*HeadRef==NULL)
        *HeadRef = temp;
    else
    {
        struct node *ptr = *HeadRef, *LastNode;
        while(ptr!=NULL)
        {
            LastNode = ptr;
            ptr = ptr->next;
        }
        temp->prev = LastNode;
        LastNode->next = temp;
    }
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
        append(&Head,number);
        scanf("%d",&number);
    }
    printf("\n\nTraversing....\n");
    DubbleTraverse(Head);
}
