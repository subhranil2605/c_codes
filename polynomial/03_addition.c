#include<stdio.h>
#include<stdlib.h>


struct node {
    int coef;
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
    int value;
    int exp;

    newNode = createNode();

    printf("\nEnter the exponent >> ");
    scanf("%d", &exp);

    printf("\nEnter its coefficient >> ");
    scanf("%d", &value);

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
            printf("%d x^%d --> ", p -> coef, p -> exp);
        } else {
            printf("NULL\n");
            break;
        }   
        p = p -> next;
    }
}

// appending function
node append(node head, int coef, int exp) {
    node newNode, ptr;

    if (head == NULL) {
        newNode = createNode();
        newNode -> coef = coef;
        newNode -> exp = exp;
        newNode -> next = NULL;
        head = newNode;
    } else {
        ptr = head;
        while (ptr -> next != NULL) {
            ptr = ptr -> next;
        }
        newNode = createNode();
        newNode -> coef = coef;
        newNode -> exp = exp;
        newNode -> next = NULL;
        ptr -> next = newNode;
    }
    return head;
}


// polynomial addition
node polyAdd(node head1, node head2, node head3) {
    node p, q;
    int sumNum;
    p = head1;
    q = head2;

    while (p != NULL && q != NULL) {
        if (p -> exp == q -> exp) {
            sumNum = p -> coef + q -> coef;
            head3 = append(head3, sumNum, p -> exp);
            p = p -> next;
            q = q -> next;
        } else if (p -> exp < q -> exp) {
            head3 = append(head3, q -> coef, q -> exp);
            q = q -> next;
        } else if (p -> exp > q -> exp) {
            head3 = append(head3, p -> coef, p -> exp);
            p = p -> next;
        }
    }

    if(q == NULL){
        while (p != NULL) {
            head3 = append(head3, p -> coef, p -> exp);
            p = p -> next;
        }
    }

    if (p == NULL){
        while (q != NULL) {
            head3 = append(head3, q -> coef, q -> exp);
            q = q -> next;
        }
    }
}



void main() {
    int coef, exp;
    node p1, p2, p3 = NULL;

    p1 = createPoly();
    printf("\n-------------Enter the second polynomial-----------\n");
    p2 = createPoly();

    printf("\nThe First polynomial is =>\t");
    displayPoly(p1);
    printf("\nThe Second polynomial is =>\t");
    displayPoly(p2);

    p3 = polyAdd(p1, p2, p3);
    printf("\nThe Result polynomial is =>\t");
    displayPoly(p3);
    
}