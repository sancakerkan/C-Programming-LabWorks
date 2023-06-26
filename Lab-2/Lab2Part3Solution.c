#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void readInput(int arr[], int *nPtr); 

void printNumbers(const int arr[], int n); 


void findLoosers(const int arr[], int n, int loosersArr[], int *sp)
{
    int i, j, flag;
    loosersArr[0] = arr[0];
    *sp = 1;

    for (i = 1; i < n; i++) {
        flag = 0;
        for (j = i-1; j >= 0; j--) {
            if (arr[i] >= arr[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            loosersArr[*sp] = arr[i];
            (*sp)++;
        }
    }
}

int main() {
    int arr[SIZE];
    int n;
    int loosersArr[SIZE];
    int s=0;
    readInput(arr, &n);
    printNumbers(arr, n);
    findLoosers(arr, n, loosersArr, &s);
    printf("Loosers ");
    printNumbers(loosersArr, s);

    return 0;
}

void readInput(int arr[], int *nPtr) {
    printf("Enter the number of elements:\n");
    scanf("%d", nPtr);
    printf("Enter %d elements:\n", *nPtr);
    for (int i = 0; i < *nPtr; i++) {
        scanf("%d", &arr[i]);
    }
}

void printNumbers(const int arr[], int n) {
    printf("Array elements:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}