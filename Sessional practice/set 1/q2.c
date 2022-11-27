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
void sortInsert(struct node **head, int x)
{
    if (isEmpty(*head) || x < top(*head))
    {
        push(head, x);
        return;
    }
    int tmp = pop(head);
    sortInsert(head, x);
    push(head, tmp);
}
void sortStack(struct node **head)
{
    if (!isEmpty(*head))
    {
        int x = pop(head);
        sortStack(head);
        sortInsert(head, x);
    }
    else
    {
        return;
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
    // pop(&head);
    sortStack(&head);
    display(head);
    return 0;
}