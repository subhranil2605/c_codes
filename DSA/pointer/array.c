#include<stdio.h>


int length(int *arr) {
    int size;
    size = sizeof(arr);
    return size;
}


void main() {
    int x[5];
    int i, n;

    for (i = 0; i < 4; i++) {
        printf("x[%d] = %p\n", i, &x[i]);
    }

    // printf("x = %p\n", x);
    // n = sizeof(x) / sizeof(*x);

    printf("%d\n", length(&x));
}