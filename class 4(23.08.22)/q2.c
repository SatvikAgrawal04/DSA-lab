#include <stdio.h>
#include <stdlib.h>
struct addpoly
{
    int ob;
    int ob2;
    int sum;
};

int main()
{
    int n;
    printf("Enter the highest order of polynomial : ");
    scanf("%d", &n);

    struct addpoly *ptr;
    ptr = (struct addpoly *)malloc(n * sizeof(struct addpoly));

    printf("Enter the h(x)\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of %c : ", i + 65);
        scanf("%d", &(ptr + i)->ob);
    }

    printf("Enter the g(x)\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of %c : ", i + 65);
        scanf("%d", &(ptr + i)->ob2);
    }

    for (int i = 0; i < n; i++)
    {
        (ptr + i)->sum = 0;
        (ptr + i)->sum += (ptr + i)->ob + (ptr + i)->ob2;
    }
    
    for (int i = n, j = 0; i > 0, j < n; i--, j++)
    {
        printf("%dX%d +", (ptr + j)->sum, i);
    }
    return 0;
}