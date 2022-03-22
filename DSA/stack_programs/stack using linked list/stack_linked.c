#include<stdio.h>
#include<stdlib.h>

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
int peek(node top);
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


// PUSH Operation
node push(node head, int val) {
    node newNode;
    newNode = createNode();
    newNode -> data = val;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
    return head;
}


// POP Operation
node pop(node top) {
    node ptr;
    ptr = top;
    
    if (top == NULL) {
        printf("\nThe STACK is empty");
    } else {
        top = top -> next;
        printf("\nThe deleted item is: %d", ptr -> data);
        free(ptr);
    }
    return top;
}


// PEEK Opeation
int peek(node top){
    if (top == NULL) {
        printf("\nThe STACK is empty\n");
        return -1;
    } else {
        return top -> data;
    }   
}


// main function 
void main() {
    int choice, val;
    node top = NULL;

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
                printf("\nEnter the number to be pushed on stack >> ");
                scanf("%d", &val);
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                val = peek(top);
                if (val != -1) {
                    printf("\nThe top most element is: %d", val);
                }
                break;
            case 4:
                printf("\nCurrent Stack is\n");
                diplayStack(top);
                break;
            case 5:
                exit(1);
        }
    }
}
