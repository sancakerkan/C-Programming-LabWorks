#include <stdio.h>
#include <math.h>

void findClosestPoint(double *length, double *closestX, double *closestY)
{
 //Complete here
}

int main()
{
    double length, closestX, closestY;

    findClosestPoint(&length, &closestX, &closestY);

    printf("length of line from point to origin %.2f\n", length);
    printf("Closest Point X: %.2f\n", closestX);
    printf("Closest Point Y %.2f\n", closestY);

    return 0;
}
