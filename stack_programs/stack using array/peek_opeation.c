#include<stdio.h>
#define MAX 3


int top = -1;
int st[MAX];


// function prototypes
void display(int st[]);
void push(int st[], int val);
int peek(int st[]);


// displaying the elements of the list
void display(int st[]) {
    int i;
    if (top == -1) {
        printf("\nThe STACK is Empty!!!\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("%d\n", st[i]);
        }
    }
}
// PUSH Operation
void push(int st[], int val) {
    if (top == MAX - 1) {
        printf("\nSTACK is Full!!!\n");
    } else {
        top++;
        st[top] = val;
    }
}


// PEEK Opeation
int peek(int st[]) {
    if (top == -1) {
        printf("\nStack is empty\n");
        return -1;
    } else {
        return st[top];
    }
}


// main function
void main() {
    int val;
    int i;

    // inserting elements in the array
    for (i = 0; i < 2; i++) {
        printf("Enter the element to inserted >> ");
        scanf("%d", &val);
        push(st, val);
    }
    display(st);

    printf("\nThe top most element is: %d\n", peek(st));
}