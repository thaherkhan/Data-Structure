#include<stdio.h>

struct node
{
    int data;
    struct node *prev;
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

void DeletingData(struct node *HeadRef, int key)
{
    struct node *ptr = HeadRef, *LastNode;
    //When Key is in Head.
    if((ptr!=NULL) && (ptr->data==key))
    {
        *HeadRef = *HeadRef->next;
         HeadRef->prev = NULL;
        free(key);
        printf("Data %d is Delete.\n",key);
        return;
    }
    while(ptr->data!=key)
    {
        LastNode = ptr;
        ptr = ptr->next;
    }
    if(ptr==NULL)
    {
        printf("Key Not Found.\n");
        return;
    }
    else
    {
        struct node *after = LastNode->next;
        struct node *before = LastNode->prev;
        free(ptr);
        before->next = after;
        after->prev = before;
        //printf("Data %d is Delete.\n");
        return;
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
    struct node *n1 = makeNode(10);
    struct node *n2 = makeNode(20);
    struct node *n3 = makeNode(30);
    struct node *n4 = makeNode(40);
    struct node *Head = n1;

    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;
    DubbleTraverse(Head);
    DeletingData(n3,30);
    printf("\n\nTraversing....\n");
    DubbleTraverse(Head);
}
