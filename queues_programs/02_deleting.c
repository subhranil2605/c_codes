#include<stdio.h>
#define MAX 3


int front = -1, rear = -1;
int queue[MAX];


// Function prototypes
void display(int que[]);
void insert(int que[], int val);
int delete(int que[]);


// Displaying the QUEUE
void display(int que[]) {
    int i;
    if (front == -1 || front > rear) {
        printf("\nQUEUE is Empty!!!\n");
    } else {
        for (i = front; i <= rear; i++) {
            printf("%d\t", que[i]);
        }
        printf("\n");
    }
}


// Inserting 
void insert(int que[], int val) {
    if (rear == MAX - 1) {
        printf("The QUEUE is FULL!!!");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        que[rear] = val;
    } else {
        rear++;
        printf("The inserted value is --> %d\n", val);
        que[rear] = val;
    }
}

// deleting function
int delete(int que[]) {
    int val;
    if (front == -1 || front > rear) {
        printf("\nThe QUEUE is empty!!!");
        return -1;
    } else {
        val = que[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return val;
    }
}


// Main function
void main() {
    int val;
    display(queue);

    insert(queue, 5);
    display(queue);

    insert(queue, 6);
    display(queue);

    insert(queue, 10);
    display(queue);


    printf("\nDeleting the front element...\n");
    val = delete(queue);
    printf("The deleted element is %d\n", val);
    display(queue);

    val = delete(queue);
    printf("The deleted element is %d\n", val);
    display(queue);

    val = delete(queue);
    printf("The deleted element is %d\n", val);
    display(queue);
}