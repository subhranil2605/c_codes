/*  Assignment 8 
    Stack using doubly linked List
*/ 


/* ------------ Subhranil Sarkar ------------ */ 
/* ------------ M.Sc. Data Science 1st Semester ------------ */ 
/* ------------ University of Kalyani ------------ */ 
/* ------------ 20th March, 2022 ------------ */ 


#include<stdio.h>
#include<stdlib.h>


// doubly node structure
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node* node;


/* ------------- Function Prototypes ------------- */ 
node createNode();
void display(node );
node push(node );
node pop(node );
void peek(node );
node mainMenu(node );

/* ------------- Functions ------------- */ 

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
void peek(node top) {
    (top == NULL) 
       ? printf("\nThe STACK is empty\n")
       : printf("\nThe topmost element is: %d\n", top -> data); 
}



/* ------------- Menus ------------- */ 
node mainMenu(node stack) {
    int choice;

    while (1) {
        printf("\n============ Queue Using Doubly Linked List ==============\n");
        printf("Press 1: PUSH\n");
        printf("Press 2: POP\n");
        printf("Press 3: Peek\n");
        printf("Press 4: Display\n");
        printf("Press 5: Exit\n");
        printf("\n=============================\n");
        printf("Enter your choice >> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nInserting into the Stack...\n");
                printf("\nThe current stack is\n");
                display(stack);
                stack = enQueue(stack);
                printf("\nThe stack is now\n");
                display(stack);
                break;
            case 2:
                printf("\nDeleting from the Stack...\n");
                printf("\nThe current stack is\n");
                display(stack);
                stack = deQueue(stack);
                printf("\nThe stack is now\n");
                display(stack);
                break;
            case 3:
                printf("\nPeeking...\n");
                peek(stack);
                break;
            case 4:
                printf("\nDisplaying...\n");
                display(stack);
                break;
            case 5:
                exit(1);
            
            default:
                printf("\nIncorrect choice!!!\n");
                break;
        }
    }

    return stack;
} 


/* ------------- Main function ------------- */ 

void main() {
    node stack;

    stack = NULL;

    stack = mainMenu(stack);
}