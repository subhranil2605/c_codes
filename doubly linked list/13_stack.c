#include<stdio.h>
#include<stdlib.h>


// doubly node structure
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node* node;


// create a single node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));

    if (temp == NULL) {
        printf("Memory is not allocated for the new ndoe!!!");
        return NULL;
    } else {
        temp -> next = NULL;
        temp -> prev = NULL;
        return temp;
    }
}


// display
void display(node top) {
    if (top == NULL) {
        printf("\nThe Stack is empty!!!\n");
    } else {
        printf("NULL");
        while (top != NULL) {
            printf("<--%d-->", top -> data);
            top = top -> next;
        }
        printf("NULL");
    }
}



// PUSH operation
node push(node top) {
    int val;
    node newNode;

    newNode = createNode();
    printf("\nEnter the data to be pushed in the list >> ");
    scanf("%d", &val);
    newNode -> data = val;

    if (top == NULL) {
        top = newNode;
    } else {
        newNode -> next = top;
        top -> prev = newNode;
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
        if (top != NULL) {
            top -> prev = NULL;
        }
        printf("\nThe deleted item is: %d\n", ptr -> data);
        free(ptr);
    }
    return top;
}


// Peek operation
void peek(node top){
    (top == NULL) 
       ? printf("\nThe STACK is empty\n")
       : printf("\nThe topmost element is: %d\n", top -> data); 
}




// main function

void main() {
    node stack;

    stack = NULL;

    stack = push(stack);
    stack = push(stack);

    display(stack);

    // stack = pop(stack);
    // stack = pop(stack);
    // display(stack);

    peek(stack);

}