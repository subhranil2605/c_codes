/*
Subhranil Sarkar
Creating List with the function Insert at the beginning
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node* node;

// Function declarations
node createNode();
node insertBeg(node head);
node createList();
node printList(node p);

// main function
void main() {
    node list;
    list = createList();
    printList(list);
}

// Function definitions

// displaying the whole list
node printList(node p) {
    while(1) {
        if(p != NULL) {
            printf("%d-->", p -> data);
        } else {
            printf("NULL\n");
            break;
        }
        p = p -> next;
    }
}

// create a node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    temp -> next = NULL;
    return temp;
}


// inserting at the beginning
node insertBeg(node head) {
    node newNode;
    int value;
    newNode = createNode();

    printf("Enter the data you want to insert into the list:: ");
    scanf("%d", &value);

    newNode -> data = value;
    
    if(head == NULL) {
        head = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}


// creating list
node createList() {
    char ch;
    node head;

    head = NULL;

    while (ch != 'q') {
        head = insertBeg(head);

        printf("\nPress 'q' to exit the loop OR press any key to continue:: ");
        scanf("\n%c", &ch);
    }
    return head;
}
