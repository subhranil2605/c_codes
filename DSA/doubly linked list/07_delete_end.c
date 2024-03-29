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

// deleting from the last
node deleteEnd(node head) {
    node p;
    int deletedItem;
    if (head == NULL) {
        printf("The list is empty!!!\n");
    } else {
        // if the list has only one component
        if (head -> next == NULL) {
            deletedItem = head -> data;
            free(head);
            head = NULL;
            printf("The deleted element is: %d\n", deletedItem);
        }else {
            p = head;
            while (p -> next != NULL) {
                p = p -> next;
            }
            printf("The deleted element is: %d\n", p -> data);
            p = p -> prev;
            p -> next = NULL;
        }

    }
    return head;
}



void main() {
    node list;

    list = insertEnd(list);
    // list = insertEnd(list);
    // list = insertEnd(list);   

    display(list);

    list = deleteEnd(list);
    display(list);
}
