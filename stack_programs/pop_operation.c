#include<stdio.h>
#define MAX 3       // max amount of elements can be stored into the list


int top = -1;
int st[MAX];

// function prototypes
void display(int st[]);
void push(int st[], int val);
int pop(int st[]);


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


// POP Operation
int pop(int st[]) {
    int val;
    if (top == - 1) {
        printf("\nSTACK is Empty!!!\n");
        return -1;
    } else {
        val = st[top];
        top--;
        return val;
    }
}


void main() {
    int val;
    int i;

    // inserting elements in the array
    for (i = 0; i < MAX; i++) {
        printf("Enter the element to inserted >> ");
        scanf("%d", &val);
        push(st, val);
    }
    display(st);

    printf("Doing POP Operation...");
    val = pop(st);

    printf("\nThe deleted element is: %d\n", val);

    printf("\nAfter deleting the array is: \n");
    display(st);
}