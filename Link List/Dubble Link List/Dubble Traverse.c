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
    struct node *n5 = makeNode(50);
    struct node *Head;
    Head = n1;
    //struct node *temp;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;
    DubbleTraverse(Head);
}
