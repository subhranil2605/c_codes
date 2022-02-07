#include<stdio.h> 
#include<stdlib.h>


struct node {
    int value;
    int exp;
    struct node* next;
};

typedef struct node* node;

void displayList(node p);

void displayList(node p) {
    
}

void main() {
    node head;
    node one = NULL;
    node two = NULL;
    node three = NULL;

    // assigning memory
    one = (node) malloc(sizeof(node));
    two = (node) malloc(sizeof(node));
    three = (node) malloc(sizeof(node));

    // assigning values and exp

    // 5 x^2 + 6 x + 8

    one -> value = 5;
    one -> exp = 2;

    two -> value = 6;
    two -> exp = 1;

    three -> value = 8;
    three -> exp = 0;

    // linking the nodes
    one -> next = two;
    two -> next = three;
    three -> next = NULL;
    head = one;
}