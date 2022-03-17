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



// deleting from the start
node deleteItem(node last, int data) {
    node p, deletedItem; 

    // if list is empty
    if (last == NULL) {
        printf("The list is empty");
    } else {
        // list consists of a single node
        if (last -> data == data && last -> next == last) {
            free(last);
            last = NULL;
        } else {
            p = last;
            // if the item at the end
            if (p -> data == data) {
                while (p -> next != last) {
                    p = p -> next;
                }
                p -> next = last -> next;
                last = p;
            } else {
                while (p -> next != last && p -> next -> data != data) {
                    p = p -> next;
                }
                if (p -> next -> data == data) {
                    deletedItem = p -> next;
                    p -> next = deletedItem -> next;
                    free(deletedItem);
                } 
            }
        }
    }
    return last;
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

    last = deleteItem(last, 4);
    display(last);

}