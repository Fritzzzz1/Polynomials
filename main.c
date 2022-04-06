#include "Menu_Functions.h"

void main() {
    int option = welcomeMenu();

    if (!option)
        printf(MENU_ERROR_FAIL);
}