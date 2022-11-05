#include <stdio.h>

int stack[100], top, n;

void push()
{
    if (top >= n - 1)
        printf("\nOverflow");

    else
    {
        printf("\nEnter value to be pushed: ");
        int num;
        scanf("%d", &num);
        top++;
        stack[top] = num;
    }
}
void pop()
{
    if (top <= -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\n%d has been popped", stack[top]);
        stack[top] = 0;
        top--;
    }
}

void display()
{
    if (top <= -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("\n%d", stack[i]);
        }
    }
}

void checkEmpty()
{
    (top <= 0) ? printf("\nEmpty") : printf("\nNot Empty");
}

int main()
{
    top = -1;
    printf("\nEnter Size of stack [MAX:100]: ");
    scanf("%d", &n);
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
        display();
        goto MENU;
    case 4:
        checkEmpty();
        goto MENU;
    default:
        printf("INVALID INPUT");
        goto MENU;
    }
    return 0;
}