#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
} * head;

void create(int n)
{
    struct Node *node, *tmp;
    int num;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->link = NULL;
    printf("Enter element 1: ");
    scanf("%d", &num);

    head->data = num;
    tmp = head;

    for (int i = 2; i <= n; i++)
    {
        node = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter element %d: ", i);
        scanf("%d", &num);

        node->data = num;
        node->link = NULL;

        tmp->link = node;
        tmp = tmp->link;
    }
}

int printM(struct Node *Head, int m, int n)
{
    struct Node *tmp;
    int a = n - m;
    int c = 0;
    for (tmp = Head; tmp != NULL; tmp = tmp->link)
    {
        if (c == a)
        {
            printf("%d", tmp->data);
        }
        c++;
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    create(n);
    printf("Enter Mth element: ");
    scanf("%d", &m);
    printM(head, m, n);

    return 0;
}