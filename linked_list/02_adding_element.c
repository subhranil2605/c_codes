#include<stdio.h>
#include<stdlib.h>

// node structure
struct node {
    int value;
    struct node *next;
};


/* printing all the values from a linked list */
void printLinkedList(struct node *p) {
    while (p != NULL) {
        printf("%d\n", p -> value);
        p = p -> next;
    }
}


void main() {

    // initialize nodes
    struct node *head;
    struct node *one;
    struct node *two;
    struct node *three;

    // adding an element
    struct node *four;

    // allocating memory
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    // added
    four = malloc(sizeof(struct node));

    // assign values
    one -> value = 1;
    two -> value = 2;
    three -> value = 3;

    // added
    four -> value = 4;


    // connect nodes
    one -> next = four;
    two -> next = three;
    three -> next = NULL;

    // added
    four -> next = two;

    // printing the values of the linked list
    head = one;
    printLinkedList(head);


}