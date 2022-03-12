/*
SUBHRANIL SARKAR
M.SC. DATA SCIENCE - 1st SEMESTER
UNIVERSITY OF KALYANI
--------------------------------------
============== ASSIGNMENT 4 ==============
Addition and Multiplication of Two Polynomials
Posted on => 2nd February, 2022
Date of Submission => 12th March, 2022
*/ 


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
node polyAdd(node poly1, node poly2);
node polyMult(node poly1, node poly2);
void menu(node poly1, node poly2);

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


// polynomial addition
node polyAdd(node poly1, node poly2) {
    node p1 = poly1;
    node p2 = poly2;
    node result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1 -> exp == p2 -> exp) {
            result = insert(result, p1 -> coef + p2 -> coef, p1 -> exp);
            p1 = p1 -> next;
            p2 = p2 -> next;
        } else if (p1 -> exp > p2 -> exp) {
            result = insert(result, p1 -> coef, p1 -> exp);
            p1 = p1 -> next;
        } else {
            result = insert(result, p2 -> coef, p2 -> exp);
            p2 = p2 -> next;
        }
    }

    while (p1 != NULL) {
        result = insert(result, p1 -> coef, p1 -> exp);
        p1 = p1 -> next;
    }

    while (p2 != NULL) {
        result = insert(result, p2 -> coef, p2 -> exp);
        p2 = p2 -> next;
    }

    return result;
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

// menu for user to choose between additon or multiplication
void menu(node poly1, node poly2) {
    node r = NULL;
    int choice;

    while (1) {
        printf("\n\n====================================================\n");
        printf("Press 1: POLYNOMIAL ADDITION\n");
        printf("Press 2: POLYNOMIAL MULTIPLICATION\n");
        printf("Press 3: EXIT\n");
        printf("\n====================================================\n");
        printf("\nEnter your choice >> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAddition of two Polynomials...\n");
                printf("\n\n\t");
                displayPoly(poly1);
                printf("\n\t");
                displayPoly(poly2);
                printf("\n+");
                printf("\n--------------------------------------------------------------------------------------------\n");
                r = polyAdd(poly1, poly2);
                printf("\t");
                displayPoly(r);
                printf("\n\n");
                break;
            case 2:
                printf("\nMultiplication of two Polynomials...\n");
                printf("\n\n\t");
                displayPoly(poly1);
                printf("\n\t");
                displayPoly(poly2);
                printf("\nX");
                printf("\n--------------------------------------------------------------------------------------------\n");
                r = polyMult(poly1, poly2);
                printf("\t");
                displayPoly(r);
                printf("\n\n");
                break;
            case 3:
                exit(1);
            
            default:
                printf("\nWrong Choice!!!\n");
                menu(poly1, poly2);
                break;
        }
    }
}



// main function
void main() {
    node poly1, poly2;
    int choice;

    poly1 = NULL;
    poly2 = NULL;

    printf("\n\nCreating 1st Polynomial...\n");
    poly1 = createPolynomial();
    printf("\nThe first polynomial is: ");
    displayPoly(poly1);

    printf("\n\nCreating 2nd Polynomial...\n");
    poly2 = createPolynomial();
    printf("\nThe second polynomial is: ");
    displayPoly(poly2);

    menu(poly1, poly2);
    
}
