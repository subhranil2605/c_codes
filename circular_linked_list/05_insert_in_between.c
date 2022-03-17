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
node insertAfter(node last, int data) {
    node newNode, p;
    int item;

    if (last == NULL) {
        printf("The list is empty!!!\n");
    } else {
        newNode = createNode();
        newNode -> data = data;

        printf("Enter the element after which new data is to be inserted >> ");
        scanf("%d", &item);

        node p = last -> next;  // it points to the head of the list
    
        while (1) {
            if (p != last) {
                if (p -> data == item) {
                    newNode -> next = p -> next;
                    p -> next = newNode;
                } else {
                    printf("%d is not in the list!!!", item);
                }
            } else {
                if (p -> data == item) {
                    newNode -> next = p -> next;
                    p -> next = newNode;
                    last = newNode;
                } else {
                    printf("%d is not in the list!!!", item);
                }
                break;
            }
            p = p -> next;
        }
        
    }
    return last;
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

    last = insertAfter(last, 6);
    display(last);
}