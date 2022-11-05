#include <stdio.h>
int linearSearch(int x, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return 1;
        }
    }
    return 0;
}
int q3(int con[], int hunt, int n)
{
    while (linearSearch(hunt, con, n))
    {
        hunt = 3 * hunt;
    }
    return hunt;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter length of container: ");
    scanf("%d", &n);
    int con[n];
    printf("Enter Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &con[i]);
    }
    printf("Enter value of hunt: ");
    int hunt;
    scanf("%d", &hunt);
    int val = q3(con, hunt, 9);
    printf("%d", val);
    return 0;
}
