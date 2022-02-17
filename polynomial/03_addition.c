#include<stdio.h>
#include<stdlib.h>


struct node {
    int coef, exp;
    struct node* next;
};

typedef struct node* node;


void createNode(int x, int y, node temp) {
    node r, z;
    z = temp;
    if (z == NULL) {
        r = (node) malloc(sizeof(node));
        r -> coef = x;
        r -> exp = y;
        temp = r;
        r -> next = (node) malloc(sizeof(node));
        r = r -> next;
        r -> next = NULL;
    } else {
        r -> coef = x;
        r -> exp = y;
        r -> next = (node) malloc(sizeof(node));
        r = r -> next;
        r -> next = NULL;
    }
}


void polyAdd(node poly1, node poly2, node poly) {
    while (poly1 -> next && poly2 -> next) {
        if (poly1 -> exp > poly2 -> exp) {
            poly -> exp = poly1 -> exp;
            poly -> coef = poly1 -> coef;
            poly1 = poly1 -> next;
        } else if (poly2 -> exp > poly1 -> exp) {
            poly -> exp = poly2 -> exp;
            poly -> coef = poly2 -> coef;
            poly2 = poly2 -> next;
        } else {
            poly -> exp = poly1 -> exp;
            poly -> coef = poly1 -> coef + poly2 -> coef;
            poly1 = poly1 -> next;
            poly2 = poly2 -> next;
        }
        poly -> next = (node) malloc(sizeof(node));
        poly = poly -> next;
        poly -> next = NULL;
    }

    while (poly1 -> next || poly2 -> next) {
        if (poly1 -> next) {
            poly -> exp = poly1 -> exp;
            poly -> coef = poly1 -> coef;
            poly1 = poly1 -> next;
        } 
        if (poly2 -> next) {
            poly -> exp = poly2 -> exp;
            poly -> coef = poly2 -> coef;
            poly2 = poly2 -> next;
        }
        poly -> next = (node) malloc(sizeof(node));
        poly = poly -> next;
        poly -> next = NULL;
    }
}


void show(node p) {
    while (1) {
        if (p != NULL) {
            printf("%d x^%d--> ", p -> coef, p -> exp);
        } else {
            printf("NULL\n");
            break;
        }
        p = p -> next;
}

