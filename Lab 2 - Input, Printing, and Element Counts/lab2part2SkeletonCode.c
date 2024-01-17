#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void readInput(int arr[], int *nPtr); // You can use same from Part I

void printNumbers(const int arr[], int n); // You can use same from Part I


void countNegNonneg(const int arr[], int n, int *negCountPtr, int *nonnegCountPtr)
{
  // Your code goes here...
}

int main() {
        int arr[SIZE];
        int n, neg=0, nonneg=0;

        readInput(arr, &n);
        printNumbers(arr, n);
		countNegNonneg(arr, n, &neg, &nonneg);
        printf("Count of Non-negative elements = %d\n", nonneg);
        printf("Count of Negative elements = %d\n", neg);

        return 0;
}
