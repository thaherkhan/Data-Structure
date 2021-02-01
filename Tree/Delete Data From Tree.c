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
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void printData(struct node *root)
{
    if(root == NULL)
        return;
    printData(root->left);
    printf("%d ", root->data);
    printData(root->right);
}

struct node *insert(struct node *root, int item)
{
    if(root == NULL)
        return newNode(item);

    else if(item < root->data)
        root->left = insert(root->left, item);

    else if(item > root->data)
        root->right = insert(root->right, item);

    return root;
}

struct node *minval(struct node *item)
{
    struct node *current = item;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node *delt(struct node *root, int item)
{
    if(root == NULL)
        return root;

    else if(item < root->data)
        root->left = delt(root->left, item);

    else if(item > root->data)
        root->right = delt(root->right, item);
    else
    {
        if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minval(root->right);
        root->data = temp->data;
        root->right = delt(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    int n;
    scanf("%d", &n);
    root = insert(root,n);
    while(n!=0)
    {
        insert(root,n);
        scanf("%d",&n);
    }
    printData(root);
    int item;
    printf("\n\nEnter The Which Delete = ");
    scanf("%d", &item);
    root = delt(root,item);
    printf("\n\nAfter Delete, The Modified Tree...\n");
    printData(root);

}
