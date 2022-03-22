/*
Selection Sorting
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


// selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex;
    int swapped = 0; // 0 -> false & 1 -> true
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // displayArray(arr, n);
        swap(&arr[minIndex], &arr[i]);
        // printf("\n");
    }
}


// main function
void main() {
    int i, j, n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements of the array\n", n);
    
    for (i = 0; i < n; i++) {
        printf("Enter %d-th element: ", i);
        scanf("%d", &a[i]);
    }


    printf("Selection Sort ");

    selectionSort(a, n);
    displayArray(a, n);
}