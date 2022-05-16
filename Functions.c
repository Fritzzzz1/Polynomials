#include "main.h"

Monom* getPolynom(unsigned int* size)
{
    Monom *newPoly, *tempPoly;
    char *tempStr;
    unsigned int tempStrSize = 0;

    // Get input string and size, check for input errors.
    tempStrSize = getPolynomString(&tempStr);
    if (tempStrSize == -1)
        return NULL;

    //Create temp array before summing of equal powers and removal of zeroed coefficients:
    tempPoly = convertStringToPoly(tempStr, &tempStrSize);
    if (tempPoly == NULL)
        return NULL;

    free(tempStr);

    //Sort high to low (selection)
    sortByCoeff(tempPoly, tempStrSize);

    //Then combine equal powers into newPoly
    newPoly = createPoly(tempPoly, tempStrSize, size);

    free(tempPoly);

    return newPoly;
}

unsigned int getPolynomString(char** dest)
{
    char ch;
    unsigned int phySize = 2, logSize = 0;

    char *tempStr = (char*) calloc(phySize, sizeof(char));

    while ((ch = getchar()) != '\n')
    {
        //Scan for illegal inputs
        if ((ch < '0' || ch > '9') && ch != ' ')
            return -1;

        tempStr[logSize] = ch;
        logSize++;
        if ((logSize >= phySize))
        {
            phySize *= 2;
            tempStr = (char*) realloc(tempStr, phySize* sizeof(char));
        }
    }
    tempStr[logSize++] = '\0';
    tempStr = (char*) realloc(tempStr, logSize);
    *dest = tempStr;

    return logSize;
}

Monom* convertStringToPoly(char* inputString, unsigned int* pointerToSize)
{
    unsigned int phySize = 1, logSize = 0, lenOfScan, countScanned, strSize = strlen(inputString);
    char* scanFrom = inputString, *endOfString = inputString+strSize;

    Monom* poly = (Monom*) malloc(phySize* sizeof(Monom));
    if (poly == NULL)
    {
        printf(ALLOC_ERROR_MSG, &poly);
        exit(1);
    }

    //as long as there is another pair of ints
    while ((countScanned = sscanf(scanFrom, "%d%d%n",
                                  &poly[logSize].coefficient, &poly[logSize].power,
                                  &lenOfScan)) == 2)
    {
        logSize++;
        scanFrom += lenOfScan;

        if ((logSize >= phySize) && (scanFrom < endOfString))
        {
            phySize *= 2;
            poly = (Monom*) realloc(poly, phySize* sizeof(Monom));
        }
    }
    if (countScanned == 1)
        return NULL;

    *pointerToSize = logSize;

    return poly;
}

void sortByCoeff(Monom* arr, unsigned int size)
{
    int i, j, maxIndex;

    for (i=0;i<size;i++)
    {
        maxIndex = i;

        for (j=i+1;j<size;j++)
            if (arr[j].power > arr[maxIndex].power)
                maxIndex = j;

        swapMonom(&arr[i], &arr[maxIndex]);
    }
}

Monom* createPoly(Monom* sourcePoly, unsigned int sourceSize, unsigned int* destSize)
{
    unsigned int newSize, j = 0;
    Monom* destPoly;

    //summing equal powers, removing zeroed coefficients, updating ordered size:
    newSize = combinePoly(sourcePoly, sourceSize);
    *destSize = newSize;

    destPoly = (Monom*) malloc((*destSize)* sizeof(Monom));
    if (destPoly == NULL)
    {
        printf(ALLOC_ERROR_MSG, &destPoly);
        exit(1);
    }

    while (j < newSize)
    {
        copyMonom(&destPoly[j], &sourcePoly[j]);
        j++;
    }

    return destPoly;
}

unsigned int combinePoly(Monom* poly, unsigned int size)
{
    int currentCoff = 0, currentPow;
    unsigned int newSize, i = 0, j = 0;

    while (i < size)
    {
        currentPow = poly[i].power;
        currentCoff += poly[i].coefficient;

        if (poly[i+1].power != currentPow)
        {
            if (currentCoff != 0)
            {
                poly[j].coefficient = currentCoff;
                poly[j++].power = currentPow;
                currentCoff = 0;
            }
        }
        i++;
    }
    newSize = j;

    return newSize;
}

void swapMonom(Monom* monA, Monom* monB)
{
    Monom temp = *monA;
    *monA = *monB;
    *monB = temp;
}

void copyMonom(Monom* monA, Monom* monB)
{
    monA->power = monB->power;
    monA->coefficient = monB->coefficient;
}

void printPoly(Monom* poly, unsigned int size)
{
    unsigned int i = 0;

    if (poly[i].coefficient == 1)
        printf("x^%d ", poly[i].power);
    else if (poly[i].coefficient == -1)
        printf("-x^%d ", poly[i].power);
    else
        printf("%dx^%d ", poly[i].coefficient, poly[i].power);

    for (i=1;i<size;i++)
    {
        if (poly[i].coefficient == -1)
            printf("- ");
        else if (poly[i].coefficient == 1)
            printf("+ ");
        else if (poly[i].coefficient < 0)
            printf("- %d", -poly[i].coefficient);
        else
            printf("+ %d", poly[i].coefficient);

        if (poly[i].power > 1)
            printf("x^%d ", poly[i].power);
        else if (poly[i].power == 1)
            printf("x ");
        else if (poly[i].power==0)
            printf(" ");
    }
    printf("\n");
}

void printPolySum(Monom* poly1, unsigned int size1, Monom* poly2, unsigned int size2)
{
    unsigned int i, j, tempSize = size1 + size2;

    Monom* tempPoly = (Monom*) malloc(tempSize* sizeof(Monom));
    if (tempPoly == NULL)
    {
        printf(ALLOC_ERROR_MSG, &tempPoly);
        exit(1);
    }

    for (i=0;i<size1;i++)
        copyMonom(&tempPoly[i], &poly1[i]);

    for (j=0;j<size2;j++)
        copyMonom(&tempPoly[i++], &poly2[j]);

    arrangeAndPrint(tempPoly, tempSize);

    free(tempPoly);
}

void printPolyMul(Monom* poly1, unsigned int size1, Monom* poly2, unsigned int size2)
{
    unsigned int i, j ,k=0, tempSize = size1*size2;

    Monom* tempPoly = (Monom*) malloc(tempSize* sizeof(Monom));
    if (tempPoly == NULL)
    {
        printf(ALLOC_ERROR_MSG, &tempPoly);
        exit(1);
    }

    for (i=0;i<size1;i++)
    {
        for (j=0;j<size2;j++)
        {
            tempPoly[k].power = poly1[i].power + poly2[j].power;
            tempPoly[k++].coefficient = poly1[i].coefficient * poly2[j].coefficient;
        }
    }
    arrangeAndPrint(tempPoly, tempSize);

    free(tempPoly);
}

void arrangeAndPrint(Monom* source, unsigned int sourceSize)
{
    unsigned int newSize;

    sortByCoeff(source, sourceSize);

    newSize = combinePoly(source, sourceSize);

    printPoly(source, newSize);
}

