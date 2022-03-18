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
node insertEnd(node last) {
    node newNode;
    int data;

    newNode = createNode();
    printf("Enter the data to be inserted (from the end) >> ");
    scanf("%d", &data);

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


// creating a list
node createList() {
    node last;
    char ch='y';
    last = NULL;

    while (ch != 'q') {
        last = insertEnd(last);
        printf("\nPress 'q' to stop OR Press anyting to continue >> ");
        scanf("\n%c", &ch);
    }

    return last;
}




void display(node last) {
    node p;
    if (last == NULL) {
        printf("The list is empty\n");
    } else {
        p = last -> next;  // it points to the head of the list
        
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
}


// reverse
node reverse(node last) {
    node current, next, prev;

    if (last == NULL) {
        printf("The list is empty!\n");
    } else {
        // single element in the list
        if (last == last -> next) {
            printf("It is the single list. So, no reverse is possible!!\n");
        } else {
            current = last -> next;     // first node
            next = current -> next;     // second node

            while (current != last) {
                prev = current;
                current = next;
                next = current -> next;
                current -> next = prev;
            } 

            next -> next = last;
            last = next;
        }
    }
    return last;
}


// main function
void main() {
    node last;
    last = NULL;
    
    last = createList();

    printf("The list is: \t");
    display(last);

    last = reverse(last);
    display(last);
}