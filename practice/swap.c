#include<stdio.h>


void swap(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


void main() {
    int a = 5, b = 7;
    printf("The value of a: %d and the value of b: %d\n", a, b);
    swap(&a, &b);
    printf("The value of a: %d and the value of b: %d\n", a, b);

}