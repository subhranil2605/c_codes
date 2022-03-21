/*
Insertion Sorting
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


// insert sort
void insertionSort(int arr[], int n) {
    int i, j;

    i = 0;
    while (i < n) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
        i++;
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


    printf("Insertion Sort ");

    insertionSort(a, n);
    displayArray(a, n);


}