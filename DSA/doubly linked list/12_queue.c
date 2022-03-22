#include<stdio.h>
#include<stdlib.h>


// doubly node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node* node;


// queue
struct queue {
    struct node* front;
    struct node* rear;
};

typedef struct queue* queue;



// create a node
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

// creating queue
queue createQueue() {
    queue q;
    q = (queue) malloc(sizeof(queue));
    q -> rear = q -> front = NULL;
    return q;
}


// displaying 
void display(queue q) {
    node p;

    if (q -> front == NULL & q -> rear == NULL) {
        printf("The list is empty\n");
    } else {
        p = q -> front;
        printf("NULL");
        while (p != q -> rear) {
            printf("<--%d-->", p -> data);
            p = p -> next;
        }
        printf("<--%d-->NULL\n", p -> data);
    }
}


// enqueue
queue enQueue(queue q) {
    node newNode;
    int value;

    newNode = createNode();
    printf("Enter the data to be inserted >> ");
    scanf("%d", &value);
    newNode -> data = value;

    if (q -> front == NULL && q -> rear == NULL) {
        q -> front = q -> rear = newNode;
    } else {
        newNode -> prev = q -> rear;
        q -> rear -> next = newNode;
        q -> rear = newNode;
    }

    return q;
}


// dequeue
queue deQueue(queue q) {
    if (q -> front == NULL && q -> rear == NULL) {
        printf("The queue is empty!!!");
    } else if (q -> front == q -> rear){
        q -> front = q -> rear = NULL;
    } else {
        q -> front = q -> front -> next;
        q -> front -> prev = NULL;
    }
    return q;
}


// peek
void peek(queue q) {
    (q -> front == NULL && q -> rear == NULL) ? printf("Queue is empty\n") 
    : printf("The front of the Queue is %d", q -> front -> data);
}


// main function
void main() {
    queue que;
    que = NULL;

    que = createQueue();

    que = enQueue(que);
    que = enQueue(que);

    display(que);

    que = deQueue(que);
    que = deQueue(que);
    display(que);

}