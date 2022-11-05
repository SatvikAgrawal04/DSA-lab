#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    int element, nge;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n\nELE\tNGE\n");
    for (int i = 0; i < n; i++)
    {
        element = a[i];
        for (int j = i; j < n; j++)
        {
            if (a[j] > a[i])
            {
                nge = a[j];
                break;
            }
            else
            {
                nge = -1;
            }
        }
        printf("%d\t%d\n", element, nge);
    }
    return 0;
}