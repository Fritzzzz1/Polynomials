#include "Menu.h"
#include "main.h"

int welcomeMenu()
{
    int choice = 0, running = 1;

    printf(WELCOME);

    while (running)
    {
        printf(MENU_OPTIONS);

        if (scanf("%d", &choice) == 1)
        {
            fflush(stdin);
            switch (choice)
            {
                case MENU_COMMAND_PRINT_ONE:
                    if (printOnePoly() == -1)
                        printf(MENU_ERROR_INTS_ONLY);
                    break;

                case MENU_COMMAND_SUM_TWO:
                    if (sumTwoPolys() == -1)
                        printf(MENU_ERROR_INTS_ONLY);
                    break;

                case MENU_COMMAND_MULTI_TWO:
                    if (multiTwoPolys() == -1)
                        printf(MENU_ERROR_INTS_ONLY);
                    break;

                default:
                    printf(MENU_ERROR_CHOICE);
                    break;
            }
        }
        else
            return 0;

        printf(MENU_REFRESH);

        fflush(stdin);
        scanf("%d", &running);
    }
    return 1;
}

int printOnePoly()
{
    Monom *poly;
    unsigned int size;

    printf(MENU_PROMPT_ENTER_POLY);

    poly = getPolynom(&size);
    if (poly == NULL)
        return -1;

    printf(MENU_DISPLAY_POLY);
    printPoly(poly, size);

    free(poly);

    return 0;
}

int sumTwoPolys()
{
    Monom *poly1, *poly2;
    unsigned int size1, size2;

    printf(MENU_PROMPT_ENTER_POLY1);

    poly1 = getPolynom(&size1);
    if (poly1 == NULL)
        return -1;

    printf(MENU_PROMPT_ENTER_POLY2);

    poly2 = getPolynom(&size2);
    if (poly2 == NULL)
        return -1;

    printf(MENU_DISPLAY_SUM);
    printPolySum(poly1, size1, poly2, size2);

    free(poly1);
    free(poly2);
    return 0;
}

int multiTwoPolys()
{
    Monom *poly1, *poly2;
    unsigned int size1, size2;

    printf(MENU_PROMPT_ENTER_POLY1);

    poly1 = getPolynom(&size1);
    if (poly1 == NULL)
        return -1;

    printf(MENU_PROMPT_ENTER_POLY2);

    poly2 = getPolynom(&size2);
    if (poly2 == NULL)
        return -1;

    printf(MENU_DISPLAY_MULTI);
    printPolyMul(poly1, size1, poly2, size2);

    free(poly1);
    free(poly2);
    return 0;
}
