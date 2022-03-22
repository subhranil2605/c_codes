#include<stdio.h>
#define MAX 3       // max amount of elements can be stored into the list


int top = -1;
int st[MAX];

// function prototypes
void display(int st[]);
void push(int st[], int val);


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


void main() {
    int val;
    display(st);

    printf("Enter the data to inserted >> ");
    scanf("%d", &val);

    push(st, val);

    display(st);
}