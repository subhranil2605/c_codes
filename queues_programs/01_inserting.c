#include<stdio.h>
#define MAX 3


int front = -1, rear = -1;
int queue[MAX];


// Function prototypes
void display(int que[]);
void insert(int que[], int val);


// Displaying the QUEUE
void display(int que[]) {
    int i;
    if (front == -1 || front > rear) {
        printf("\nQUEUE is Empty!!!\n");
    } else {
        for (i = 0; i <= rear; i++) {
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
    } else {
        rear++;
        que[rear] = val;
    }
}


// Main function
void main() {
    int val;
    display(queue);

    insert(queue, 5);
    insert(queue, 6);

    display(queue);

}