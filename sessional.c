#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node *next;
};

void create(struct node **head)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter degree: ");
    int p;
    scanf("%d", &p);
    tmp->pow = p;
    printf("Enter coeff of power %d ", p);
    int val;
    scanf("%d", &val);
    tmp->coeff = val;
    tmp->next = NULL;
    *head = tmp;
    for (int i = p - 1; i >= 0; i--)
    {
        struct node *nw = (struct node *)malloc(sizeof(struct node));
        printf("Enter value of power %d ", i);
        scanf("%d", &val);
        nw->coeff = val;
        nw->pow = i;
        nw->next = NULL;
        tmp->next = nw;
        tmp = tmp->next;
    }
}

void display(struct node *head)
{
    struct node *tmp;
    for (tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%dx%d + ", tmp->coeff, tmp->pow);
    }
}

void multiply(struct node **res, struct node *head1, struct node *head2)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    *res = tmp;
    struct node *tmp1 = head1;
    struct node *tmp2 = head2;
    while (tmp1 || tmp2)
    {
        for (tmp1 = head1; tmp1 != NULL; tmp1 = tmp1->next)
        {
            tmp->coeff = tmp1->coeff * tmp2->coeff;
            tmp->pow = tmp1->pow + tmp2->pow;
            tmp->next = NULL;
            if (tmp1 && tmp2)
            {
                tmp->next = (struct node *)malloc(sizeof(struct node));
                tmp = tmp->next;
            }
        }
        tmp2 = tmp2->next;
    }
}

int main()
{
    struct node *head1, *head2, *res;
    head1 = head2 = res = NULL;
    create(&head1);
    printf("\n");
    display(head1);
    printf("\n");
    create(&head2);
    printf("\n");
    display(head2);
    printf("\n");
    multiply(&res, head1, head2);
    printf("\n");
    display(res);
}