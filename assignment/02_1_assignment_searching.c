/*  Assignment 2 
    Searching - Linear Search, Binary Search
*/ 


/* ------------ Subhranil Sarkar ------------ */ 
/* ------------ M.Sc. Data Science 1st Semester ------------ */ 
/* ------------ University of Kalyani ------------ */ 
/* ------------ 22nd March, 2022 ------------ */ 



#include<stdio.h>


/* --------------- Function Prototypes ---------------*/ 
void swap(int *a, int *b);
void bubbleSort(int arr[], int n);
void displayArray(int arr[], int n);
void linearSearch(int a[], int n, int search);
int binarySearchIterative(int arr[], int left, int right, int search);
int binarySearchRecursive(int arr[], int left, int right, int search);
void menuBinarySearch(int a[], int n, int search);



/* --------------- Functions ---------------*/ 

// swap function
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
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

// display elements
void displayArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// linear search
void linearSearch(int a[], int n, int search) {
    int i, flag = 0, pos = 0;


    for (i = 0; i < n; i++) {
        if (a[i] == search) {
            flag = 1;
            pos = i;
        } 
    } 

    (flag == 1) 
    ? printf("The element %d is in the array at %d\n", search, pos) 
    : printf("The element %d is not in the array!\n", search);
}


// binary search iterative function
int binarySearchIterative(int arr[], int left, int right, int search) {
    int middle;
    while (left <= right) {
        middle = left + (right - left) / 2;

        if (arr[middle] == search) {
            return middle;
        } else if (arr[middle] < search) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}


// binary search recursive function
int binarySearchRecursive(int arr[], int left, int right, int search) {
    int middle;
    while (left <= right) {
        middle = left + (right - left) / 2;

        if (arr[middle] == search) {
            return middle;
        } else if (arr[middle] < search) {
            // the element is in the right part
            return binarySearchRecursive(arr, middle + 1, right, search);
        } else {
            // the element is in left part
            return binarySearchRecursive(arr, left, middle - 1, search);
        }
    }
    return -1;
}


// menu for choosing binary search method
void menuBinarySearch(int a[], int n, int search) {
    int choice, pos;

    printf("\nFor Binary Search, we need to sort the array\n");
    bubbleSort(a, n);
    displayArray(a, n);

    printf("\n\n====== Binary Search Type Choose Menu =======\n");
    printf("Press 1: Using Iterative function\n");
    printf("Press 2: Using Recursive function");
    printf("\n=============\n");
    printf("Enter your choice >> ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            pos = binarySearchIterative(a, 0, n-1, search);
            break;
        case 2:
            pos = binarySearchRecursive(a, 0, n-1, search);
            break;
        
        default:
            printf("\nIncorrect choice!!!\n");
            break;
    }

    (pos != -1) 
    ? printf("The element %d is found at %d\n", search, pos) 
    : printf("The element %d is not found!\n", search);
}




/* --------------- Main Function ---------------*/ 
void main() {
    int i, n, search;
    int choice; 

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int a[n];

    printf("\nEnter the %d elements\n", n);
    for (i = 0; i < n; i++) {
        printf("%d-th element is: ", i);
        scanf("%d", &a[i]);
    }


    printf("\nEnter the element to be searched: ");
    scanf("%d", &search);

    printf("\n\n======== Searching ========\n");
    printf("Press 1: Linear Search\n");
    printf("Press 2: Binary Search");
    printf("\n================\n");
    printf("Enter your choice >> ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            linearSearch(a, n, search);
            break;
        case 2:
            menuBinarySearch(a, n, search);
            break;
        
        default:
            printf("Incorrect Choice\n");
            break;
    }

}