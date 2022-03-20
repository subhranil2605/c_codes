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


// delete at any position
node deletePos(node head) {
    node current;
    int temp, pos, i;

    printf("\nYour current list is : \n");
    display(head);

    printf("\nEnter the position of the node to delete(starting from 0):: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("\nList is empty!\n");
        return 0;
    } else {
        if (pos == 0) {
            temp = head -> data;
            head = head -> next;
            head -> prev = NULL;
        } else {
            current = head;
            for (i = 0; i < pos; i++) {
                current = current -> next;
                if (current == NULL) {
                    printf("\nIncorrect position! Indexing out of range.\n");
                    return head;
                }
            }
            temp = current -> data;
            
            // if the element is at last
            if (current -> next == NULL) {  
                current = current -> prev;
                current -> next = NULL;
            } else {
                current -> prev -> next = current -> next;
                current -> next -> prev = current -> prev;
            }
        }
    }
    printf("\nDeleted element is: %d\n", temp);
    display(head);
    return head;
}



void main() {
    node list;

    list = insertEnd(list);
    list = insertEnd(list);
    list = insertEnd(list);   

    display(list);

    list = deletePos(list);
}
