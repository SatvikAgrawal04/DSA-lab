#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create()
{
    struct node *nw;
    nw = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("\nEnter value(-1 for null): ");
    scanf("%d", &x);
    if (x == -1)
    {
        nw = NULL;
        return nw;
    }
    nw->data = x;
    printf("Enter left child of %d: ", x);
    nw->left = create();
    printf("Enter right child of %d: ", x);
    nw->right = create();
    return nw;
}
int checkEmpty(struct node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    return 0;
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void main()
{
    struct node *root = NULL;
    int c;
MENU:
    printf("\n\nEnter your choice: \n 1. Create \n 2. Inorder \n 3. Preorder\n 4. Postorder\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        if (checkEmpty(root))
        {
            root = create();
        }
        else
            printf("Already exists\n");
        goto MENU;
    case 2:
        if (!checkEmpty(root))
        {
            inorder(root);
        }
        else
        {
            printf("Empty");
        }
        goto MENU;
    case 3:
        if (!checkEmpty(root))
        {
            preorder(root);
        }
        else
        {
            printf("Empty");
        }
        goto MENU;
    case 4:
        if (!checkEmpty(root))
        {
            postorder(root);
        }
        else
        {
            printf("Empty");
        }
        goto MENU;
    default:
        break;
    }
}