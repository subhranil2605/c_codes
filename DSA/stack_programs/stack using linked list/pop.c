#include<stdio.h>
#include<stdlib.h>

// int top = -1;

// node structure
struct node {
    int data;
    struct node* next;
};

typedef struct node* node;


// Function prototypes
node createNode();
node push(node top, int val);
node pop(node top);
void diplayStack(node p);


// create a single node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));

    if (temp == NULL) {
        printf("Memory is not allocated for the new ndoe!!!");
        return NULL;
    } else {
        temp -> next = NULL;
        return temp;
    }
}


// PUSH operation
node push(node top, int val) {
    node newNode;
    newNode = createNode();
    newNode -> data = val;

    if (top == NULL) {
        top = newNode;
    } else {
        newNode -> next = top;
        top = newNode;
    }
    return top;
}


// POP operation
node pop(node top) {
    node ptr;
    ptr = top;
    
    if (top == NULL) {
        printf("The STACK is empty!!!");
    } else {
        top = top -> next;
        printf("\nThe deleted item is: %d\n", ptr -> data);
        free(ptr);
    }
    return top;
}


// display
void diplayStack(node p) {
    if (p == NULL) {
        printf("\nThe STACK is empty!");
    } else {
        while (1) {
            if (p != NULL) {
                printf("%d-->", p -> data);
            } else {
                printf("NULL\n");
                break;
            }
            p = p -> next;
        }
    }
}



void main() {
    node st = NULL;

    st = push(st, 5);
    st = push(st, 10);

    diplayStack(st);

    st = pop(st);
    diplayStack(st);
}