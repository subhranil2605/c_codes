#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
};

typedef struct node* node;


//queue
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


// Inserting element into the queue
queue enQueue(queue q) {
    node newNode;
    int value;

    // value = 5;
    
    newNode = createNode();
    printf("Enter the data to be inserted >> ");
    scanf("%d", &value);
    newNode -> data = value;

    if (q -> front == NULL && q -> rear == NULL) {
        q -> front = q -> rear = newNode;
    } else {
        q -> rear -> next = newNode;
        q -> rear = newNode;
        newNode -> next = q -> front;
    }

    return q;
}


// deleting from the queue
queue deQueue(queue q) {
    if (q -> front == NULL && q -> rear == NULL) {
        printf("The queue is empty!!!");
    } else if (q -> front == q -> rear){
        q -> front = q -> rear = NULL;
    } else {
        q -> front = q -> front -> next;
        q -> rear -> next = q -> front;
    }
    return q;
}


// peek
void peek(queue q) {
    (q -> front == NULL && q -> rear == NULL) ? printf("Queue is empty\n") 
    : printf("The front of the Queue is %d", q -> front -> data);
}


// displaying the queue
void display(queue q) {
    node p;

    if (q -> front == NULL && q -> rear == NULL) {
        printf("The queue is empty!!!\n");
    } else {
        p = q -> front;  
        while (p != q -> rear) {
            printf("-->%d", p -> data);
            p = p -> next;
        }
        printf("-->%d---\n", p -> data);
    }
}



void main() {
    queue que;

    que = NULL;
    que = createQueue();

    que = enQueue(que);
    que = enQueue(que);
    que = enQueue(que);

    display(que);

    // que = deQueue(que);

    peek(que);
}