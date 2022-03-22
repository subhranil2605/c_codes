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
queue delete(queue q);
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
    ptr -> data = val;

    if (q -> rear == NULL) {
        q -> front = q -> rear = ptr; // both REAR and FRONT is the new inserted node
    } else {
        q -> rear -> next = ptr;    // inserting at the last
        q -> rear = ptr;            // setting the pointer REAR at the new inserted node
    }
    return q;
}


// deletion
queue delete(queue q) {
    int val;
    node p, temp;

    p = q -> front;
    if (p == NULL) {
        printf("\nThe QUEUE is empty!!! So, no element is deleted\n");
        return q;
    } else {
        temp = p;
        p = p -> next;
        q -> front = p;
        if (p == NULL) {
            q -> rear = NULL;
        }
        printf("\nThe deleted element is %d\n", temp -> data);
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
        printf("\nThe QUEUE is EMPTY.\n");
    } else {
        while (1) {
            if (ptr != q -> rear) {
                printf("%d->", ptr -> data);
            } else {
                printf("%d\n", ptr -> data);
                break;
            }
            ptr = ptr -> next;
        }
    }
}


// main function
void main() {
    queue que;
    int choice, val;

    que = createQueue();

    while (1) {
        printf("\n============================\n");
        printf("Press 1: Insert\n");
        printf("Press 2: Delete\n");
        printf("Press 3: Peek\n");
        printf("Press 4: Display\n");
        printf("Press 5: Exit");
        printf("\n============================\n");
        printf("\nEnter your choice >> ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("\nInserting...\n");
                printf("\nEnter the value to be inserted >> ");
                scanf("%d", &val);
                que = insert(que, val);
                break;
            case 2:
                printf("\nDeleting...\n");
                que = delete(que);
                break;
            case 3:
                val = peek(que);
                (val == -1) ? printf("\nQUEUE is empty.\n") 
                            : printf("\nThe front element is: %d\n", val);  
                break;
            case 4:
                printf("\nCurrent QUEUE is: ");
                display(que);
                break;
            case 5:
                exit(1);
            
            default:
                printf("\nWrong choice!!!\n");
                break;
        }
    }

}