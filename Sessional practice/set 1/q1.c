#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff, pow;
    struct node *next;
} * headA, *headB, *headC;

struct node *create(struct node *head)
{
    if (head != NULL)
    {
        printf("Already created\n");
        return head;
    }
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter degree: ");
    int p, c;
    scanf("%d", &p);
    printf("Enter coeff of power %d: ", p);
    scanf("%d", &c);
    head->coeff = c;
    head->pow = p;
    head->next = NULL;
    struct node *tmp = head;
    for (int i = p - 1; i >= 0; i--)
    {
        struct node *nw;
        nw = (struct node *)malloc(sizeof(struct node));
        printf("Enter coeff of power %d: ", i);
        scanf("%d", &c);
        nw->coeff = c;
        nw->pow = i;
        nw->next = NULL;
        tmp->next = nw;
        tmp = tmp->next;
    }
    return head;
}

void add(struct node **res, struct node *head1, struct node *head2)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->next = NULL;
    *res = tmp;
    while (head1 && head2)
    {
        if (head1->pow > head2->pow)
        {
            tmp->coeff = head1->coeff;
            tmp->pow = head1->pow;
            head1 = head1->next;
        }
        else if (head1->pow < head2->pow)
        {
            tmp->coeff = head2->coeff;
            tmp->pow = head2->pow;
            head2 = head2->next;
        }
        else
        {
            tmp->coeff = head1->coeff + head2->coeff;
            tmp->pow = head1->pow;
            head1 = head1->next;
            head2 = head2->next;
        }
        if (head1 && head2)
        {
            tmp->next = (struct node *)malloc(sizeof(struct node));
            tmp = tmp->next;
            tmp->next = NULL;
        }
    }
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Does not exist\n");
        return;
    }
    struct node *tmp;
    for (tmp = head; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->pow == 0)
        {
            printf("%d", tmp->coeff);
        }
        else if (tmp->pow == 1)
        {
            printf("%dx + ", tmp->coeff);
        }

        else
            printf("%dx%d + ", tmp->coeff, tmp->pow);
    }
}

int main()
{
    headA = headB = headC = NULL;
    headA = create(headA);
    headB = create(headB);
    display(headA);
    printf("\n");
    display(headB);
    printf("\n");
    add(&headC, headA, headB);
    display(headC);
}