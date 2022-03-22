#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node* node;


// create a single node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    if (temp == NULL) {
        return temp;
    } else {
        temp -> next = NULL;
        return temp;
    }
}




void display(node last) {
    node p = last -> next;  // it points to the head of the list
    
    while (1) {
        if (p != last) {
            printf("%d-->", p -> data);
        } else {
            printf("%d\n", p -> data);
            break;
        }
        p = p -> next;
    }
}


// main function
void main() {
    node one = NULL, two = NULL, three = NULL, last;

    one = createNode();
    two = createNode();
    three = createNode();

    one -> data = 1;
    two -> data = 2;
    three -> data = 3;

    one -> next = two;
    two -> next = three;
    three -> next = one;

    last = three;

    printf("The list is: \t");
    display(last);
}