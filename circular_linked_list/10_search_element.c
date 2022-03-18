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




// displaying the circular linked list
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





// searching element
void search(node last) {
    node p;
    int item, count = 0, flag=0;

    if (last == NULL) {
        printf("The list is empty\n");
    } else {
        p = last -> next;

        printf("Enter the item you want to search >> ");
        scanf("%d", &item);

        while (1) {
            if (p != last) {
                if (p -> data == item) {
                    printf("The element is found at position: %d\n", count + 1);
                    flag = 1;
                    break;
                } else {
                    flag = 0;
                }
            } else {
                // if the item is at the end
                if (p -> data == item) {
                    printf("The element is found at position: %d\n", count + 1);
                    flag = 1;
                }
                break;
            }
            count++;
            p = p -> next;
        }

        if (flag != 1) {
            printf("The item is not present in the list!!!\n");
            return;
        }
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
    last = insertEnd(last, 5);
    last = insertEnd(last, 6);

    printf("The list is: \t");
    display(last);

    search(last);
}