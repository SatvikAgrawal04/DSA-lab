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

void printReverse(struct Node *Head, int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    struct Node *tmp;
    int i;
    for (tmp = Head, i = 0; tmp != NULL, i < n; tmp = tmp->link, i++)
    {
        arr[i] = tmp->data;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    create(n);

    printReverse(head, n);

    return 0;
}