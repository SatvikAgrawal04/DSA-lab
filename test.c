#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
}; 

struct node* create()
{
    struct node *nw;
    nw = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter value (-1 for no value): ");
    scanf("%d", &x);
    if(x == -1)
        return 0;
    nw->data = x;
    printf("Enter left child of %d: ", x);
    nw->left = create();
    printf("Enter right child of %d: ", x);
    nw->right = create();
    return nw;
}

void main()
{
    struct node *root;
    root = create();
}