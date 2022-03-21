/*
Bubble Sorting
*/


#include<stdio.h>

// swap function
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// display elements
void displayArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped = 0; // 0 -> false & 1 -> true
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1; 
            }
        }

        if (swapped == 0) {
            break;
        }
    }
}


// main function
void main() {
    int i, j, n, swapped = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements of the array\n", n);
    
    for (i = 0; i < n; i++) {
        printf("Enter %d-th element: ", i);
        scanf("%d", &a[i]);
    }


    printf("Bubble Sort");

    bubbleSort(a, n);
    displayArray(a, n);


}