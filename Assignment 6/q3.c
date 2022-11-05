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

void traverse_fwd()
{
    struct node *tmp;
    for (tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%d ", tmp->data);
    }
}
void traverse_bwd()
{
    struct node *tmp;
    for (tmp = last; tmp != NULL; tmp = tmp->before)
    {
        printf("%d ", tmp->data);
    }
}
void checkEmpty()
{
    head == NULL ? printf("Empty") : printf("Not empty");
}
void insertAtIndex(int data, int index, int size)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    if (index == 0)
    {
        tmp->data = data;
        tmp->next = head;
        head->before = tmp;
        tmp->before = NULL;
        head = tmp;
    }
    else if (index == size)
    {
        struct node *p = head;
        int i = 0;
        while (i < size)
        {
            p = p->next;
            i++;
        }
        tmp->data = data;
        p->next = tmp;
        tmp->before = p;
        tmp->next = NULL;
    }

    else
    {
        struct node *p = head;
        int i = 0;
        while (i != (index - 1))
        {
            p = p->next;
            i++;
        }
        tmp->data = data;
        tmp->next = p->next;
        p->next->before = tmp;
        tmp->before = p;
        p->next = tmp;
    }
}
void delInBet(int index)
{
    if (index == 0)
    {
        struct node *tmp = head;
        head = head->next;
        free(tmp);
        head->before = NULL;
    }
    else
    {
        struct node *tmp = head;
        struct node *p;
        int i = 0;
        while (i < (index - 1))
        {
            tmp = tmp->next;
            i++;
        }
        p = tmp->next;
        tmp->next = p->next;
        p->next->before = tmp;
        free(p);
    }
}
void delForKey(int key)
{
    struct node *tmp = head;
    struct node *p;
    while (tmp->data != key)
    {
        p = tmp;
        tmp = tmp->next;
    }
    p->next = tmp->next;
    tmp->next->before = p;
    free(tmp);
}
int count()
{
    int c = 1;
    struct node *tmp;
    for (tmp = head; tmp->next != NULL; tmp = tmp->next)
        c++;
    printf("No. of nodes are: %d", c);
}
int search(int a)
{
    struct node *tmp;
    int f = 0;
    for (tmp = head; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->data == a)
            f = 1;
    }
    f == 0 ? printf("Not found") : printf("Found");
}

int main()
{
    head = NULL;
    int n, c;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    create(n);
MENU:
    printf("Enter your choice\n0. Traverse forward\n1. Traverse backward\n2. Check if list is empty\n3. Insert node\n4. Delete node\n5. Delete node for a given key\n6. Count total no. of nodes\n7. Search for an element\n8. EXIT\n");
    scanf("%d", &c);
    switch (c)
    {
    case 0:
        traverse_fwd();
        goto MENU;
    case 1:
        traverse_bwd();
        goto MENU;
    case 2:
        checkEmpty();
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
            insertAtIndex(x, 1, n);
            traverse_fwd();
        }
        else if (a == 2)
        {
            printf("Enter element you want to insert: ");
            scanf("%d", &x);
            insertAtIndex(x, n, n);
            traverse_fwd();
        }
        else
        {
            printf("Enter element you want to insert: ");
            scanf("%d", &x);
            printf("Enter Index: ");
            scanf("%d", &i);
            insertAtIndex(x, i, n);
            traverse_fwd();
        }
        goto MENU;
    case 4:
        printf("Enter where you want to Delete\n1. Begining\n2. End\n3. Any position\n");
        scanf("%d", &a);
        if (a == 1)
        {
            i = 1;
            delInBet(i);
            traverse_fwd();
        }
        else if (a == 2)
        {
            i = n - 1;
            delInBet(i);
            traverse_fwd();
        }
        else if (a == 3)
        {
            printf("Enter Index: ");
            scanf("%d", &i);
            delInBet(i);
            traverse_fwd();
        }
        else
        {
        }
        goto MENU;
    case 5:
        printf("Enter key: ");
        int key;
        scanf("%d", &key);
        delForKey(key);
        traverse_fwd;
        goto MENU;
    case 6:
        count();
        goto MENU;
    case 7:
        printf("Enter element you want to search: ");
        scanf("%d", &a);
        search(a);
        goto MENU;
    case 8:
        break;
    default:
        printf("Wrong INPUT");
        goto MENU;
    }
    return 0;
}