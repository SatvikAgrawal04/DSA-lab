#include <stdio.h>
#include <stdlib.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
    int i;
    if (l == r)
        printf("%s\n", a);
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i));
        }
    }
}

int main()
{
    char *str;
    printf("Enter your string length: ");
    int n;
    scanf("%d", &n);
    str = (char *)malloc(n * sizeof(char));
    printf("Enter a string: ");
    getchar();
    scanf("%[^\n]s", str);
    permute(str, 0, n - 1);
    return 0;
}