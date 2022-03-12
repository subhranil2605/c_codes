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
node polyMult(node poly1, node poly2);


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
        return head;
    } else  {
        if (coef == 0) {
            printf("\nCoef is 0, so new node is created!!\n");
        } else {
            if (head == NULL || head -> exp < exp) {
                newNode -> next = head;
                head = newNode;
            } else if (head -> exp == exp) {
                printf("\n%d Degree is already present! So, the new node is updated!!!\n", exp);
                head -> coef = head -> coef + coef;
                free(newNode);
                return head;
            } else {
                p = head;
                while (p -> next != NULL && p -> next -> exp >= exp) {
                    if (p -> next -> exp == exp) {
                        // printf("\n%d Degree is already present! So, the new node is updated!!!\n", exp);
                        p -> next -> coef = p -> next -> coef + coef;
                        free(newNode);
                        return head;
                    }
                    p = p -> next;
                }
                newNode -> next = p -> next;
                p -> next = newNode;
            }
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
            if (p -> exp == 1) {
                printf(" + (%d)x", p -> coef);
            } else if (p -> exp == 0) {
                printf(" + (%d)", p -> coef);
            } else {
                printf(" + (%d)x^%d", p -> coef, p -> exp);    
            }
        } else {
            // printf("NULL\n");
            break;
        }
        p = p -> next;
    }
}


// polynomial multiplication
node polyMult(node poly1, node poly2) {
    node p, q;
    node result = NULL;
    for (p = poly1; p != NULL; p = p -> next) {
        for (q = poly2; q != NULL; q = q -> next) {
            result = insert(result, p -> coef * q -> coef, p -> exp + q -> exp);
        }
    }
    return result;
}


// main function
void main() {
    node poly1 = NULL, poly2 = NULL, r = NULL;

    // poly1 = createPolynomial( );
    // displayPoly(poly1);


    poly1 = insert(poly1, 5, 2);
    poly1 = insert(poly1, 7, 1);

    poly2 = insert(poly2, 2, 1);
    poly2 = insert(poly2, 6, 0);
    // displayPoly(poly2);

    r = polyMult(poly1, poly2);
    displayPoly(r);
    
} 