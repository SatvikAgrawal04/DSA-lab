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
    for (int i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            head = (struct node *)malloc(sizeof(struct node));
            printf("Enter data: ");
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
            printf("Enter data: ");
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
    for (tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%d ", tmp->data);
    }
}

int main()
{
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    create(n);
    traversal();
    return 0;
}