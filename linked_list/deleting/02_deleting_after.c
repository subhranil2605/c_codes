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


// delete after a node
node deleteAfter(node head) {
    node current, next;
    int item;

    printf("Enter the element after which you want to delete >> ");
    scanf("%d", &item);

    if (head == NULL) {
        printf("The list is empty!!!\n");
    } else {
        if (head -> data == item) {
            printf("The deleted element is: %d", head -> next -> data);
            head -> next = head -> next -> next;
            return head;
        } else {
            current = head;
            while (current -> data != item) {
                current = current -> next;
                next = current -> next;

                if (current -> next == NULL) {
                    printf("Not in the list OR the last item\n");
                    return head;
                } 

            }
            printf("The deleted element is: %d\n", next -> data);
            current -> next = next -> next;
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

    list = deleteAfter(list);
    printList(list);

}