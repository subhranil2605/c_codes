
/*********NAME: ROHAN SAHA************/
/*********MSC IN COMPUTER SCIENCE*************/
/******** PROGRAMS OF  POLYNOMIAL USING LINKEDLIST*********/


#include<stdio.h>
#include<stdlib.h>

struct node {
        
        int coefficient;
        int degree;
        struct node *next;
};

struct node * createPolynomial(struct node *polyEq);
struct node * addPolynomial(struct node *polyEq1,struct node* polyEq2);
struct node * multPolynomial(struct node *polyEq1,struct node* polyEq2);
void displayPolynomial(struct node *polyEq);
struct node * insert(struct node *polyEq, int coefficient,int degree);
struct node * getNode();

void menu(struct node * polyEq1, struct node *polyEq2);

int main()
{
    struct node *polyEq1=NULL, *polyEq2=NULL,*polyEq3=NULL;
    system("clear");
    printf("Enter the data of Polynomial Equation 1 :\n");
    polyEq1 = createPolynomial(polyEq1);
    displayPolynomial(polyEq1);
    printf("Enter the data of Polynomial Equation 2 :\n");
    polyEq2 = createPolynomial(polyEq2);
    displayPolynomial(polyEq2);
    menu(polyEq1,polyEq2);

}

struct node * getNode()
{
    struct node * ll;
    ll= (struct node *)malloc(sizeof(struct node));
    if(ll!=NULL)
    {
        ll->next = NULL;
        return ll;
    }
    else
    {
        return NULL;
    }
}

struct node * createPolynomial(struct node *polyEq)
{
    int coeffiFromUser,degreeFromUser;
    char ch='Y';
    
do
{
    printf("Enter the coefficient : ");
    scanf("%d",&coeffiFromUser);
    printf("Enter the degree : ");
    scanf("%d",&degreeFromUser);

    polyEq = insert(polyEq,coeffiFromUser,degreeFromUser);

    printf("\nDo you want to add one more node?(Y/N): ");
    scanf("\n%c",&ch);
    
}while(ch == 'Y' || ch == 'y');
    return polyEq;
}

struct node * insert(struct node *polyEq,int coefficient, int degree)
{

    struct node *newNode, *temp;
    newNode = getNode();

    newNode->coefficient = coefficient;
    newNode->degree = degree;

    if(newNode==NULL)
    {
        printf("# MEMORY ALLOCATION FAILED..");
        return polyEq;
    }
    else
    {
        if(coefficient==0)
        {
            printf("\n**WARNING:: Coefficient 0 means this term is useless.\nSo, No extra node created.\n ");
        }
        else
        {
            if(polyEq==NULL || polyEq->degree < degree)
            {
                newNode->next = polyEq;
                polyEq = newNode;
            }
            else if(polyEq->degree == degree)
            {
                printf("\n**WARNING:: %d degree term is already present in this equation. So, coefficient will be updated..\nNo extra node created.\n", degree);
                polyEq->coefficient = polyEq->coefficient + coefficient;
                free(newNode);
                return polyEq;
            }
            else
            {
                temp = polyEq;
                while(temp->next != NULL && temp->next->degree > degree)
                {
                    if(temp->next->degree == degree)
                        {
                            printf("\n**WARNING:: %d degree term is already present in this equation. So, coefficient will be updated..\n", degree);
                            temp->next->coefficient = temp->next->coefficient + coefficient;
                            free(newNode);
                            return polyEq;
                        }
                    temp= temp->next;
                }

                newNode->next = temp->next;
                temp->next = newNode;
            }
        }


    
    }

        return polyEq;

}



