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

void preOrder(struct node *root)
{
    if(root == NULL)
        return;
    printf(" %d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    printf(" %d ", root->data);
    inOrder(root->right);
}

void postOrder(struct node *root)
{
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d ", root->data);
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

struct node *search(struct node *root, int item)
{
    if(root == NULL || root->data == item)
        return root;
    if(item < root->data)
        return search(root->left, item);
    else if(item > root->data)
        return search(root->right, item);
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

struct node *del(struct node *root, int item)
{
    if(root == NULL)
        return root;

    else if(item < root->data)
        root->left = del(root->left, item);

    else if(item > root->data)
        root->right = del(root->right, item);

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
        root->right = del(root->right, temp->data);
    }
    return root;
}

void del_all(struct node *root)
{
    if(root != NULL)
    {
        del_all(root->left);
        del_all(root->right);
        free(root);
    }
}

int main()
{
    struct node *root = NULL;
    int n;
    scanf("%d", &n);
    root = insert(root,n);

    while(n > 0)
    {
        insert(root,n);
        scanf("%d", &n);
    }
    printf("Pre Order Traverse \n");
    preOrder(root);
    printf("\nIn Order Traverse \n");
    inOrder(root);
    printf("\nPost Order Traverse \n");
    postOrder(root);

    int item;
    printf("\n\nItem You Want to Search = ");
    scanf("%d", &item);
    struct node *loc;
    loc = search(root,item);
    if(loc == NULL)
        printf("item not Found.\n");
    else
        printf("item found.\n");

    printf("\nDelete 30\n");
    root = del(root,30);
    printf("\nInOrder Traversal of the Modified Tree \n");
    inOrder(root);

    del_all(root);
    printf("\nDelete all root.\n");
}
