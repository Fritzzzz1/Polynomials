#include "main.h"

void main() {
    int option = welcomeMenu();

    if (!option)
        printf(MENU_ERROR_FAIL);
}
