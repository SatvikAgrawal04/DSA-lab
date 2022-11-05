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
void traversal(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    for (; ptr != NULL; ptr = ptr->link)
        printf("%d ", ptr->data);
}
int checkIfEmpty(struct Node *Head)
{
    if (Head->link == NULL)
        return 0;
    else
        return 1;
}
struct Node *insertAtIndex(struct Node *Head, int data, int index)
{
    if (index == 1)
    {
        struct Node *tmp;
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = data;
        tmp->link = head;
        return tmp;
    }
    else
    {
        struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
        struct Node *p = Head;
        int i = 0;
        while (i != (index - 1))
        {
            p = p->link;
            i++;
        }
        tmp->data = data;
        tmp->link = p->link;
        p->link = tmp;
        return Head;
    }
}
struct Node *delInBet(struct Node *Head, int index)
{
    if (index == 1)
    {
        struct Node *tmp = Head;
        Head = Head->link;
        free(tmp);
        return Head;
    }
    else
    {
        struct Node *tmp = Head;
        struct Node *p;
        int i = 0;
        while (i < (index - 1))
        {
            tmp = tmp->link;
            i++;
        }
        p = tmp->link;
        tmp->link = p->link;
        free(p);
        return Head;
    }
}
struct Node *delForKey(struct Node *Head, int key)
{
    struct Node *tmp = Head;
    struct Node *p;
    while (tmp->data != key)
    {
        p = tmp;
        tmp = tmp->link;
    }
    p->link = tmp->link;
    free(tmp);
    return Head;
}
int count(struct Node *Head)
{
    int c = 1;
    struct Node *tmp;
    for (tmp = Head; tmp->link != NULL; tmp = tmp->link)
        c++;
    return c;
}
int search(struct Node *Head, int a)
{
    struct Node *tmp;
    for (tmp = Head; tmp != NULL; tmp = tmp->link)
    {
        if (tmp->data == a)
            return 1;
    }
    return 0;
}
int main()
{
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    create(n);
    int c;
    int b;
MENU:
    printf("\n-------------------------------------------\n");
    printf("Enter your choice\n1. Traverse list\n2. Check if list is empty\n3. Insert node\n4. Delete node\n5. Delete node for a given key\n6. Count total no. of nodes\n7. Search for an element\n0. EXIT\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        traversal(head);
        goto MENU;
    case 2:
        if (checkIfEmpty(head))
            printf("Not Empty");
        else
            printf("Empty");
        goto MENU;
    case 3:
        printf("Enter where you want to insert\n1. Begining\n2. End\n3. Any position\n");
        int a;
        scanf("%d", &a);
        int x;
        int i;
        if (a == 1)
        {
            printf("Enter element you want to insert: ");
            scanf("%d", &x);
            head = insertAtIndex(head, x, 1);
        }
        else if (a == 2)
        {
            printf("Enter element you want to insert: ");
            scanf("%d", &x);
            head = insertAtIndex(head, x, count(head));
        }
        else
        {
            printf("Enter element you want to insert: ");
            scanf("%d", &x);
            printf("Enter Index: ");
            scanf("%d", &i);
            head = insertAtIndex(head, x, i);
        }
        goto MENU;
    case 4:
        printf("Enter where you want to Delete\n1. Begining\n2. End\n3. Any position\n");
        scanf("%d", &a);
        if (a == 1)
        {
            i = 1;
            head = delInBet(head, i);
        }
        else if (a == 2)
        {
            i = count(head) - 1;
            head = delInBet(head, i);
        }
        else if (a == 3)
        {
            printf("Enter Index: ");
            scanf("%d", &i);
            head = delInBet(head, i);
        }
        else
        {
        }
        goto MENU;
    case 5:
        printf("Enter key: ");
        int key;
        scanf("%d", &key);
        head = delForKey(head, key);
        goto MENU;
    case 6:
        b = count(head);
        printf("No of nodes are: %d", b);
        goto MENU;
    case 7:
        printf("Enter element you want to search: ");
        scanf("%d", &a);
        if (search(head, a))
            printf("\nFOUND");
        else
            printf("\nNOT FOUND");
        goto MENU;
    case 0:
        break;
    default:
        printf("Wrong INPUT");
        goto MENU;
    }
    return 0;
}