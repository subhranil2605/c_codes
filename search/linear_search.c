#include<stdio.h>


void main() {
    int i, n, search, flag = 0, pos = 0;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int a[n];

    printf("\nEnter the %d elements\n", n);
    for (i = 0; i < n; i++) {
        printf("%d-th element is: ");
        scanf("%d", &a[i]);
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &search);

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