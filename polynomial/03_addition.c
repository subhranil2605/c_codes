#include<stdio.h>
#include<stdlib.h>

struct polynomial
{
    float coeff;
    int power;
    struct polynomial *link;
};

typedef struct polynomial* poly;

poly creatPolynomial(poly var)
{
    float a;
    int b;
    char c;
    poly temporary, next;
    var = (poly)malloc(sizeof(poly));
    printf("\ncoefficient: ");
    scanf("%f", &a);
    printf("\n");
    var->coeff = a;
    printf("x^ ");
    scanf("%d", &b);
    var->power = b;
    var->link = NULL;
    temporary = var;
    up:
    next = (poly)malloc(sizeof(poly));
    printf("\nadd more terms (y/n): ");
    scanf("%s", &c);
    printf("\n");
    if(c == 'n')
    {
        next->link = NULL;
    }
    else
    {
        printf("\ncoefficient: ");
        scanf("%f", &a);
        printf("\n");
        next->coeff = a;
        printf("x^ ");
        scanf("%d", &b);
        printf("\n");
        next->power = b;
        next->link = NULL;
        temporary->link = next;
        temporary = temporary->link;
        goto up;
    }
    return var;
}

void displayPoly(poly head)
{
    poly temporary = NULL;
    temporary = head;
    while(temporary != NULL)
    {
        printf("+ (%.2f)x^%d ", temporary->coeff, temporary->power);
        temporary = temporary->link;
    }
}

poly addPolynomial(poly fpoly, poly spoly)
{
    float a;
    poly tempo1, tempo2, polyadd, temporary;
    poly next, next1, next2;
    next = NULL;
    next1 = NULL;
    next2 = NULL;
    polyadd = NULL;
    polyadd = (poly )malloc(sizeof(poly));
    temporary = polyadd;
    tempo1 = fpoly;
    tempo2 = spoly;
    while(tempo1 != NULL && tempo2 != NULL)
    {
        next = (poly )malloc(sizeof(poly));
        if(tempo1->power == tempo2->power)
        {
            a = tempo1->coeff + tempo2->coeff;
            polyadd->coeff = a;
            polyadd->power = tempo1->power;
            polyadd->link = NULL;
            tempo1 = tempo1->link;
            tempo2 = tempo2->link;
        }
        else if(tempo1->power > tempo2->power)
        {
            polyadd->coeff = tempo1->coeff;
            polyadd->power = tempo1->power;
            polyadd->link = NULL;
            tempo1 = tempo1->link;
        }
        else
        {
            polyadd->coeff = tempo2->coeff;
            polyadd->power = tempo2->power;
            polyadd->link = NULL;
            tempo2 = tempo2->link;
        }
        if(tempo1 == NULL && tempo2 == NULL)
        {
            next->link = NULL;
        }
        else
        {
            next->link = NULL;
            polyadd->link = next;
            polyadd = polyadd->link;
        }
    }
    while(tempo1 != NULL)
    {
        next1 = (poly )malloc(sizeof(poly));
        polyadd->coeff = tempo1->coeff;
        polyadd->power = tempo1->power;
        polyadd->link = NULL;
        tempo1 = tempo1->link;
        if(tempo1 == NULL)
        {
            next1->link = NULL;
        }
        else
        {
            next1->link = NULL;
            polyadd->link = next1;
            polyadd = polyadd->link;
        }
    }
    while(tempo2 != NULL)
    {
        next2 = (poly )malloc(sizeof(poly));
        polyadd->coeff = tempo2->coeff;
        polyadd->power = tempo2->power;
        polyadd->link = NULL;
        tempo2 = tempo2->link;
        if(tempo2 == NULL)
        {
            next2->link = NULL;
        }
        else
        {
            next2->link = NULL;
            polyadd->link = next2;
            polyadd = polyadd->link;
        }
    }
    return temporary;
}

poly polyMul(poly head1, poly head2)
{
    poly head = NULL;
    poly temp = NULL;
    poly prev = NULL;
    poly temporary = NULL;
    poly temp1 = NULL;
    poly temp2 = NULL;
    temp1 = head1;
    while(temp1 != NULL)
    {
        temp2 = head2;
        while(temp2 != NULL)
        {
            temporary = (poly )malloc(sizeof(poly));
            temporary->coeff = temp1->coeff * temp2->coeff;
            temporary->power = temp1->power + temp2->power;
            temporary->link = NULL;
            if(head == NULL)
            {
                head = temporary;
            }
            else
            {
                temp = head;
                prev = head;
                while(temp != NULL && temp->power > temporary->power)
                {
                    prev = temp;
                    temp = temp->link;
                }
                if(temp == NULL)
                {
                    prev->link = temporary;
                }
                else if(temp->power == temporary->power)
                {
                    temp->coeff = temp->coeff + temporary->coeff;
                }
                else
                {
                    prev->link = temporary;
                    temporary->link = temp;
                }
                
            }
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
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
    poly firstPoly;
    poly secondPoly; 
    poly resultPoly;
    poly addpoly;
    
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