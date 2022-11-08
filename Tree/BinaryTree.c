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
    printf("Enter root value: ");
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
    struct node *root;
    root = create();

   printf("preorder is: ");
   preorder(root); 

   printf("\nInorder is: ");
   inorder(root);

   printf("\nPosorder is: ");
   postorder(root);
}