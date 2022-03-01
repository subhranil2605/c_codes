#include<stdio.h>
#include<stdlib.h>


struct node {
    int coef, exp;
    struct node* next;
};

typedef struct node* node;


// functions prototypes
node getNode();
node insert(node, int, int);
node createPoly();
void display(node);



// creating a single node
node getNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    if (temp != NULL) {
        temp -> next = NULL;
        return temp;
    } else {
        return NULL;   // failed to allocate memory
    }
}


// inserting into list
node insert(node head, int coef, int exp) {
    node newNode, temp;

    newNode = getNode();
    newNode -> coef = coef;
    newNode -> exp = exp;

    if (newNode == NULL) {
        printf("Memory Allocation failed!!!");
        return head;
    } else {
        if (coef == 0) {
            printf("Coefficient is 0. So no new memory is allocated.");
        } else {
            if (head == NULL || head -> exp < exp) {
                newNode -> next = head;
                head = newNode;
            } else if (head -> exp == exp) {
                printf("\nCoefficients are same. So they are merged together.\n");
                head -> coef = head -> coef + coef;
                free(newNode);
                return head;
            } else {
                temp = head;
                while (temp -> next != NULL && temp -> next -> exp > exp) {
                    if (temp -> next -> exp == exp) {
                        printf("\nCoefficients are same. So they are merged together.\n");
                        temp -> next -> coef = temp -> next -> coef + coef;
                        free(newNode);
                        return head;
                    }
                    temp = temp -> next;
                }
                newNode -> next = temp -> next;
                temp -> next = newNode;
            }
        }
    }
    return head;
}


// create a polynomial
node createPoly() {
    node head;
    int coef, exp;
    char ch = 'y';

    head = NULL;
    while (ch != 'q') {
        printf("Enter the coefficient >> ");
        scanf("%d", &coef);

        printf("Enter the exponent >> ");
        scanf("%d", &exp);

        head = insert(head, coef, exp);
        printf("\nPress 'q' to continue OR Press anything to continue >> ");
        scanf("\n%c", &ch);
    }
    return head;
}


// displaying the polynomial
void display(node p) {
    if (p == NULL) {
        printf("Empty Polynomial");
    } else {
        while (1) {
            if (p != NULL) {
                if (p -> exp == 1) {
                    printf("%dX-->", p -> coef);
                } else if (p -> exp == 0) {
                    printf("%d-->", p -> coef);
                } else {
                    printf("%dX^%d-->", p -> coef, p -> exp);
                }
            } else {
                printf("NULL\n");
                break;
            }
            p = p -> next;
        }
    }
}

void main() {
    node p1;
    p1 = createPoly();
    display(p1);
}#include<stdio.h>
#include<stdlib.h>


struct node {
    int coef, exp;
    struct node* next;
};

typedef struct node* node;


// functions prototypes
node getNode();
node insert(node, int, int);
node createPoly();
void display(node);



// creating a single node
node getNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    if (temp != NULL) {
        temp -> next = NULL;
        return temp;
    } else {
        return NULL;   // failed to allocate memory
    }
}


// inserting into list
node insert(node head, int coef, int exp) {
    node newNode, temp;

    newNode = getNode();
    newNode -> coef = coef;
    newNode -> exp = exp;

    if (newNode == NULL) {
        printf("Memory Allocation failed!!!");
        return head;
    } else {
        if (coef == 0) {
            printf("Coefficient is 0. So no new memory is allocated.");
        } else {
            if (head == NULL || head -> exp < exp) {
                newNode -> next = head;
                head = newNode;
            } else if (head -> exp == exp) {
                printf("\nCoefficients are same. So they are merged together.\n");
                head -> coef = head -> coef + coef;
                free(newNode);
                return head;
            } else {
                temp = head;
                while (temp -> next != NULL && temp -> next -> exp > exp) {
                    if (temp -> next -> exp == exp) {
                        printf("\nCoefficients are same. So they are merged together.\n");
                        temp -> next -> coef = temp -> next -> coef + coef;
                        free(newNode);
                        return head;
                    }
                    temp = temp -> next;
                }
                newNode -> next = temp -> next;
                temp -> next = newNode;
            }
        }
    }
    return head;
}


// create a polynomial
node createPoly() {
    node head;
    int coef, exp;
    char ch = 'y';

    head = NULL;
    while (ch != 'q') {
        printf("Enter the coefficient >> ");
        scanf("%d", &coef);

        printf("Enter the exponent >> ");
        scanf("%d", &exp);

        head = insert(head, coef, exp);
        printf("\nPress 'q' to continue OR Press anything to continue >> ");
        scanf("\n%c", &ch);
    }
    return head;
}


// displaying the polynomial
void display(node p) {
    if (p == NULL) {
        printf("Empty Polynomial");
    } else {
        while (1) {
            if (p != NULL) {
                if (p -> exp == 1) {
                    printf("%dX-->", p -> coef);
                } else if (p -> exp == 0) {
                    printf("%d-->", p -> coef);
                } else {
                    printf("%dX^%d-->", p -> coef, p -> exp);
                }
            } else {
                printf("NULL\n");
                break;
            }
            p = p -> next;
        }
    }
}

void main() {
    node p1;
    p1 = createPoly();
    display(p1);
}