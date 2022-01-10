/*
Subhranil Sarkar
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
node insertAfter(node head);
node createNodeWithValue();

// main function
void main() {
    node list;
    list = createList();
    printList(list);

    list = insertAfter(list);
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



// insert after
node insertAfter(node head) {
    int choice, i, value;
    node ptr, newNode;

    printf("\nYour current list is : \n");
    printList(head);

    printf("\nEnter the position after which you want to insert the new node (starting from 0):: ");
    scanf("%d", &choice);

    newNode = createNodeWithValue();

    if (choice == 0) {
        // inserting at the beginning
        newNode -> next = head -> next;
        head -> next = newNode;
    } else {
        ptr = head;
        for (i = 0; i < choice; i++) {
            ptr = ptr -> next;
            if (ptr == NULL) {
                printf("\nIndex out of range!\nReturning the current list:\n");
                return head;
            }
        }
        newNode -> next = ptr -> next;
        ptr -> next = newNode;
    }
    return head;
    
}


node createNodeWithValue() {
    node newNode;
    int value;
    
    newNode = createNode();

    if (newNode == NULL) {
        printf("\nCould not create a new node!\n");
        return 0;
    }

    printf("\nEnter the new data:: ");
    scanf("%d", &value);
    newNode -> data = value;
    return newNode;
}