#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
};

typedef struct node* node;

/* ------------------- Function declarations --------------- */
node displayList(node p);
node createNode();
node insertBeg(node head);
node createList();

/* ------------------- Function definitions --------------- */

// displaying
node displayList(node p) {
    while (1) {
        if (p != NULL) {
            printf("%d-->", p -> data);
        } else {
            printf("NULL\n");
            break;
        }
        p = p -> next;
    }
}


// create a single node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    temp -> next = NULL;
    return temp;
}

// inserting from the beginning
node insertBeg(node head) {
    node newNode;
    int value;

    newNode = createNode();
    printf("\nEnter the new value >> ");
    scanf("%d", &value);
    newNode -> data = value;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}

// creating a list
node createList() {
    node head;
    char ch;

    head = NULL;

    while (ch != 'q') {
        head = insertBeg(head);
        printf("\nPress 'q' to stop OR Press any key to continue >> ");
        scanf("\n%c", &ch);
    }
    return head;
}



// main function
void main() {
    node list;
    list = createList();
    displayList(list);
}
