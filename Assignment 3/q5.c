#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[20];
    char grade;
};

int main(int argc, char const *argv[])
{

    int n;
    struct student *stud;
    printf("Enter the no. of students: \n");
    scanf("%d", &n);
    stud = (struct student *)malloc(n * sizeof(struct student));

    for (int i = 0; i < n; i++)
    {
        printf("Enter details of student %d:\n", i + 1);
        printf("Enter roll: ");
        scanf("%d", &(stud + i)->roll);
        printf("Enter name: ");
        getchar();
        scanf("%[^\n]s", (stud + i)->name);
        printf("Enter grade: ");
        getchar();
        scanf("%c", &(stud + i)->grade);
        printf("\n\n");
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%s\t%c", (stud + i)->roll, (stud + i)->name, (stud + i)->grade);
    }

    return 0;
}