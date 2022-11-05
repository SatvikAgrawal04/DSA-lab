#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *ptr;
void add()
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value: ");
    scanf("%d", &new->data);
    new->next = head;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        ptr->next = new;
    }
    ptr = new;
}
void display()
{
    struct node *tmp = head;
    do
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    } while (tmp != head);
}

void search()
{
    struct node *t;
    int s;
    printf("\nEnter node to search: ");
    scanf("%d", &s);
    for (t = head; t != head; t = t->next)
    {
        if (s == t->data)
        {
            printf("\nNode found.\n");
            break;
        }
    }
    if (t == head)
        printf("\nNode not found.\n");
}
void ins(struct node *t)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert: ");
    scanf("%d", &new->data);
    if (t == head)
    {
        new->next = head;
        head = new;
        return;
    }
    if (t == ptr)
    {
        new->next = head;
        ptr->next = new;
        ptr = new;
        return;
    }
}
void insp()
{
    struct node *t, *new;
    int n1, i;
    printf("\nEnter the  position after you want to insert :\n");
    scanf("%d", &n1);
    new = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert: ");
    scanf("%d", &new->data);
    for (i = 1, t = head; t != head; t = t->next, i++)
    {
        if (i + 1 == n1)
        {
            new->next = t->next;
            t->next = new;
            return;
        }
    }
    if (t == head)
        printf("\nWrong input\n");
}
void insert()
{
    struct node *t, *new;
    int n1, i, n;
    printf("\n1)At first.\n2)At Last.\n3)At a given position.\nEnter your choice.\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        ins(head);
        break;
    case 2:
        ins(ptr);
        break;
    case 3:
        insp();
        break;
    }
    printf("\nNode inserted.\n");
}
void del(struct node *t)
{
    if (t == head)
    {
        head = head->next;
        free(t);
        return;
    }
    if (t == ptr)
    {
        for (t = head; t->next != ptr; t = t->next)
            ;
        ptr = t;
        t = t->next;
        ptr->next = head;
        free(t);
        return;
    }
}
void delp()
{
    struct node *t, *k;
    int n1, i;
    printf("\nEnter the  position after you want to delete :\n");
    scanf("%d", &n1);
    for (i = 1, t = head; t != head; t = t->next, i++)
    {
        if (i + 1 == n1)
        {
            k = t->next;
            t->next = k->next;
            free(k);
            return;
        }
    }
}
void delete ()
{
    struct node *t, *new;
    int n1, i, n;
    printf("\n1)At first.\n2)At Last.\n3)At a given position.\nEnter your choice.\n");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        del(head);
        break;
    case 2:
        del(ptr);
        break;
    case 3:
        delp();
        break;
    }
    printf("\nNode Deleted\n");
}
int count()
{
    int c = 0;
    struct node *tmp = head;
    if (tmp != NULL)
    {
        do
        {
            c++;
            tmp = tmp->next;
        } while (tmp != head);
    }

    printf("No of nodes are %d\n", c);
    return c;
}
void delForKey()
{
    int k;
    printf("Enter key: ");
    scanf("%d", &k);
    struct node *tmp = head, *p;
    do
    {
        p = tmp;
        tmp = tmp->next;

    } while (tmp->data != k);
    p->next = tmp->next;
    free(tmp);
}
void main()
{
    int n;
    head = NULL;
    do
    {
        printf("\n1)Add\n2)Display\n3)Count no. of nodes\n4)Search\n5)Insert\n6)Delete\n7)Delete for key\n8)Exit\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            count();
            break;
        case 4:
            search();
            break;
        case 5:
            insert();
            break;
        case 6:
            delete ();
            break;
        case 7:
            delForKey();
            break;
        }
    } while (n != 7);
}