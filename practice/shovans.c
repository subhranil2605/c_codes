/*
Subhranil Sarkar
M.Sc. Data Science
21.12.2021
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// using typedef to use "node"
typedef struct Node node;

// Displaying the list
void displayList(node *p)
{
    while (p != NULL)
    {
        printf("%d-->", p->data);
        p = p->next;
    }
}

node *createNode()
{
    node *newnode = (node*)malloc(sizeof(node));
    if (newnode != NULL)
    {
        newnode->next = NULL;
        return newnode;
    }
    else
        return 0;
}

node *insertBeg(node *head)
{
    int value;
    node *newnode = createNode();
    if (newnode == NULL)
    {
        printf("overflow");
        return 0;
    }
    printf("\nEnter the data for insertion : \t");
    scanf("\n%d",&value);
    newnode->data = value;
    if (head == NULL)
    {
        head = newnode;
    }
    else {
        newnode->next = head;
        head = newnode;
    }
    return head;
}

node *insertEnd(node *head)
{
    int value;
    node *p;
    node *newnode = createNode();
    if (newnode == NULL)
    {
        printf("overflow");
        return 0;
    }
    printf("\nEnter the data for insertion : \t");
    scanf("\n%d",&value);
    newnode->data = value;
    if (head == NULL)
    {
        head = newnode;
    }
    else {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newnode;
    }
    return head;
}

node *insertAfter(node *head)
{
    int value, i, pos;
    node *p, *q;
    node *newnode = createNode();
    if (newnode == NULL)
    {
        printf("overflow");
        return 0;
    }
    printf("\nCurrent List is:  ");
    displayList(head);
    printf("\nEnter the position After which the Node has to be Inserted (starting from Zero): \t");
    scanf("\n%d",&pos);
    
    printf("\nEnter the data for Insertion : \t");
    scanf("\n%d",&value);
    
    newnode->data = value;
    if (pos == 0)
    {
        q = head->next;
        head->next = newnode;
        newnode->next = q;
    }
    else {
        p = head;
        for (i=0; i<pos; i++)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("Position does not exist");
                return head;
            }
        }
        newnode->next = p->next;
        p->next = newnode;
    }
    return head;
}

node *insertBef(node *head)
{
    int value, i, pos;
    node *p;
    node *newnode = createNode();
    if (newnode == NULL)
    {
        printf("overflow");
        return 0;
    }
    printf("\nCurrent List is:  ");
    displayList(head);
    printf("\nEnter the position Before which the Node has to be Inserted (starting from Zero): \t");
    scanf("\n%d",&pos);
    
    printf("\nEnter the Data for Insertion : \t");
    scanf("\n%d",&value);
    
    newnode->data = value;
    if (pos == 0)
    {
        newnode->next = head;
        head = newnode;
    }
    else {
        p = head;
        for (i=0; i<pos-1; i++)
        {
            p = p->next;
            if (p == NULL)
            {
                printf("Position does not exist");
                return head;
            }
        }
        newnode->next = p->next;
        p->next = newnode;
    }
    return head;
}

node *insertAny(node *head)
{
    int value, i, pos;
    node *p, *q;
    node *newnode = createNode();
    if (newnode == NULL)
    {
        printf("overflow");
        return 0;
    }
    printf("\nCurrent List is:  ");
    displayList(head);
    printf("\nEnter the position where the Node is to be Inserted (starting from Zero): \t");
    scanf("\n%d",&pos);

    printf("\nEnter the Data for Insertion: \t");
    scanf("\n%d",&value);
    newnode->data = value;
    if (pos == 0)
    {
        newnode->next = head->next;
        head = newnode;
    }
    else {
        p = head;
        for (i = 0; i<pos ; i++)
        {
            q = p;
            p = p->next;
            if (p == NULL)
            {
                printf("Position does not exist");
                return head;
            }
        }
        newnode->next = p->next;
        q->next = newnode;
    }
    return head;
}

node *createList()
{
    int i;
    char ch;
    node *start = NULL;
    printf("\n=======================\nPress 1 to insert from beginning\nPress 2 to insert from end\n=======================\n");
    scanf("%d",&i);
    if (i == 1)
    {
        do {
            start  = insertBeg(start);
            printf("\nPress 'y' to Continue or Press 'n' to stop:   \t");
            scanf("\n%c",&ch);
        }while (ch == 'y' || ch == 'Y');
    }
    else if (i == 2)
    {
        do {
            start  = insertEnd(start);
            printf("\nPress 'y' to Continue or Press 'n' to stop:   \t");
            scanf("\n%c",&ch);
        }while (ch == 'y' || ch == 'Y');    
    }
    else {
        printf("Invalid Input");
    }
    return start;
}

node *insertAnyMenu(node *list)
{
    int i;
    printf("\n=======================\nPress 1 to Insert Before a Node\nPress 2 to Insert After a Node\nPress 3 to Insert at a Particular Position\nPress 4 to go back\n=======================\n");
    scanf("%d",&i);
    switch (i)
    {
        case 1: list = insertBef(list);
            break;
            
        case 2: list = insertAfter(list);
            break;
            
        case 3: list = insertAny(list);
            break;

        case 4: return list;
            break;

        default : printf("Invalid Input");
            break;
    }
}

node *insertMenu(node *list)
{
    int i;
        printf("\n=======================\nPress 1 to Insert at Beginning\nPress 2 to Insert at End\nPress 3 to Insert at any Position\nPress 4 to go back\n=======================\n");
        scanf("%d",&i);
        switch (i)
        {
            case 1: list = insertBeg(list);
                break;

            case 2: list = insertEnd(list);
                break;
            
            case 3: list = insertAnyMenu(list);
                break;
            
            case 4: return list;
                break;

            default : printf("Invalid Input");
                break;
        }
}

void main()
{
    int i;
    node *list = NULL;
    node *newlist = NULL;
    while(1)
    {
        printf("\n=======================\nPress 1 to Create a List\nPress 2 to Insert\nPress 3 to displayList\nPress 4 to Exit\n=======================\n");
        scanf("%d",&i);
        switch (i)
        {
            case 1: {
                    list = createList();
                    printf("\nThe List has been Created");
                }
                break;

            case 2: {
                    list = insertMenu(list);
                    printf("\nOperation Completed");
                }
                break;

            case 3: displayList(list);
                break;

            case 4: exit(0);
                break;

            default : printf("\nInvalid Input");
                break;
        }
    }
}

