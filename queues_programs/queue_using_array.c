#include<stdio.h>
#include<stdlib.h>


int front = -1, rear = -1;


// Function prototypes
void display(int que[]);
void insert(int que[], int val, int MAX);
int delete(int que[]);


// Displaying the QUEUE
void display(int que[]) {
    int i;
    if (front == -1 || front > rear) {
        printf("\nQUEUE is Empty!!!\n");
    } else {
        printf("\nThe QUEUE is: ");
        for (i = front; i <= rear; i++) {
            printf("%d -> ", que[i]);
        }
        printf("\n");
    }
}


// Inserting 
void insert(int que[], int val, int MAX) {
    if (rear == MAX - 1) {
        printf("The QUEUE is FULL!!!");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        que[rear] = val;
    } else {
        rear++;
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
    int MAX;
    int val, choice;
    
    printf("Enter the size of the array: ");
    scanf("%d", &MAX);
    int queue[MAX];

    while (1) {
        printf("\n=========================\n");
        printf("Press 1: Insert\n");
        printf("Press 2: Delete\n");
        printf("Press 3: Display\n");
        printf("Press 3: Exit");
        printf("\n=========================\n");
        printf("\nEnter your choice >> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be inserted >> ");
            scanf("%d", &val);
            insert(queue, val, MAX);
            break;
        case 2:
            val = delete(queue);
            if (val != -1) {
                printf("\nThe deleted element is: %d", val);
            }
            break;
        case 3:
            display(queue);
            break;
        case 4:
            exit(1);
        
        default:
            printf("\nWrong choice!!! Please choose correct value.\n");
            break;
        }
    }
}