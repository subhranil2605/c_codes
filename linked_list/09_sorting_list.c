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
node sort(node head);
void swap(int* a, int* b);


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

// sorting
node sort(node head) {
    node p, q;
    if (head == NULL) {
        printf("\nThe list is empty.\n");
    }else {
        for (p = head; p != NULL; p = p -> next) {
            for (q = p -> next; q != NULL; q = q -> next) {
                if (p -> data > q -> data) {
                    swap(&p -> data, &q -> data);
                }
            }
        }
        return head;
    }

}

void swap(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


// main function
void main() {
    node list;
    list = createList();
    printList(list);
    list = sort(list);
    printf("After sorting => ");
    printList(list);
}