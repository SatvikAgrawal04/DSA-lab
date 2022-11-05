#include <stdio.h>
int main()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int temp[n];
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]%2 == 0)
        {
            temp[c] = arr[i];
            c++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i]%2 != 0)
        {
            temp[c] = arr[i];
            c++;
        }
    }
    
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
    
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}