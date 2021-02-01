#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *makeNode(int item)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}

void traverse(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

void push(struct node **headRef, int item)
{
    struct node *temp = makeNode(item);
    temp->next = *headRef;
    *headRef = temp;
}

void append(struct node **headRef, int item)
{
    struct node *temp = makeNode(item);

    //when head is null
    if(*headRef == NULL)
        *headRef = temp;
    else
    {
        struct node *ptr = *headRef, *lastNode;
        while(ptr != NULL)
        {
            lastNode = ptr;
            ptr = ptr->next;
        }
        lastNode->next = temp;
    }
}

void insertAfterNode(struct node *prevNode, int item)
{
    if(prevNode == NULL)
    {
        printf("Fazlami Koro!!!\n");
        return;
    }
    struct node *temp = makeNode(item);
    temp->next = prevNode->next;
    prevNode->next = temp;
}

void deleteData(struct node **headRef, int key)
{
    struct node *ptr = *headRef, *lastNode;
    //When key is in head node
    if(  (ptr != NULL) && (ptr->data == key) )  {
        *headRef = ptr->next;
         free(ptr);
         printf("Head Data %d is deleted.\n",key);
         return;
    }
    while( (ptr!=NULL) && (ptr->data != key) )  {
        lastNode = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL)  {
        printf("Key Not Found.\n");
    }
    else  {
        lastNode->next = ptr->next;
        free(ptr);
        printf("Data %d is deleted.\n",key);
    }
}

int main()
{
    struct node *head = NULL;
    struct node *n1 = makeNode(10);
    struct node *n2 = makeNode(20);
    struct node *n3 = makeNode(30);
    head = n1;
    n1->next = n2;
    n2->next = n3;

    //insertAfterNode(n2,400);
    //push(&head,200);
    //append(&head,300);
    //printf("\n\nTraversing...\n");
    //traverse(head);

    //deleteData(&head,10);
    printf("\n\nTraversing...\n");
    traverse(head);
}
