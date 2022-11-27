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

int depthOfTree(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int lDepth = depthOfTree(root->left);
        int rDepth = depthOfTree(root->right);
        if (lDepth > rDepth)
        {
            return (lDepth + 1);
        }
        else
        {
            return (rDepth + 1);
        }
    }
}

int getLeafCount(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return getLeafCount(root->left) + getLeafCount(root->right);
    }
}

int nonLeafCount(struct node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    }
    return 1 + nonLeafCount(root->left) + nonLeafCount(root->right);
}

void checkBST(struct node *root, int *f)
{
    if ((*f) == 1 || root == NULL)
    {
        return;
    }
    else if (root->right != NULL && root->data > root->right->data)
    {
        *f = 1;
    }
    else if (root->left != NULL && root->data < root->left->data)
    {
        *f = 1;
    }
    checkBST(root->left, f);
    checkBST(root->right, f);
}

void main()
{
    struct node *root = NULL;
    int c;
MENU:
    printf("\n\nEnter your choice: \n 0. EXIT\n 1. Create \n 2. Inorder \n 3. Preorder\n 4. Postorder\n 5. Depth of Tree\n 6. Count leaf nodes\n 7. Count non leaf nodes\n 8. Check BST\n");
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
    case 5:
        if (!checkEmpty(root))
        {
            int depth = depthOfTree(root);
            printf("Deapth of tree is: %d", depth);
        }
        else
        {
            printf("Empty");
        }
        goto MENU;
    case 6:
        if (!checkEmpty(root))
        {
            int count = getLeafCount(root);
            printf("No. of leaf nodes are: %d", count);
        }
        else
        {
            printf("Empty");
        }
        goto MENU;
    case 7:
        if (!checkEmpty(root))
        {
            int count = nonLeafCount(root);
            printf("No. of non leaf nodes are: %d", count);
        }
        else
        {
            printf("Empty");
        }
        goto MENU;
    case 8:
        if (!checkEmpty(root))
        {
            int f = 0;
            checkBST(root, &f);
            if (f == 1)
            {
                printf("Not BST");
            }
            else
            {
                printf("BST");
            }
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