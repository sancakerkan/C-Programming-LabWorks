#include <stdio.h>
#include <math.h>

/*
pre-conditions
n is greater than 1 (n > 1)
maxVal is positive (maxVal > 0)
minVal is positive (minVal > 0)
maxVal is greater than or equal to minVal (maxVal >= minVal)
*/
void printPowersInRange(int n, int p, int count, int minVal, int maxVal)
{
    // your code comes here
}

int main()
{
    int number;
    int minVal, maxVal;

    printf("Enter number> ");
    scanf("%d", &number);
    printf("Enter minimum value> ");
    scanf("%d", &minVal);
    printf("Enter maximum value> ");
    scanf("%d", &maxVal);

    printPowersInRange(number, 0,0, minVal, maxVal);

    return 0;
}
