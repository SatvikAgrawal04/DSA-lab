#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * f, *r;

void enqueue(int x)
{
    if (f == NULL)
    {
        struct node *nw = (struct node *)malloc(sizeof(struct node));
        nw->data = x;
        nw->next = NULL;
        f = nw;
        r = nw;
    }
    else
    {
        struct node *nw = (struct node *)malloc(sizeof(struct node));
        nw->data = x;
        nw->next = NULL;
        r->next = nw;
        r = nw;
    }
}
void dequeue()
{
    struct node *tmp = f;
    f = f->next;
    printf("%d has been dequeued", tmp->data);
    free(tmp);
}
void display()
{
    struct node *tmp;
    for (tmp = f; tmp != NULL; tmp = tmp->next)
    {
        printf("%d ", tmp->data);
    }
}
void peek()
{
    printf("%d", f->data);
}
void isEmpty()
{
    f == NULL ? printf("Empty") : printf("Not Empty");
}

int main()
{
    f = NULL;
    r = NULL;
    int c, x;
MENU:
    printf("\n\nEnter Your choice\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.isEmpty\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        printf("Enter element: ");
        scanf("%d", &x);
        enqueue(x);
        goto MENU;
    case 2:
        dequeue();
        goto MENU;
    case 3:
        peek();
        goto MENU;
    case 4:
        display();
        goto MENU;
    case 5:
        isEmpty();
        goto MENU;
    }
    return 0;
}
