#include<stdio.h>
#include<stdlib.h>


struct node {
    float coeff;
    int exp;
    struct node* next;
};

typedef struct node* node;


/*Function declarations*/
node createPoly();
node createNode();
node insertBeg(node head);
void displayPoly(node p);

/*-----------------------------------------------------------------------------------------------------*/
/*Function definitions*/

// creating a single node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    temp -> next = NULL;
    return temp;
}

// inserting the polynomials from the beginning
node insertBeg(node head) {
    node newNode;
    float coeff;
    int exp;
    newNode = createNode();

    printf("\nEnter the exponentiaiton >> ");
    scanf("%d", &exp);

    printf("\nEnter its coefficient >> ");
    scanf("%f", &coeff);

    newNode -> coeff = coeff;
    newNode -> exp = exp;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}

// creating a polynomial
node createPoly() {
    char ch;
    node head;

    head = NULL;

    while (ch != 'q') {
        head = insertBeg(head);

        printf("\nPress 'q' to exit the loop OR Press any key to continue >> ");
        scanf("\n%c", &ch);
    }
    return head;
}

// display polynomial
void displayPoly(node p) {
    while (1) {
        if (p != NULL) {
            printf("%0.2fx^%d --> ", p -> coeff, p -> exp);
        } else {
            printf("NULL\n");
            break;
        }
        p = p -> next;
    }
}

/*-----------------------------------------------------------------------------------------------------*/
// Main function 
void main() {
    node p1;
    p1 = createPoly();
    displayPoly(p1);
}