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


// insert beginning
node insertBeg(node last) {
    node newNode;
    int data;

    newNode = createNode();
    printf("Enter the data to be inserted >> ");
    scanf("%d", &data);

    newNode -> data = data;

    if (last == NULL) {
        last = newNode;
        newNode -> next = last;
    } else {
        newNode -> next = last -> next;
        last -> next = newNode;
    }
    return last;    
}


// creating a list
node createList() {
    node last;
    char ch='y';
    last = NULL;

    while (ch != 'q') {
        last = insertBeg(last);
        printf("\nPress 'q' to stop OR Press anyting to continue >> ");
        scanf("\n%c", &ch);
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
    
    last = createList();

    printf("The list is: \t");
    display(last);
}