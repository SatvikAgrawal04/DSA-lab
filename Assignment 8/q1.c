#include <stdio.h>
int r = -1, f = -1;
// int q[10];
void enqueue(int x, int n, int q[])
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
        return;
    }
    else
    {
        f = (f + 1) % n;
        printf("%d has been dequeued", q[f]);
        q[f] = 0;
    }
}
void peek(int q[])
{
    printf("%d", q[f + 1]);
}
void display(int q[])
{
    int a = f + 1, b = r;
    for (; a <= b; a++)
    {
        printf("%d ", q[a]);
    }
    printf("\n");
}
void isEmpty(int q[])
{
    r == -1 ? printf("Queue empty") : printf("Not Empty");
}
void isFull(int q[], int n)
{
    if ((r + 1) % n == f)
    {
        printf("FULL");
    }
    else
    {
        printf("Not full");
    }
}
int main()
{
    int c, x, n = 10, a;
    printf("Enter size of queue: ");
    scanf("%d", &a);
    n = a + 1;
    int q[n];
MENU:
    printf("\n\nEnter Your choice\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.isEmpty\n6.isFull\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        printf("Enter element: ");
        scanf("%d", &x);
        enqueue(x, n, q);
        goto MENU;
    case 2:
        dequeue(n, q);
        goto MENU;
    case 3:
        peek(q);
        goto MENU;
    case 4:
        display(q);
        goto MENU;
    case 5:
        isEmpty(q);
        goto MENU;
    case 6:
        isFull(q, n);
        goto MENU;
    }
    return 0;
}