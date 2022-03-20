
#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node* node;


// creating a single node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    if (temp == NULL) {
        return temp;
    } else {
        temp -> next = NULL;
        temp -> prev = NULL;
        return temp;
    }
}


// displaying 
void display(node p) {
    if (p == NULL) {
        printf("The list is empty\n");
    } else {
        printf("NULL");
        while (p != NULL) {
            printf("<--%d-->", p -> data);
            p = p -> next;
        }
        printf("NULL\n");
    }
}


// inserting into the list
node insertEnd(node head) {
    node newNode, p;
    int value;

    newNode = createNode();

    printf("Enter the number to be inserted >> ");
    scanf("%d", &value);

    newNode -> data = value;

    if (head == NULL) {
        return newNode;
    } else {
        p = head;
        while (p -> next != NULL) {
            p = p -> next;
        }
        newNode -> prev = p;
        p -> next = newNode;
    }
    return head;
}


// insert any
node insertPos(node head) {
    int choice, i, value;
    node current, prev, newNode;

    printf("\nYour current list is : \n");
    display(head);

    printf("\nEnter the position where you want to insert the new value (starting from 0) >> ");
    scanf("%d", &choice);

    newNode = createNode();
    printf("Enter the data >>");
    scanf("%d", &value);
    newNode -> data = value;

    // inserting at the beginning
    if (choice == 0) {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    } else {          
        current = head;
        for (i = 0; i < choice; i++) {
            prev = current;
            current = current -> next;

            if (current == NULL) {
                printf("\nIndex out of range!\nReturning the current list:\n");
                return head;
            }
        }
        prev -> next = newNode;         // previous node's next node is the new node
        newNode -> prev = prev;         // new node's previous is the prev node
        newNode -> next = current;      // new node's next node is the current node
        current -> prev = newNode;      // new node's previous node is the newnode
    }
    return head;
    
}



void main() {
    node list;

    list = insertEnd(list);
    list = insertEnd(list);
    list = insertEnd(list);   

    display(list);

    list = insertPos(list);
    display(list);
}











