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
node insertBeg(node head) {
    node newNode;
    int value;

    newNode = createNode();

    printf("Enter the number to be inserted >> ");
    scanf("%d", &value);

    newNode -> data = value;

    if (head == NULL) {
        return newNode;
    } else {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
    return head;
}



void main() {
    node list;

    list = insertBeg(list);
    list = insertBeg(list);
    list = insertBeg(list);   

    display(list);
}
