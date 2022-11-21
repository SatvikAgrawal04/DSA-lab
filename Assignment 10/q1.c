#include <stdio.h>
#include <stdlib.h>

struct node101
{
    int data;
    struct node101 *left, *right;
} * root101;

struct node101 *newNode101(int num)
{
    struct node101 *nw = (struct node101 *)malloc(sizeof(struct node101));
    nw->data = num;
    nw->left = nw->right = NULL;
    return nw;
}

struct node101 *insert101(struct node101 *tmp, int key)
{
    if (tmp == NULL)
    {
        return newNode101(key);
    }
    if (key < tmp->data)
    {
        tmp->left = insert101(tmp->left, key);
    }
    else
    {
        tmp->right = insert101(tmp->right, key);
    }
}

void inorder101(struct node101 *root101)
{
    if (root101 == NULL)
    {
        return;
    }
    inorder101(root101->left);
    printf("%d ", root101->data);
    inorder101(root101->right);
}

void preorder101(struct node101 *root101)
{
    if (root101 == NULL)
    {
        return;
    }
    printf("%d ", root101->data);
    preorder101(root101->left);
    preorder101(root101->right);
}

void postorder101(struct node101 *root101)
{
    if (root101 == NULL)
    {
        return;
    }
    postorder101(root101->left);
    postorder101(root101->right);
    printf("%d ", root101->data);
}

struct node101 *search101(struct node101 *root101, int key)
{
    if (root101->data == key || root101 == NULL)
    {
        return root101;
    }
    else
    {
        if (key < root101->data)
        {
            return search101(root101->left, key);
        }
        else
        {
            return search101(root101->right, key);
        }
    }
}

void smallest101(struct node101 *root101)
{
    while (root101 != NULL && root101->left != NULL)
    {
        root101 = root101->left;
    }
    printf("\nSmallest value is %d\n", root101->data);
}
void largest101(struct node101 *root101)
{
    while (root101 != NULL && root101->right != NULL)
    {
        root101 = root101->right;
    }
    printf("\nlargest value is %d\n", root101->data);
}

int main10_1()
{
    struct node101 *tmp;
    int key;
    root101 = NULL;
    int c;
MENU:
    printf("\n\nBinary Search Tree Menu\n0. Quit\n1. Create\n2. In-Order Traversal\n3. Pre-Order Traversal\n4. Post-Order traversal\n5. Search\n6. Find Smallest Element\n7. Find Largest Element\n8. Deletion of Tree\nEnter your choice:");
    scanf("%d", &c);

    switch (c)
    {
    case 0:
        break;

    case 1:
        printf("Enter no. of nodes: ");
        int n, x;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("Enter Data: ");
            scanf("%d", &x);
            root101 = insert101(root101, x);
        }
        goto MENU;
    case 2:
        inorder101(root101);
        goto MENU;

    case 3:
        preorder101(root101);
        goto MENU;
    case 4:
        postorder101(root101);
        goto MENU;
    case 5:
        printf("Enter no. you want to search101: ");
        scanf("%d", &key);
        tmp = search101(root101, key);
        if (tmp == NULL)
        {
            printf("Not found");
        }
        else
        {
            printf("found");
        }
        goto MENU;
    case 6:
        smallest101(root101);
        goto MENU;
    case 7:
        largest101(root101);
        goto MENU;
    }

    return 0;
}