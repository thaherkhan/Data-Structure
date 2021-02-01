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

void InsertAfterNode(struct node *prevNode, int item)
{
   //When PreNode is Empty.
   if(prevNode==NULL)
   {
       printf("Fazlami Koro.\n");
       return;
   }
   struct node *temp = makeNode(item);
   struct node *temp2 = prevNode->next;
   prevNode->next = temp;
   temp->prev = prevNode;
   temp->next = temp2;
   temp2->prev = temp;
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
    struct node *n1 = makeNode(10);
    struct node *n2 = makeNode(20);
    struct node *n3 = makeNode(30);
    Head = n1;
    struct node *temp;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    InsertAfterNode(n1,40);
    printf("\n\nTraversing....\n");
    DubbleTraverse(Head);
}
