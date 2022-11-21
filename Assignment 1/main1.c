#include "q1.c"
#include "q2.c"
#include "q3.c"
#include "q4.c"
#include "q5.c"
#include "q6.c"
#include "q7.c"
#include "q8.c"
#include "q9.c"
#include "q10.c"
#include "q11.c"
#include "q12.c"
#include "q13.c"

int main1()
{
    int c;
MENU:
    printf("\n\nEnter your choice:\n0. Back\n1. q1\n2. q2\n3. q3\n4. q4\n5. q5\n6. q6\n7. q7\n8. q8\n9. q9\n10. q10\n11. q11\n12. q12\n13. q13\n");
    scanf("%d", &c);
    switch (c)
    {
    case 0:
        break;
    case 1:
        main1_1();
        goto MENU;
    case 2:
        main1_2();
        goto MENU;
    case 3:
        main1_3();
        goto MENU;
    case 4:
        main1_4();
        goto MENU;
    case 5:
        main1_5();
        goto MENU;
    case 6:
        main1_6();
        goto MENU;
    case 7:
        main1_7();
        goto MENU;
    case 8:
        main1_8();
        goto MENU;
    case 9:
        main1_9();
        goto MENU;
    case 10:
        main1_10();
        goto MENU;
    case 11:
        main1_11();
        goto MENU;
    case 12:
        main1_12();
        goto MENU;
    case 13:
        main1_13();
        goto MENU;
    }
    return 0;
}