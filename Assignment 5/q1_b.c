// 210516667 Parth Bansal
//  Menu driven program of Circular linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
struct node *last;

void create(int n)
{
    struct node *new1, *new2;
    int i = 0;
    while (i < n)
    {
        if (head == NULL)
        {
            new1 = (struct node *)malloc(sizeof(struct node));
            printf("Enter element 1 ");
            scanf("%d", &new1->data);
            new1->link = NULL;
            head = new1;
        }
        else
        {
            printf("Enter element %d: ", i + 1);
            new2 = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &new2->data);
            new1->link = new2;
            new2->link = head;
            new1 = new2;
        }
        last = new2;
        i++;
    }
}

// Traversal (Menu 1)
void display()
{
    struct node *temp;
    printf("\nThe Linked List is ");
    temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != head);

    printf("\n");
}

// Menu 2 Check if List is Empty
void checkEmpty()
{
    if (head == NULL)
        printf("Empty.");
    else
        printf("Not Empty.");
}

// Menu 3 Insertion
void insert()
{
    int c;
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    // struct node *temp = (struct node *)malloc(sizeof(struct node));

    printf("\nMenu\n1: Insertion at Beginning.\n2: Insertion at end.\n3: Insertion at any position.\n");
    scanf("%d", &c);
    // Input
    printf("Enter value: ");
    scanf("%d", &newn->data);
    switch (c)
    {
    case 1: // Beginning
        if (head == NULL)
        {
            head = newn;
            newn->link = NULL;
            last = newn;
            last->link = head;
        }
        else
        {
            newn->link = head;
            head = newn;
            last->link = head;
        }
        break;

    case 2: // End
        if (head == NULL)
        {
            head = newn;
            newn->link = NULL;
        }
        else
        {
            for (temp = head; temp->link != head; temp = temp->link)
                ;
            temp->link = newn;
            newn->link = head;
            last = newn;
        }
        break;

    case 3: // Any Position
        printf("Enter Position: ");
        int pos;
        scanf("%d", &pos);
        if (head == NULL)
        {
            head = newn;
            newn->link = NULL;
        }
        else
        {
            int i;
            for (i = 1, temp = head; i < pos - 1; temp = temp->link, i++)
                ;
            newn->link = temp->link;
            temp->link = newn;
        }
        break;
    }
    display();
}

// Menu 4 Delete node
void delete ()
{
    struct node *temp;
    int c;
    if (head == NULL)
    {
        printf("List is Empty, Deletion not possible");
        return;
    }
    printf("\nMenu\n1: Beginning.\n2: End.\n3: any position.\n");
    scanf("%d", &c);

    switch (c)
    {
    case 1: // Beginning
        temp = head;
        head = head->link;
        free(temp);
        last->link = head;
        break;

    case 2: // End
        if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            for (temp = head; temp->link->link != head; temp = temp->link)
                ;
            free(temp->link);
            temp->link = head;
        }
        break;

    case 3: // Any Position
        printf("Enter Position: ");
        int pos;
        scanf("%d", &pos);
        if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            int i;
            for (i = 1, temp = head; i < pos - 1; temp = temp->link, i++)
                ;
            struct node *ptr;
            ptr = temp->link;
            temp->link = temp->link->link;
            free(ptr);
        }
        break;
    }
    display();
}
int search(int key)
{
    struct node *temp = head;
    do
    {
        if (temp->data == key)
        {
            printf("Element found.");
            return 1;
        }
        temp = temp->link;
    } while (temp != head);
    printf("Element not found.");
    return 0;
}

// Menu 5 Delete node for a given key
void del_key_a4()
{
    printf("Enter Key: ");
    int key;
    scanf("%d", &key);
    struct node *temp;
    temp = head;
    if (search(key))
    {
        do
        {
            temp = temp->link;
        } while (temp != head);
        struct node *p1;
        p1 = temp->link;
        temp->link = temp->link->link;
        free(p1);
        printf("Key Found.\n");
        display();
    }
    else
        printf("Key not found.");
}

// Menu 6 Count no of nodes
void count_a4()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int c = 0;
    for (temp = head; temp->link != head; temp = temp->link)
        c++;
    c++;
    printf("No of nodes is %d", c);
}

// Menu 7 Search for an element

int main()
{
    head = NULL;
    int n;
    printf("Enter no of nodes you want to create: ");
    scanf("%d", &n);

    create(n);
MENU:
    printf("\nMenu\n1: Traversal\n2: Check if list is empty.\n3: Insertion.\n4: Deletion at a position.\n");
    printf("5: Deletion for a key.\n6: Count no of nodes.\n7: Search for an element.\n0:EXIT\n");
    printf("Enter your choice: ");
    int c;

    scanf("%d", &c);
    switch (c)
    {
    case 0:
        break;
    case 1:
        display();
        goto MENU;

    case 2:
        checkEmpty();
        goto MENU;

    case 3:
        insert();
        goto MENU;

    case 4:
        delete ();
        goto MENU;

    case 5:
        del_key_a4();
        goto MENU;

    case 6:
        count_a4();
        goto MENU;

    case 7:
        printf("Enter no to search: ");
        int key;
        scanf("%d", &key);
        search(key);
        goto MENU;

    default:
        printf("Enter a valid value.");
        goto MENU;
    }
    return 0;
}