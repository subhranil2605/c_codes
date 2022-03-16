#include<stdio.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node* node;


// main function
void main() {
    node first, two, three, last;

    first = NULL;
    two = NULL;
    three = NULL;

    // Allocating memory
    first = (node) malloc(sizeof(node));
    two = (node) malloc(sizeof(node));
    three = (node) malloc(sizeof(node));

    first -> data = 1;
    two -> data = 2;
    three -> data = 3;

    first -> next = two;
    two -> next = three;
    three -> next = one;

    last = three;
}