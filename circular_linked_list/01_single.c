#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
};

typedef struct node* node;



void main() {
    node last;
    node one = NULL;
    node two = NULL;
    node three = NULL;
    
    // Allocate memory
    one = (node) malloc(sizeof(node));
    two = (node) malloc(sizeof(node));
    three = (node) malloc(sizeof(node));

    // Adding value
    one -> data = 1;
    two -> data = 2;
    three -> data = 3;

    // connect nodes
    one -> next = two;
    two -> next = three;
    three -> next = one;

    // saver address of the last node in third
    last = three;
    
}