#include<stdio.h>
#include<stdlib.h>


struct node {
    int coef, exp;
    struct node* next;
};

typedef struct node* node;


node getNode();
node createPoly(node head);

// creating a single node
node getNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    if (temp != NULL) {
        temp -> next = NULL;
        return temp;
    } else {
        return NULL;
    }
}


// creating a linked list
node createPoly(node head) {
    int coef, exp;
    char ch = 'a';
    while (ch != 'q') {
        printf("Enter the coefficient >> ");
        scanf("%d", &coef);
        printf("Enter the exponent >> ");
        scanf("%d", &exp);

        head = insert
    }
}


// inserting
node insert(node head, int coef, int exp) {
    node newNode, temp;
    newNode = getNode();
    newNode -> coef = coef; 
    newNode -> exp = exp;

    if (newNode == NULL) {
        printf("MEMORY ALLOCATION FAILED!");
        return head;
    } else {
        if (coef == 0) {
            printf("Coefficient is 0, so no new memory is allocated!!!");
        } else {
            if (head == NULL || head -> exp < exp) {
                newNode -> next = head;
                head = newNode;
            } else if (head -> exp == exp) {
                printf("\n %d degree term is already present.", exp);
                head -> coef = head -> coef + coef;
                free(newNode);
                return head;
            } else {
                temp = head;
                while (temp -> next != NULL && temp -> next -> exp > exp) {
                    if (temp -> next -> exp == exp) {
                        
                    }
                }
            }
        }
    }
}