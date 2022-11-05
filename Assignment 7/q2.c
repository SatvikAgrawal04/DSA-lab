#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} * head, *top;

void push()
{
    int num;
    printf("Enter value: ");
    scanf("%d", &num);
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = num;
        head->next = NULL;
        top = head;
    }
    else
    {
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        top->next = new;
        new->data = num;
        new->next = NULL;
        top = new;
    }
}

void pop()
{
    struct Node *tmp, *p;
    for (tmp = head; tmp->next != top; tmp = tmp->next)
        ;
    p = top;
    top = tmp;
    free(p);
}
void display(struct Node *tmp)
{
    if (head == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        tmp = head;
        }
}
void checkEmpty()
{
    head == NULL ? printf("Empty") : printf("Not empty");
}
int main()
{
    head = NULL;
MENU:
    printf("\nEnter your choice\n0.Exit\n1.Push\n2.Pop\n3.Display\n4.Check if Empty\n");
    int c;
    scanf("%d", &c);
    switch (c)
    {
    case 0:
        break;
    case 1:
        push();
        goto MENU;
    case 2:
        pop();
        goto MENU;
    case 3:
        // display();
        goto MENU;
    case 4:
        // checkEmpty();
        goto MENU;
    default:
        printf("INVALID INPUT");
        goto MENU;
    }
    return 0;
}