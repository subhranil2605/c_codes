#include<stdio.h>



int binarySearch(int arr[], int left, int right, int search) {
    int middle;
    while (left <= right) {
        middle = l + (r - l) / 2;

        if (arr[middle] = search) {
            return middle;
        } else if (arr[middle] < search) {
            l = middle + 1;
        } else {
            r = middle - 1;
        }
    }
    return -1;
}


void main() {
    int i, n;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int a[n];

    printf("\nEnter the %d elements in sorted order\n", n);
    for (i = 0; i < n; i++) {
        printf("%d-th element is: ");
        scanf("%d", &a[i]);
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &search);
    
} 