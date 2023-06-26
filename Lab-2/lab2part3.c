#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void readInput(int arr[], int *nPtr); // You can use same from Part I

void printNumbers(const int arr[], int n); // You can use same from Part I


void findLoosers(const int arr[], int n, int loosersArr[], int *sp)
{
	// Your code goes here...
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
