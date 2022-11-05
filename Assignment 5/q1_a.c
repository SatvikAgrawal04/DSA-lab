// Test Qustion 2
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int d1;
    int d2;
    int pos;
    struct node *add;
};

struct node *head = NULL;

void create_a5(int n)
{
    struct node *N, *M;
    int i = 0;
    while (i < n)
    {
        if (head == NULL)
        {
            N = (struct node *)malloc(sizeof(struct node));
            printf("Enter the info of 1st Node: ");
            scanf("%d", &N->d1);
            scanf("%d", &N->d2);
            N->pos = i + 1;
            head = N;
            N->add = NULL;
        }
        else
        {
            printf("Enter info of %d node: ", i + 1);
            M = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &M->d1);
            scanf("%d", &M->d2);
            M->pos = i + 1;
            N->add = M;
            M->add = NULL;
            N = M;
        }
        i++;
    }
}

void swap()
{
    struct node *temp;
    for (temp = head; temp->add != NULL; temp = temp->add)
    {
        if (temp->d1 > temp->add->d1)
        {
            // Swapping i and i+1 node
        }
        else if (temp->d2 > temp->add->d2)
        {
            // swap i and i+1 node
        }
        else
            printf("node->%d -> ", &temp->pos);
    }
}