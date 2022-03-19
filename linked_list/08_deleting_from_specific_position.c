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


// delete at any position
node deleteAny(node head) {
    node ptr, preptr;
    int temp, pos, i;

    printf("\nEnter the position of the node to delete(starting from 0):: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("\nList is empty!\n");
        return 0;
    } else {
        if (pos == 0) {
            temp = head -> data;
            head = head -> next;
        } else {
            preptr = head;
            ptr = head;
            for (i = 0; i < pos; i++) {
                preptr = ptr;
                ptr = ptr -> next;
                if (ptr == NULL) {
                    printf("\nIncorrect position! Indexing out of range.\n");
                    return head;
                }
            }
            temp = ptr -> data;
            preptr -> next = ptr -> next;
        }
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
    list = deleteAny(list);
}