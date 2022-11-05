#include <stdio.h>
int main()
{
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    int f = 0;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            f = 1;
            index = i;
        }
    }
    if (f == 0)
    {
        printf("NOT FOUND!!!");
    }
    else
    {
        printf("Found at index %d", index);
    } 
    return 0;
}