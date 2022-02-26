#include<stdio.h>
#include<stdlib.h>


int top = -1;


// node structure
struct node {
    int data;
    struct node* next;
};

typedef struct node* node;


// function prototypes

// stack using array 
void displayAr(int st[]);
void pushAr(int st[], int val, int MAX);
int popAr(int st[]);
int peekAr(int st[]);
void arrayMenu();

// stack using linked list 
node createNode();
node pushLi(node top, int val);
node popLi(node top);
int peekLi(node top);
void displayLi(node p);
void llMenu();


/* Stack using array functions */

// display
void displayAr(int st[]) {
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
void pushAr(int st[], int val, int MAX) {
    if (top == MAX - 1) {
        printf("\nSTACK is Full!!!\n");
    } else {
        top++;
        st[top] = val;
    }
}


// POP Operation
int popAr(int st[]) {
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
int peekAr(int st[]) {
    if (top == -1) {
        printf("\nStack is empty\n");
        return -1;
    } else {
        return st[top];
    }
}


/* Stack using linked list functions */

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
void displayLi(node p) {
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
node pushLi(node head, int val) {
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
node popLi(node top) {
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
int peekLi(node top){
    if (top == NULL) {
        printf("\nThe STACK is empty\n");
        return -1;
    } else {
        return top -> data;
    }   
}


// array menu function 
void arrayMenu() {
    int choice, val, max;

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
                printf("\nEnter the number to be pushed on stack >> ");
                scanf("%d", &val);
                pushAr(st, val, max);
                break;
            case 2:
                val = popAr(st);
                if (val != -1) {
                    printf("\nThe deleted data from the stack is: %d", val);
                }
                break;
            case 3:
                val = peekAr(st);
                if (val != -1) {
                    printf("\nThe top most element is: %d", val);
                }
                break;
            case 4:
                printf("\nCurrent Stack is\n");
                displayAr(st);
                break;
            case 5:
                exit(1);
            default:
                printf("\nWrong Choice\n");
                break;
        }
    }
}

// Linked list menu
void llMenu() {
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
                top = pushLi(top, val);
                break;
            case 2:
                top = popLi(top);
                break;
            case 3:
                val = peekLi(top);
                if (val != -1) {
                    printf("\nThe top most element is: %d", val);
                }
                break;
            case 4:
                printf("\nCurrent Stack is\n");
                displayLi(top);
                break;
            case 5:
                exit(1);
            default:
                printf("\nWrong Choice\n");
                break;
        }
    }
}



void main() {
    int choice;

    while (1) {
        printf("\n============================\n");
        printf("Press 1: Stack Using Array\n");
        printf("Press 2: Stack Using Linked List\n");
        printf("Press 3: Exit");
        printf("\n============================\n");
        printf("Enter Your Choice >> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nCreating STACK Using Array...\n");
                arrayMenu();
                break;
            case 2:
                printf("\nCreating STACK Using Linked List...\n");
                llMenu();
                break;
            case 3:
                exit(1);
            default:
                printf("\nWrong Choice\n");
                break;
        }
    }
}
