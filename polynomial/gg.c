#include<stdio.h>
#include<stdlib.h>


struct node {
    int coef, exp;
    struct node* next;
};


typedef struct node* node;



// create a node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    temp -> next = NULL;
    return temp;
}

// appending into the list
node insertEnd(node head) {
    node newNode, p;
    int coef, exp;
    newNode = createNode();
    printf("\nEnter the coef: ");
    scanf("%d", &coef);
    printf("\nEnter the exp: ");
    scanf("%d", &exp);
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

// append
node append(node head, int coef, int exp) {
    node newNode, p;
    newNode = createNode();
    newNode -> coef = coef;
    newNode -> exp = exp;
    if (newNode == NULL) {
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


// create polynomial
node createPoly() {
    char ch;
    node head;

    head = NULL;

    while (ch != 'q') {
        head = insertEnd(head);
        printf("\nPress 'q' to exit the loop OR press any key to continue:: ");
        scanf("\n%c", &ch);
    }
    return head;
}


// adding two polynomials
node addPoly(node fpoly, node spoly) {
    float a;
    node tempo1, tempo2, polyadd, temporary;
    node next, next1, next2;
    next = NULL;
    next1 = NULL;
    next2 = NULL;
    polyadd = NULL;
    polyadd = (node )malloc(sizeof(node));
    temporary = polyadd;
    tempo1 = fpoly;
    tempo2 = spoly;
    while(tempo1 != NULL && tempo2 != NULL)
    {
        next = (node )malloc(sizeof(node));
        if(tempo1->exp == tempo2->exp)
        {
            a = tempo1->coef + tempo2->coef;
            polyadd->coef = a;
            polyadd->exp = tempo1->exp;
            polyadd->next = NULL;
            tempo1 = tempo1->next;
            tempo2 = tempo2->next;
        }
        else if(tempo1->exp > tempo2->exp)
        {
            polyadd->coef = tempo1->coef;
            polyadd->exp = tempo1->exp;
            polyadd->next = NULL;
            tempo1 = tempo1->next;
        }
        else
        {
            polyadd->coef = tempo2->coef;
            polyadd->exp = tempo2->exp;
            polyadd->next = NULL;
            tempo2 = tempo2->next;
        }
        if(tempo1 == NULL && tempo2 == NULL)
        {
            next->next = NULL;
        }
        else
        {
            next->next = NULL;
            polyadd->next = next;
            polyadd = polyadd->next;
        }
    }
    while(tempo1 != NULL)
    {
        next1 = (node )malloc(sizeof(node));
        polyadd->coef = tempo1->coef;
        polyadd->exp = tempo1->exp;
        polyadd->next = NULL;
        tempo1 = tempo1->next;
        if(tempo1 == NULL)
        {
            next1->next = NULL;
        }
        else
        {
            next1->next = NULL;
            polyadd->next = next1;
            polyadd = polyadd->next;
        }
    }
    while(tempo2 != NULL)
    {
        next2 = (node )malloc(sizeof(node));
        polyadd->coef = tempo2->coef;
        polyadd->exp = tempo2->exp;
        polyadd->next = NULL;
        tempo2 = tempo2->next;
        if(tempo2 == NULL)
        {
            next2->next = NULL;
        }
        else
        {
            next2->next = NULL;
            polyadd->next = next2;
            polyadd = polyadd->next;
        }
    }
    return temporary;
}



// display poly
void display(node p) {
    while (1) {
        if (p != NULL) {
            printf("%d x^%d--> ", p -> coef, p -> exp);
        } else {
            printf("NULL\n");
            break;
        }
        p = p -> next;
    }
}


void main() {
    node p1, p2, r;
    p1 = createPoly();
    display(p1);
    p2 = createPoly();
    display(p2);

    r = addPoly(p1, p2);
    display(r);
}