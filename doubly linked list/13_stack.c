#include<stdio.h>
#include<stdlib.h>

int top = -1;


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
void display(node head) {
    if (head == NULL) {
        printf("\nThe Stack is empty!!!\n");
    } else {
        printf("NULL");
        while (head != NULL) {
            printf("<--%d-->", head -> data);
            head = head -> next;
        }
        printf("NULL");
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
        head -> prev = newNode;
        head = newNode;
    }
    return head;
}





// main function

void main() {
    node stack;

    stack = NULL;

    stack = push(stack);
    stack = push(stack);

    display(stack);
}