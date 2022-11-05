#include <stdio.h>
void linearSearch(int x, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            printf("Found");
            return;
        }
    }
    printf("Not found");
    return;
}
int main()
{
    int n, c;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &c);
    linearSearch(c, a, n);
    return 0;
}