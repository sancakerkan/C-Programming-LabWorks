#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void countNegNonneg(const int arr[], int n, int *negCountPtr, int *nonnegCountPtr);
void readInput(int arr[], int *nPtr);
void printNumbers(const int arr[], int n);

int main() {
    int arr[SIZE];
    int n, neg = 0, nonneg = 0;

    readInput(arr, &n);
    printNumbers(arr, n);

    countNegNonneg(arr, n, &neg, &nonneg);
    printf("Count of Non-negative elements = %d\n", nonneg);
    printf("Count of Negative elements = %d\n", neg);

    return 0;
}

void readInput(int arr[], int *nPtr) {
    printf("Enter the number of elements: ");
    scanf("%d", nPtr);
    printf("Enter %d elements: ", *nPtr);
    for (int i = 0; i < *nPtr; i++) {
        scanf("%d", &arr[i]);
    }
}

void printNumbers(const int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void countNegNonneg(const int arr[], int n, int *negCountPtr, int *nonnegCountPtr) {
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            (*negCountPtr)++;
        } else {
            (*nonnegCountPtr)++;
        }
    }
}