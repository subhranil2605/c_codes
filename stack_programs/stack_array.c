#include<stdio.h>
#include<stdlib.h>

int top = -1;


// function prototypes
void display(int st[]);
void push(int st[], int val, int MAX);
int pop(int st[]);
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
void push(int st[], int val, int MAX) {
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
    int choice, val, max, i = 0;

    printf("Enter the amount of elements to be inserted in the stack >> ");
    scanf("%d", &max);
    int st[max];

    while (1) {
        printf("\n====================================================\n");
        printf("Press 1: PUSH\n");
        printf("Press 2: POP\n");
        printf("Press 3: PEEK\n");
        printf("Press 4: Display\n");
        printf("Press 5: Exit");
        printf("\n====================================================\n");
        printf("\nEnter Your Choice >> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n(%d/%d)", i + 1, max);
                printf("\nEnter the number to be pushed on stack >> ");
                scanf("%d", &val);
                push(st, val, max);
                i++;
                break;
            case 2:
                val = pop(st);
                if (val != -1) {
                    printf("\nThe deleted data from the stack is: %d", val);
                }
                break;
            case 3:
                val = peek(st);
                if (val != -1) {
                    printf("\nThe top most element is: %d", val);
                }
                break;
            case 4:
                printf("\nCurrent Stack is\n");
                display(st);
                break;
            case 5:
                exit(1);
        }
    }
}
