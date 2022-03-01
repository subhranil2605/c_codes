#include<stdio.h>
#include<stdlib.h>


// node
struct node {
    int data;
    struct node* next;
};

typedef struct node* node;

// queue
struct queue {
    node front;
    node rear;
};

typedef struct queue* queue;

// function prototypes
node createNode();
queue createQueue();
queue insert(queue q, int val);
int peek(queue q);
void display(queue q);


// creating a single node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    if (temp == NULL) {
        return NULL;
    } else {
        temp -> next = NULL;
        return temp;
    }
}


// createing queue
queue createQueue() {
    queue q;
    q = (queue) malloc(sizeof(queue));
    q -> rear = q -> front =NULL;
    return q;
}


// inserting element in queue
queue insert(queue q, int val) {
    node ptr;
    ptr = createNode();

    if (ptr == NULL) {
        printf("\nMemory is not allocated!\n");
        return q;
    } else {
        ptr -> data = val;

        if (q -> rear == NULL) {
            q -> front = q -> rear = ptr; // both REAR and FRONT is the new inserted node
        } else {
            q -> rear -> next = ptr;    // inserting at the last
            q -> rear = ptr;            // setting the pointer REAR at the new inserted node
        }
        return q;
    }
}


// peek
int peek(queue q) {
    int c = (q -> front == NULL) ? -1 : q -> front -> data;
    return c;
}


// display queue
void display(queue q) {
    node ptr;
    ptr = q -> front;
    if (ptr == NULL) {
        printf("\nThe QUEUE is EMPTY.");
    } else {
        while (1) {
            if (ptr != q -> rear) {
                printf("%d->", ptr -> data);
            } else {
                printf("%d->NULL\n", ptr -> data);
                break;
            }
            ptr = ptr -> next;
        }
    }
}


// main function
void main() {
    int val;
    queue que;

    que = createQueue(que);

    que = insert(que, 5);
    que = insert(que, 10);
    que = insert(que, 100);

    display(que);

    val = peek(que);

    (val == -1) ? printf("\nQUEUE is empty.\n") 
                : printf("\nThe value at the front of the queue is: %d\n", val);
}