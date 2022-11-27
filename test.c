#include <stdio.h>
#include <stdlib.h>

struct node
{
    int d1;
    struct node *next;
};

void swap(struct node **a, struct node **b)
{
    struct node *tmp = *a;
    *a = *b;
    *b = tmp;
};

void create(struct node **head)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    *head = tmp;
    printf("Enter no. of nodes: ");
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter value of node %d: ", i + 1);
        scanf("%d", &val);
        tmp->d1 = val;
        tmp->next = NULL;
        if (i <= n - 1)
        {
            tmp->next = (struct node *)malloc(sizeof(struct node));
            tmp = tmp->next;
        }
    }
}

void display(struct node *head)
{
    for (struct node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%d", tmp->d1);
    }
}

int main()
{
    struct node *head;
    create(&head);
    display(head);
}