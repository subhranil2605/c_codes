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

// concat
node concat(node a, node b) {
    node p;
    if (a == NULL) {
        return b;
    } 
    if (b == NULL){
        return a;
    } 
    p = a;
    while (a -> next != NULL) {
        a = a -> next;
    }
    b -> prev = a;
    a -> next = b;
    return p;
}




void main() {
    node list1, list2 ;

    list1 = NULL;
    list2 = NULL;

    list1 = insertEnd(list1);
    list1 = insertEnd(list1);
    list1 = insertEnd(list1);   

    display(list1);

    printf("\n\nAnother list\n");
    list2 = insertEnd(list2);
    list2 = insertEnd(list2);
    list2 = insertEnd(list2);   

    display(list2);


    printf("\n\nAfter merging\n");
    
    list1 = concat(list1, list2);
    display(list1);
}
