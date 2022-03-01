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
void displaySAr(int st[]);
void pushSAr(int st[], int val, int MAX);
int popSAr(int st[]);
int peekSAr(int st[]);
void menuSAr();

// stack using linked list 
node createNode();
node pushSLi(node top, int val);
node popSLi(node top);
int peekSLi(node top);
void displaySLi(node p);
void menuSLi();


/* Stack using array functions */

// display
void displaySAr(int st[]) {
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
void pushSAr(int st[], int val, int MAX) {
    if (top == MAX - 1) {
        printf("\nSTACK is Full!!!\n");
    } else {
        top++;
        st[top] = val;
    }
}


// POP Operation
int popSAr(int st[]) {
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
int peekSAr(int st[]) {
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
void displaySLi(node p) {
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
node pushSLi(node head, int val) {
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
node popSLi(node top) {
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
int peekSLi(node top){
    if (top == NULL) {
        printf("\nThe STACK is empty\n");
        return -1;
    } else {
        return top -> data;
    }   
}


// array menu function 
void menuSAr() {
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
                pushSAr(st, val, max);
                break;
            case 2:
                val = popSAr(st);
                if (val != -1) {
                    printf("\nThe deleted data from the stack is: %d", val);
                }
                break;
            case 3:
                val = peekSAr(st);
                if (val != -1) {
                    printf("\nThe top most element is: %d", val);
                }
                break;
            case 4:
                printf("\nCurrent Stack is\n");
                displaySAr(st);
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
void menuSLi() {
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
                top = pushSLi(top, val);
                break;
            case 2:
                top = popSLi(top);
                break;
            case 3:
                val = peekSLi(top);
                if (val != -1) {
                    printf("\nThe top most element is: %d", val);
                }
                break;
            case 4:
                printf("\nCurrent Stack is\n");
                displaySLi(top);
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
                menuSAr();
                break;
            case 2:
                printf("\nCreating STACK Using Linked List...\n");
                menuSLi();
                break;
            case 3:
                exit(1);
            default:
                printf("\nWrong Choice\n");
                break;
        }
    }
}
