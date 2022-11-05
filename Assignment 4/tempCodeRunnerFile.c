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