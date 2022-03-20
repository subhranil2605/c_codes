#include<stdio.h>


void main() {
    int i, n, search, flag = 0, count = 0;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int a[n];

    printf("\nEnter the elements\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++) {
        (a[i] == search) ? flag = 1 : flag = 0;
        count++;
    } 

    (flag == 1) 
    ? printf("The element is in the array at %d\n", count) 
    : printf("The element is not in the array!\n")
}