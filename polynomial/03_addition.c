#include<stdio.h>
#include<stdlib.h>


struct node {
    float coef;
    int exp;
    struct node* next;
};

typedef struct node* node;



// create node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    temp -> next = NULL;
    return temp;
}


// insert from the beginning
node insertBeg(node head) {
    node newNode;
    float value;
    int exp;

    newNode = createNode();

    printf("\nEnter the exponent >> ");
    scanf("%d", &exp);

    printf("\nEnter its coefficient >> ");
    scanf("%f", &value);

    newNode -> coef = value;
    newNode -> exp = exp;
    
    if (head == NULL) {
        head = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}


// create polynomial
node createPoly() {
    char ch;
    node head;

    head = NULL;

    while (ch != 'q') {
        head = insertBeg(head);

        printf("\nPress 'q' to exit OR Press any key to continue >> ");
        scanf("\n%c", &ch);
    }
    return head;
}


// display list
void displayPoly(node p) {
    while (1) {
        if (p != NULL) {
            printf("%0.2f x^%d --> ", p -> coef, p -> exp);
        } else {
            printf("NULL\n");
            break;
        }   
        p = p -> next;
    }
}

void main() {
    node p = createPoly();
    printf("The polynomial is =>\t");
    displayPoly(p);
}