#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOC_ERROR_MSG "Memory allocation failed at %p"
#define MENU_ERROR_FAIL "You have failed to interact with the menu :)\n Please try again...\n"

typedef struct{
    int coefficient;
    int power;
}Monom;

int welcomeMenu();

Monom* getPolynom(unsigned int* size);
unsigned int getPolynomString(char** dest);
Monom* convertStringToPoly(char* inputString, unsigned int* pointerToSize);

void sortByCoeff(Monom* arr, unsigned int size);
Monom* createPoly(Monom* sourcePoly, unsigned int sourceSize, unsigned int* destSize);
unsigned int combinePoly(Monom* poly, unsigned int size);

void swapMonom(Monom* monA, Monom* monB);
void copyMonom(Monom* monA, Monom* monB);

void printPoly(Monom* poly, unsigned int size);
void printPolySum(Monom* poly1, unsigned int size1, Monom* poly2, unsigned int size2);
void printPolyMul(Monom* poly1, unsigned int size1, Monom* poly2, unsigned int size2);
void arrangeAndPrint(Monom* source, unsigned int sourceSize);

#endif /* MAIN_H */


