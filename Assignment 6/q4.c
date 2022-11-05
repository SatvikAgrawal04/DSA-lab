#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *before;
    int data;
    struct node *next;
} * head, *last;
void create(int n)
{
    int num;
    struct node *tmp;
    printf("Enter data: ");
    for (int i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            head = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &num);
            head->before = NULL;
            head->data = num;
            head->next = NULL;
            tmp = head;
            last = head;
        }
        else
        {
            struct node *new;

            new = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &num);
            tmp->next = new;
            new->data = num;
            new->before = tmp;
            new->next = NULL;
            tmp = new;
            last = tmp;
        }
    }
}

void traversal()
{
    struct node *tmp;
    printf("\n");
    for (tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%d ", tmp->data);
    }
}

void remDuplicate()
{
    struct node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == tmp->next->data && tmp->next != NULL)
        {
            struct node *d = tmp->next;
            tmp->next->before = tmp;
            tmp->next = tmp->next->next;
            free(d);
        }
        tmp = tmp->next;
    }
}

int main()
{
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    create(n);
    traversal();
    remDuplicate();
    traversal();
    return 0;
}