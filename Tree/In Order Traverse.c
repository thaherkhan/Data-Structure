#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inOrderTraverse(struct node *temp)
{
    if(temp == NULL)
        return;

    inOrderTraverse(temp->left);

    printf("%d ", temp->data);

    inOrderTraverse(temp->right);
}

int main()
{
    int num;
    struct node *root =NULL;
    scanf("%d",&num);
    root= newNode(num);
    while(num!=0)
    {

        scanf("%d",&num);
       newNode(num);
    }
/*    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);*/

    inOrderTraverse(root);

    //getchar();
    return;
}
