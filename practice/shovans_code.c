#include<stdio.h>
#include<stdlib.h>
struct node {
    float coeff;
    int power;
    struct node *next;
};

typedef struct node* node;


node creatPolynomial(node var) {
    float a;
    int b;
    char c;
    node tmp, next;
    var = (node)malloc(sizeof(node));
    printf("\ncoefficient: ");
    scanf("%f", &a);
    printf("\n");
    var->coeff = a;
    printf("x^ ");
    scanf("%d", &b);
    var->power = b;
    var->next = NULL;
    tmp = var;
    up:
    next = (node)malloc(sizeof(node));
    printf("\nadd more terms (y/n): ");
    scanf("%s", &c);
    printf("\n");
    if(c == 'n') {
        next->next = NULL;
    } else {
        printf("\ncoefficient: ");
        scanf("%f", &a);
        printf("\n");
        next->coeff = a;
        printf("x^ ");
        scanf("%d", &b);
        printf("\n");
        next->power = b;
        next->next = NULL;
        tmp->next = next;
        tmp = tmp->next;
        goto up;
    }
    return var;
}

void displayPoly(node head)
{
    node tmp = NULL;
    tmp = head;
    while(tmp != NULL)
    {
        printf("+ (%.2f)x^%d ", tmp->coeff, tmp->power);
        tmp = tmp->next;
    }
}

node addPolynomial(node fpoly, node spoly) {
    node p, q, result, tmp;
    node next = NULL, next1 = NULL, next2 = NULL;
    result = (node)malloc(sizeof(node));
    tmp = result;
    p = fpoly;
    q = spoly;
    while(p != NULL && q != NULL) {
        next = (node)malloc(sizeof(node));
        if(p->power == q->power) {
            result->coeff = p->coeff + q->coeff;
            result->power = p->power;
            result->next = NULL;
            p = p->next;
            q = q->next;
        } else if(p->power > q->power) {
            result->coeff = p->coeff;
            result->power = p->power;
            result->next = NULL;
            p = p->next;
        } else {
            result->coeff = q->coeff;
            result->power = q->power;
            result->next = NULL;
            q = q->next;
        }
        if(p == NULL && q == NULL) {
            next->next = NULL;
        } else {
            next->next = NULL;
            result->next = next;
            result = result->next;
        }
    }
    while(p != NULL) {
        next1 = (node )malloc(sizeof(node));
        result->coeff = p->coeff;
        result->power = p->power;
        result->next = NULL;
        p = p->next;
        if(p == NULL) {
            next1->next = NULL;
        } else {
            next1->next = NULL;
            result->next = next1;
            result = result->next;
        }
    }
    while(q != NULL) {
        next2 = (node )malloc(sizeof(node));
        result->coeff = q->coeff;
        result->power = q->power;
        result->next = NULL;
        q = q->next;
        if(q == NULL) {
            next2->next = NULL;
        } else {
            next2->next = NULL;
            result->next = next2;
            result = result->next;
        }
    }
    return tmp;
}

node polyMul(node head1, node head2) {
    node head = NULL;
    node temp = NULL;
    node prev = NULL;
    node tmp = NULL;
    node temp1 = NULL;
    node temp2 = NULL;
    temp1 = head1;
    while(temp1 != NULL) {
        temp2 = head2;
        while(temp2 != NULL) {
            tmp = (node )malloc(sizeof(node));
            tmp->coeff = temp1->coeff * temp2->coeff;
            tmp->power = temp1->power + temp2->power;
            tmp->next = NULL;
            if(head == NULL) {
                head = tmp;
            } else {
                temp = head;
                prev = head;
                while(temp != NULL && temp->power > tmp->power) {
                    prev = temp;
                    temp = temp->next;
                }
                if(temp == NULL) {
                    prev->next = tmp;
                } else if(temp->power == tmp->power) {
                    temp->coeff = temp->coeff + tmp->coeff;
                } else {
                    prev->next = tmp;
                    tmp->next = temp;
                }
                
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return head;
}

int main()
{
    printf("Polynomial Addition and Multiplication\n");
    printf("Please enter the polynomial in the descending order of exponent\n\n");
    char d;
    char e;
    int choice;
    node firstPoly;
    node secondPoly; 
    node resultPoly;
    node addpoly;
    
    while(1)
    {
        xy:
        firstPoly = NULL;
        secondPoly = NULL;
        resultPoly = NULL;
        addpoly = NULL;
        printf("\nEnter the first polynomial: \n");
        firstPoly = creatPolynomial(firstPoly);
        displayPoly(firstPoly);
        printf("\n\nEnter the second polynomial: \n");
        secondPoly = creatPolynomial(secondPoly);
        displayPoly(secondPoly);
        on:
        printf("\n\nEnter 1 for Addition\nEnter 2 for Multiplication\nEnter 3 for both\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("\nThe sum of these two polynomials: \n\n");
            addpoly = addPolynomial(firstPoly, secondPoly);
            printf("{");
            displayPoly(firstPoly);
            printf("}");
            printf("  +  ");
            printf("{");
            displayPoly(secondPoly);
            printf("}\n\n = ");
            displayPoly(addpoly);
            printf("\n\n");
            break;
        case 2:
            printf("\nThe multiplication of these two polynomials: \n\n");
            resultPoly = polyMul(firstPoly, secondPoly);
            printf("{");
            displayPoly(firstPoly);
            printf("}");
            printf("  X  ");
            printf("{");
            displayPoly(secondPoly);
            printf("}\n\n = ");
            displayPoly(resultPoly);
            printf("\n\n");
            break;
        case 3:
            printf("\nThe sum of these two polynomials: \n\n");
            addpoly = addPolynomial(firstPoly, secondPoly);
            printf("{");
            displayPoly(firstPoly);
            printf("}");
            printf("  +  ");
            printf("{");
            displayPoly(secondPoly);
            printf("}\n\n = ");
            displayPoly(addpoly);
            printf("\n\n");
            printf("\nThe multiplication of these two polynomials: \n\n");
            resultPoly = polyMul(firstPoly, secondPoly);
            printf("{");
            displayPoly(firstPoly);
            printf("}");
            printf("  X  ");
            printf("{");
            displayPoly(secondPoly);
            printf("}\n\n = ");
            displayPoly(resultPoly);
            break;
        default:
            break;
        }
        printf("\n\nwant to proceed for more(y/n): ");
        scanf("%s", &d);
        if(d == 'n')
        {
            exit(1);
        }
        else
        {
            printf("\nwant to proceed another operation with these polynomials(y/n): ");
            scanf("%s", &e);
            if(e == 'y')
            {
                goto on;
            }
            else
            {
                goto xy;
            }
        }
    }
    return 0;
}


