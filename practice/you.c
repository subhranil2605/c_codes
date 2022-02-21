#include<stdio.h>
#include<stdlib.h>


struct node {
    int coef, pow;
    struct node* next;
};

typedef struct node* node;



node polyAdd(node, node);
node enter(node);
node insert(node, int, int);
void display(node);


void main() {
    node head1, head2, head3;

    head1 = NULL;
    head2 = NULL;
    head3 = NULL;

    printf("In Polynomial 1 :\n");
    head1 = enter(head1);

    printf("In Polynomial 2 :\n");
    head2 = enter(head2);

    head3 = polyAdd(head1, head2);

    printf("Polynomial 1 is : ");
    display(head1);
    printf("Polynomial 2 is : ");
    display(head2);
    printf("Sum of the above two polynomials is : ");
    display(head3);
}



node enter(node start) {
    int ex;
    int co;
    char ch;
    while (ch != 'q') {
        printf("\nEnter coefficient for term : ");
        scanf("\n%d", &co);
        printf("\nEnter exponent for term %d X^ : ", co);
        scanf("\n%d", &ex);
        start = insert(start, co, ex);
        printf("\nEnter 'q' to exit OR Press anything >> ");
        scanf("\n%c", &ch); 
    }
    return start;
}


node insert(node start, int co, int ex) {
    node ptr, tmp;
    tmp = (node) malloc(sizeof(node));
    tmp -> coef = co;
    tmp -> pow = ex;
    if (start == NULL) {
        tmp -> next = start;
        start = tmp;
    } else {
        ptr = start;
        while (ptr -> next != NULL) {
            ptr = ptr -> next;
        }
        tmp -> next = ptr -> next;
        ptr -> next = tmp;
        if (ptr -> next == NULL) {
            tmp -> next = NULL;
        }
    }
    return start;
}


// polynomial addition
node polyAdd(node poly1, node poly2) {
    node result, r, tmp;
    result = NULL;

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

        if (poly1 -> pow == poly2 -> pow) {
            tmp -> coef = poly1 -> coef + poly2 -> coef;
            tmp -> pow = poly1 -> pow;
            poly1 = poly1 -> next;
            poly2 = poly2 -> next;
        } else if (poly1 -> pow > poly2 -> pow) {
            tmp -> coef = poly1-> coef;
            tmp -> pow = poly1 -> pow;
            poly1 = poly1 -> next;
        } else if (poly1 -> pow < poly2 -> pow){
            tmp -> coef = poly2 -> coef;
            tmp -> pow = poly2 -> pow;
            poly2 = poly2 -> next;
        }
    }

    // if the first polynomial remains
    while (poly1 != NULL) {
        tmp = (node) malloc(sizeof(node));
        tmp -> coef = poly1 -> coef;
        tmp -> pow = poly1 -> pow;
        if (result == NULL) {
            result = tmp;
            r = result;
        } else {
            r -> next = tmp;
            r = r -> next;
        }
        poly1 = poly1 -> next;
    }

    // if the second polynomial remains
    while (poly2 != NULL) {
        tmp = (node) malloc(sizeof(node));
        tmp -> coef = poly2 -> coef;
        tmp -> pow = poly2 -> pow;
        if (result == NULL) {
            result = tmp;
            r = result;
        } else {
            r -> next = tmp;
            r = r -> next;
        }
        poly2 = poly2 -> next;
    }

    r -> next = NULL;
    return result;
}


void display(node ptr) {
    if (ptr == NULL) {
        printf("Empty\n");
        return;
    }

    while (ptr != NULL) {
        printf("%dx^%d-->", ptr -> coef, ptr -> pow);
        ptr = ptr -> next;
    }
    printf("\b\b \n");
}