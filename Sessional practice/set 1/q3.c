#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head, int val)
{
    if (*head == NULL)
    {
        struct node *tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = val;
        tmp->next = NULL;
        *head = tmp;
        return;
    }
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = val;
    tmp->next = *head;
    *head = tmp;
}
int pop(struct node **head)
{
    struct node *tmp = *head;
    *head = tmp->next;
    int data = tmp->data;
    free(tmp);
    // printf("\n%d popped\n", data);
    return data;
}
void display(struct node *head)
{
    int c = 0;
    if (head == NULL)
    {
        printf("Empty");
        return;
    }
    for (struct node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%d\n", tmp->data);
    }
}
int isEmpty(struct node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int top(struct node *head)
{
    return head->data;
}
int count(struct node *head)
{
    int c = 0;
    for (struct node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        c++;
    }
    return c;
}
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
int main()
{
    struct node *head = NULL;
    push(&head, 5);
    push(&head, 12);
    push(&head, 9);
    push(&head, 11);
    push(&head, 6);
    push(&head, 10);
    push(&head, 7);

    int n = count(head);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = pop(&head);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    bubbleSort(a, n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", a[i]);
    }
    return 0;
}