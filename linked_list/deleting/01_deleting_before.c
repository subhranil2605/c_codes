#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
};

typedef struct node* node;


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
node insertBeg(node head, int value) {
    node newNode;

    newNode = createNode();
    newNode -> data = value;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}


// delete before a node
node deleteBefore(node head) {
    node current, prev;
    int item;

    printf("Enter the element you want to delete >> ");
    scanf("%d", &item);

    if (head == NULL) {
        printf("The list is empty!!!\n");
    } else {
        if (head -> data == item) {
            printf("There's no data before this item!!!\n");
            return head;
        } else if (head -> next -> data == item) {
            printf("The deleted element is: %d\n", head -> data);
            head = head -> next;
            return head;
        } else {
            current = head;
            while (current -> next -> data != item) {
                prev = current;
                current = current -> next;

                if (current -> next == NULL) {
                    printf("Not in the list\n");
                    return head;
                } 

            }
            printf("The deleted element is: %d\n", current -> data);
            prev -> next = current -> next;

        }
    }
    return head;
}


// main function
void main() {
    node list;
    list = NULL;

    list = insertBeg(list, 5);
    list = insertBeg(list, 6);
    list = insertBeg(list, 100);
    list = insertBeg(list, 20);
    list = insertBeg(list, 10);
    list = insertBeg(list, 555);
    printList(list);

    list = deleteBefore(list);
    printList(list);

}