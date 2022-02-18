#include<stdio.h>
#include<stdlib.h>


struct node {
    int coef, exp;
    struct node* next;
};

typedef struct node* node;


// create Node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    temp -> next = NULL;
    return temp;
}

// inserting at the end
node insertEnd(node head) {
    int coef, exp;
    node newNode, p;
    newNode = createNode();
    printf("Enter the exponent >> ");
    scanf("%d", &exp);
    printf("Enter its coefficient >> ");
    scanf("%d", &coef);
    newNode -> coef = coef;
    newNode -> exp = exp;

    if (head == NULL) {
        return newNode;
    } else {
        p = head;
        while (p -> next != NULL) {
            p = p -> next;
        }
        p -> next = newNode;
    }
    return head;
}


// creating a polynomial
node createPoly() {
    node head;
    char ch;
    head = NULL;
    while (ch!='q') {
        head = insertEnd(head);
        printf("\nPress 'q' to exir OR Press anything to continue >> ");
        scanf("\n%c", &ch);
    }
    return head;
}

// append function 
node append(int coef, int exp, node head) {
    node newNode, p;
    newNode = createNode();
    newNode -> coef = coef;
    newNode -> exp = exp;

    if (head == NULL) {
        return newNode;
    } else {
        p = newNode;
        while (p -> next != NULL) {
            p = p -> next;
        }
        p -> next = newNode;
    }
    return head;
}


// polynomial addition
node polyAdd(node poly1, node poly2) {
    node p, q;
    node result, r, tmp;
    result = NULL;

    p = poly1;
    q = poly2;

    if (poly1 == NULL && poly2 == NULL) {
        return result;
    } 

    while (poly1 != NULL && poly2 != NULL) {
        tmp = (node) malloc(sizeof(node));

        if (result == NULL) {   // initial condition
            result = tmp;
            r = result;
        } else {
            r -> next = tmp;
            r = r -> next;
        }

        if (poly1 -> exp == poly2 -> exp) {
            tmp -> coef = p -> coef + q -> coef;
            tmp -> exp = p -> exp;
            poly1 = poly1 -> next;
            poly2 = poly2 -> next;
        } else if (poly1 -> exp > poly2 -> exp) {
            tmp -> coef = poly1-> coef;
            tmp -> exp = poly1 -> exp;
            poly1 = poly1 -> next;
        } else if (poly1 -> exp < poly2 -> exp){
            tmp -> coef = poly2 -> coef;
            tmp -> exp = poly2 -> exp;
            poly2 = poly2 -> next;
        }
    }

    // if the first polynomial remains
    while (p != NULL) {
        tmp = (node) malloc(sizeof(node));
        tmp -> coef = p -> coef;
        tmp -> exp = p -> exp;
        if (result == NULL) {
            result = tmp;
            r = result;
        } else {
            r -> next = tmp;
            r = r -> next;
        }
        p = p -> next;
    }

    // if the second polynomial remains
    while (q != NULL) {
        tmp = (node) malloc(sizeof(node));
        tmp -> coef = q -> coef;
        tmp -> exp = q -> exp;
        if (result == NULL) {
            result = tmp;
            r = result;
        } else {
            r -> next = tmp;
            r = r -> next;
        }
        q = q -> next;
    }

    r -> next = NULL;
    return result;
}




// display poly
void displayPoly(node p) {
    while (1) {
        if (p != NULL) {
            printf("%dx^%d --> ", p -> coef, p -> exp);
        } else {
            printf("NULL\n");
            break;
        }
        p = p -> next;
    }
}


// main function 
void main() {
    node p1, p2, r = NULL;

    printf("\nCreating first polynomial...\n");
    p1 = createPoly();

    printf("\nCreating second polynomial...\n");
    p2 = createPoly();

    printf("\nThe first Polynomial is:  ");
    displayPoly(p1);
    printf("\nThe second Polynomial is:  ");
    displayPoly(p2);

    printf("\nThe result polynomial is\n");
    r = polyAdd(p1, p2);
    displayPoly(r);
}