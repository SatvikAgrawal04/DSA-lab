#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a = 56;
    int *r = &a;
    printf("%d\n", r);
    int *q[10];
    q[0] = r;
    printf("%d", q[0]);
    return 0;
}
