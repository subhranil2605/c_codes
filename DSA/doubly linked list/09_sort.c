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

// swap
void swap(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}



// ascending sorting
node sortAsc(node head) {
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


// descending sorting
node sortDesc(node head) {
    node p, q;
    if (head == NULL) {
        printf("\nThe list is empty.\n");
    }else {
        for (p = head; p != NULL; p = p -> next) {
            for (q = p -> next; q != NULL; q = q -> next) {
                if (p -> data < q -> data) {
                    swap(&p -> data, &q -> data);
                }
            }
        }
        return head;
    }

}






void main() {
    node list;

    list = insertEnd(list);
    list = insertEnd(list);
    list = insertEnd(list);   

    display(list);

    list = sortDesc(list);
    display(list);
}
