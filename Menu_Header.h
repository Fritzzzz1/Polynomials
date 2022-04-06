#define MENU_COMMAND_PRINT_ONE 1
#define MENU_COMMAND_SUM_TWO 2
#define MENU_COMMAND_MULTI_TWO 3

int welcomeMenu();
int printOnePoly();
int sumTwoPolys();
int multiTwoPolys();


const char* WELCOME = "\nWelcome to the polynomial interface >>> by Fritzzzz >>>\n\n"
"Here you can easily print, evaluate, and interact with polynomials.\n"
"Results are presented as a power of 'x', merged, and ordered from high to low.\n\n"
"*** Please note that both the coefficient and the power are designed to receive integer values, \n"
"and that powers are designed to be 0 or greater only. ***\n\n"
"To enter a polynomial, use a sequence of pairs of numbers representing coefficient and power.\n"
"For example: the input | 2 3 5 2 | will be presented as | 2x^3 + 5x^2 |.\n"
"*** Numbers should be separated by an empty space.\n";

const char* MENU_OPTIONS = "\nOPTIONS:\n"
                     "(1) - Display a polynomial\n"
                     "(2) - Display the sum of 2 polynomials\n"
                     "(3) - Display the multiplication of 2 polynomials\n\n"
                     "Please enter your choice:";

const char* MENU_REFRESH = "\nEnter 1 to go back to menu or 0 to exit \n";
const char* MENU_ERROR_FAIL = "You have failed to interact with the menu :)\n"
                        "Please try again...\n";

const char* MENU_ERROR_INTS_ONLY = "\n*** Please follow the instructions on how to enter a polynomial."
                         "\nonly numbers are allowed, and in an even amount ***\n";

const char* MENU_ERROR_CHOICE = "\n*** Menu options are simply 1, 2, or 3 ***\n";

const char* MENU_PROMPT_ENTER_POLY = "\nEnter data for polynomial:\n";
const char* MENU_PROMPT_ENTER_POLY1 = "\nEnter data for polynomial 1:\n";
const char* MENU_PROMPT_ENTER_POLY2 = "\nEnter data for polynomial 2:\n";
const char* MENU_DISPLAY_POLY = "The given polynomial combined is:\n";
const char* MENU_DISPLAY_SUM = "\nThe sum of the 2 given polynomials is:\n";
const char* MENU_DISPLAY_MULTI = "\nThe result of multiplication of the 2 given polynomials is:\n";