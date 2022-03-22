#include<stdio.h>


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


// main function
void main() {
    int i, n, search, pos, choice;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int a[n];

    printf("\nEnter the %d elements in sorted order\n", n);
    for (i = 0; i < n; i++) {
        printf("%d-th element is: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &search);


    // Menu
    printf("\n====== Binary Search Type Choose Menu =======\n");
    printf("Press 1: Using Iterative function\n");
    printf("Press 2: Using Recursive function\n");
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