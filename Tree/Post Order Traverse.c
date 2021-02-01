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

void postOrderTraverse(struct node *temp)
{
    if(temp == NULL)
        return;

    postOrderTraverse(temp->left);
    postOrderTraverse(temp->right);

    printf("%d ", temp->data);
}

int main()
{
    struct node *root = newNode(1);
    //root->left        = newNode(2);
    root->right       = newNode(2);
    root->right->right  = newNode(5);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(6);
    root->right->right->left->right = newNode(4);

    printf("Post Order Traverse of Binary Tree...\n");
    postOrderTraverse(root);

    //getchar();
    return 0;
}
