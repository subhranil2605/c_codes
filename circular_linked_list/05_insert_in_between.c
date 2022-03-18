#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node* node;


// create a single node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    if (temp == NULL) {
        return temp;
    } else {
        temp -> next = NULL;
        return temp;
    }
}


// adding element to a empty list
node creatingSingleElementList(node last, node newNode) {
    if (last != NULL) {
        return last;
    } else {
        last = newNode;
        newNode -> next = last;
        return last;
    }
}


// insert at the end
node insertEnd(node last, int data) {
    node newNode;

    newNode = createNode();
    newNode -> data = data;

    if (last == NULL) {
        last = creatingSingleElementList(last, newNode);
    } else {
        newNode -> next = last -> next;     // links between new last and the first node
        last -> next = newNode;             // new node is the current last node
        last = newNode;                     // set the last pointer to the new node
    }
    return last;    
}



// insert after a specific item
node insertAfter(node last) {
    node newNode, p;
    int data, item;
    
    if (last == NULL) {
        printf("The list is empty");
        return last;
    } else {
        printf("Enter the item after which new data to be inserted >> ");
        scanf("%d", &item);
        printf("Enter the data to be inserted >> ");
        scanf("%d", &data);
        newNode = createNode();
        newNode -> data = data;
        p = last -> next;

        do {
            if (p -> data == item) {
                newNode -> next = p -> next;
                p -> next = newNode;

                if (p == last) {
                    last = newNode;
                }
                return last;
            }
            p = p -> next;
        } while (p != last -> next);
        return last;
    }
}



void display(node last) {
    node p = last -> next;  // it points to the head of the list
    
    while (1) {
        if (p != last) {
            printf("-->%d", p -> data);
        } else {
            printf("-->%d---\n", p -> data);
            break;
        }
        p = p -> next;
    }
}


// main function
void main() {
    node last;
    last = NULL;
    
    last = insertEnd(last, 1);
    last = insertEnd(last, 2);
    last = insertEnd(last, 3);
    last = insertEnd(last, 4);

    printf("The list is: \t");
    display(last);

    last = insertAfter(last);
    display(last);
}