void displayPolynomial(struct node *polyEq)
{
    struct node *temp;

    if(polyEq==NULL)
    {
        printf("# NO POLYNOMIAL EQUATION HERE..\n");
        return;
    }

    temp = polyEq;
    printf("\n\n\t\t\t\t\t>>\t ");

    while(temp)
    {
        if(temp->degree==0)
        {
            if(temp->coefficient<0)
                printf("%d ",temp->coefficient);

            else if(temp->coefficient>0)
                printf("+%d ",temp->coefficient);


        }
        else if(temp->degree==1)
        {
            if(temp->coefficient<0)

                printf(" %dX ",temp->coefficient);
            
            else if(temp->coefficient>1)
            {
                if(temp==polyEq)
                    printf(" %dX ",temp->coefficient);
                else
                    printf(" +%dX ",temp->coefficient);
            }

            else if(temp->coefficient==1)
            {
                if(temp==polyEq)
                    printf(" X ");
                else
                    printf(" +X ");
            }
            
            else if(temp->coefficient==-1)
                printf(" -X ");
        
        }
        else
        {
            if(temp->coefficient<0)
                printf("%dX^%d ",temp->coefficient,temp->degree);
            
            else if(temp->coefficient>1)
            {
                if(temp==polyEq)
                    printf(" %dX^%d ",temp->coefficient,temp->degree);
                else
                    printf(" +%dX^%d ",temp->coefficient,temp->degree);
            }
            
            else if(temp->coefficient==1)
            {
                if(temp==polyEq)
                    printf(" X^%d ",temp->degree);
                else
                    printf(" +X^%d ",temp->degree);
            }
        
            else if(temp->coefficient==-1)
                printf(" -X^%d ",temp->degree);
            
        }

        temp= temp->next;
    }
    printf(" \t<<\n\n");
}


struct node * addPolynomial(struct node *polyEq1,struct node* polyEq2)
{
    struct node *temp1 = polyEq1 , *temp2 = polyEq2 , *polyEq3 = NULL;

    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->degree == temp2->degree)
        {
            polyEq3 = insert(polyEq3,temp1->coefficient + temp2->coefficient, temp1->degree);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->degree > temp2->degree)
        {
            polyEq3 = insert(polyEq3, temp1->coefficient, temp1->degree);
            temp1 = temp1->next;
        }
        else
        {
            polyEq3 = insert(polyEq3, temp2->coefficient, temp2->degree);
            temp2 = temp2->next;
        }
    }
    while(temp1!=NULL)
    {
        polyEq3 = insert(polyEq3, temp1->coefficient, temp1->degree);
        temp1 = temp1->next;
    }
    while(temp2!=NULL)
    {
        polyEq3 = insert(polyEq3, temp2->coefficient, temp2->degree);
        temp2 = temp2->next;
    }

    return polyEq3;
}


struct node * multPolynomial(struct node *polyEq1,struct node* polyEq2)
{
    struct node * temp1 = polyEq1 , *temp2 = polyEq2, *polyEq3 = NULL;
    while(temp1!=NULL)
    {
        temp2 = polyEq2;
        while(temp2!=NULL)
        {
            polyEq3 = insert(polyEq3, temp1->coefficient*temp2->coefficient,temp1->degree+temp2->degree);
            temp2= temp2->next;
        }
       temp1= temp1->next;

    }

    return polyEq3;

}


void menu(struct node * polyEq1, struct node *polyEq2)
{
    char ch;
    struct node  *polyEq3=NULL;
    system("clear");
    printf("\n1.ADDITION\n");
    printf("2.MULTIPLICATION\n");
    printf("Enter your choice >> ");
    scanf("\n%c",&ch);
    switch(ch)
    {
        case '1': 
                {
                    printf("\t\t\t\tPOLYNOMIAL ADDITION\n\n\n");
                    printf("\nPolynomial Equation 1:\n");
                    displayPolynomial(polyEq1);
                    printf("\nPolynomial Equation 2:\n");
                    displayPolynomial(polyEq2);
                    printf("\nAfter adding Equation 1 and Equation 2 :\n");
                    polyEq3 = addPolynomial(polyEq1,polyEq2);
                    displayPolynomial(polyEq3);
                    break;

                }
        case '2': 
                {
                    printf("\t\t\t\tPOLYNOMIAL MULTIPLICATION\n\n\n");
                    printf("\nPolynomial Equation 1:\n");
                    displayPolynomial(polyEq1);
                    printf("\nPolynomial Equation 2:\n");
                    displayPolynomial(polyEq2);
                    printf("\nAfter multiplying Equation 1 and Equation 2 :\n");
                    polyEq3 = multPolynomial(polyEq1,polyEq2);
                    displayPolynomial(polyEq3);
                    break;

                }
        
        case '0':
                {   
                    system("clear");
                    exit(0);
                }

        default:    
                {
                    menu(polyEq1,polyEq2);
                    break;
                }
    }
}
