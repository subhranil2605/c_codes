#include<stdio.h>
#include<stdlib.h>

int top = -1;

// node structure
struct node {
    int data;
    struct node* next;
};

typedef struct node* node;


// Function prototypes
node createNode();
node push(node head);
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
node push(node head) {
    int val;
    node newNode;
    newNode = createNode();
    printf("\nEnter the data to be pushed in the list >> ");
    scanf("%d", &val);
    newNode -> data = val;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
    return head;
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

    // st = push(st);
    st = push(st);

    diplayStack(st);
}