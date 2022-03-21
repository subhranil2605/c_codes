/*  Assignment 2 
    Sorting - Bubble Sort, Selection Sort, Insertion Sort
*/ 


/* ------------ Subhranil Sarkar ------------ */ 
/* ------------ M.Sc. Data Science 1st Semester ------------ */ 
/* ------------ University of Kalyani ------------ */ 
/* ------------ 22nd March, 2022 ------------ */ 


#include<stdio.h>


/* ------------ Function Prototypes  ------------ */ 
void swap(int *a, int *b);
void displayArray(int arr[], int n);


/* ------------ Functions  ------------ */ 

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



/* ------------ Main Function  ------------ */ 
void main() {
    int i, j, n, choice;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements of the array\n\n", n);
    
    for (i = 0; i < n; i++) {
        printf("Enter %d-th element: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nThe Given Array is: \n");
    displayArray(a, n);

    printf("\n\n========== Sorting Array ==========\n");
    printf("Press 1: Bubble Sort\n");
    printf("Press 2: Selection Sort\n");
    printf("Press 3: Insertion Sort");
    printf("\n====================\n");
    printf("Enter your choice >> ");
    scanf("%d", &choice);


    switch (choice) {
        case 1:
            bubbleSort(a, n);
            break;
        case 2:
            selectionSort(a, n);
            break;
        case 3:
            insertionSort(a, n);
            break;
        
        default:
            printf("Incorrect Choice!!!\n");
            break;
    }


    printf("\nAfter sorting the list is:\n");
    displayArray(a, n);

}