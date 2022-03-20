#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node* node;


void main() {
    node one, two, three, head;

    one = NULL;
    two = NULL;
    three = NULL;   

    // Allocating memory
    one = (node) malloc(sizeof(node));
    two = (node) malloc(sizeof(node));
    three = (node) malloc(sizeof(node));

    // inserting data
    one -> data = 1;
    two -> data = 2;
    three -> data = 3;


    // linking
    one -> next = two;
    one -> prev = NULL;

    two -> next = three;
    two -> prev = one;

    three -> next = NULL;
    three -> prev = two;

    head = NULL;
}
