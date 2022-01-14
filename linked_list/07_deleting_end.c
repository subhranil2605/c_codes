#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
};

typedef struct node* node;

// function declarations
node createNode();
node insertBeg(node head);
node createList();
void printList(node head);
node deleteEnd(node head);


// displaying a list
void printList(node p) {
    printf("\nYour list is:: \n");
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

// creating a single node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    temp -> next = NULL;
    return temp;
}

// inserting at the starting position function
node insertBeg(node head) {
    node newNode;
    int value;
    newNode = createNode();

    printf("Enter the value of new data:: ");
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
        printf("\nPress 'q' to exit OR Press any key to continue: ");
        scanf("\n%c", &ch);
    }
    return head;
}


// delete at the beginning
node deleteEnd(node head) {
    node p, q;
    int temp;
    if (head == NULL) {
        printf("\nList is empty!\n");
        return 0;
    } else if (head -> next == NULL) {
        p = head;
        head = NULL;
        temp = p -> data;
    } else {
        q = head;
        p = head -> next;
        while (p -> next != NULL) {
            q = p;
            p = p -> next;
        }
        q -> next = NULL;
        temp = p -> data;
    }
    printf("\nDeleted element is: %d\n", temp);
    printList(head);
    return head;
}

// main function
void main() {
    node list = NULL;
    list = createList();
    printList(list);
    list = deleteEnd(list);
}