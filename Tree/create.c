#include<stdio.h>
#include<stdlib.h>
int r = -1, f = -1;
void enqueue(struct Node *x, int n, int q[])
{
    if (r == -1)
    {
        r = 0;
    }
    if ((r + 1) % n == f)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        r = (r + 1) % n;
        q[r] = x;
    }
    if (f == -1)
        f = 0;
}
int dequeue(int n, int q[])
{
    if (f == r)
    {
        printf("Underflow\n");
        r = -1;
        return 0;
    }
    else
    {
        f = (f + 1) % n;
        int x = q[f];
        return x;
    }
}
int isEmpty(int q[])
{
    if (r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *root;
void create()
{
    int n;
    printf("Enter size of queue: ");
    scanf("%d", &n);
    int *q[n];
    struct Node *p, *t;
    int x;
    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(root, n, q);
    while (!isEmpty(q))
    {
        p = dequeue(n, q);
        printf("Enter left child of %d (-1 if not present): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(t, n, q);
        }
        printf("Enter right child of %d (-1 if not present): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(t, n, q);
        }
    }
}

int main(int argc, char const *argv[])
{
    create();
    return 0;
}
