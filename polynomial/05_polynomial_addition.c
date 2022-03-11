#include<stdio.h>
#include<stdlib.h>


struct node {
    int coef, exp;
    struct node* next;
};

typedef struct node* node;


// function prototypes
node createNode();
node insert(node head, int coef, int exp);
node createPolynomial();
void displayPoly(node);


// create a single node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    if (temp != NULL) {
        temp -> next = NULL;
        return temp;
    } else {
        return NULL;
    }
}


// insert an element
node insert(node head, int coef, int exp) {
    node newNode;
    node p;
    newNode = createNode();
    newNode -> coef = coef;
    newNode -> exp = exp;

    if (newNode == NULL) {
        printf("\nMemory Allocation Failed...\n");
    } else  {
        if (head == NULL || head -> exp < exp) {
            newNode -> next = head;
            head = newNode;
        } else {
            p = head;
            while (p -> next != NULL) {
                p = p -> next;
            }
            newNode -> next = p -> next;
            p -> next = newNode;
        }
    }
    return head;
}


// create polynomial
node createPolynomial() {
    int coef, exp;
    char ch = 'y';
    node head;
    head = NULL;

    while (ch != 'q') {
        printf("Enter the coefficient >> ");
        scanf("%d", &coef);
        printf("Enter the exponent >> ");
        scanf("%d", &exp);
        head = insert(head, coef, exp);
        printf("\nPress 'q' to stop OR Press anything to continue >> ");
        scanf("\n%c", &ch);
    }

    return head;
}

// displaying the polynomial
void displayPoly(node p) {
    while (1) {
        if (p != NULL) {
            printf("%d x^%d --> ", p -> coef, p -> exp);
        } else {
            printf("NULL\n");
            break;
        }
        p = p -> next;
    }
}


// main function
void main() {
    node poly;
    poly = createPolynomial();
    displayPoly(poly);
}