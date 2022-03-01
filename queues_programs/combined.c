#include<stdio.h>
#include<stdlib.h>


/* ------------------------------------------------------- */

int front = -1, rear = -1;


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

/* ------------------------------------------------------- */

/* Function prototypes */

// array 
void displayQAr(int que[]);
void insertQAr(int que[], int val, int MAX);
int deleteQAr(int que[]);

// linked list
node createNode();
queue createQueue();
queue insertQLi(queue q, int val);
queue deleteQLi(queue q);
int peekQLi(queue q);
void displayQLi(queue q);

// menu
void menuQAr();
void menuQLi();

/*------------- Array functions -------------*/

// Displaying the QUEUE
void displayQAr(int que[]) {
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
void insertQAr(int que[], int val, int MAX) {
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
int deleteQAr(int que[]) {
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



/*------------- Linked List functions -------------*/

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
    q -> rear = q -> front = NULL;
    return q;
}


// inserting element in queue
queue insertQLi(queue q, int val) {
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
queue deleteQLi(queue q) {
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
int peekQLi(queue q) {
    int c = (q -> front == NULL) ? -1 : q -> front -> data;
    return c;
}


// display queue
void displayQLi(queue q) {
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



// Menu functions

void menuQAr() {
    int MAX;
    int val, choice;
    
    printf("Enter the size of the array >> ");
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

        switch (choice) {
        case 1:
            printf("\nEnter the data to be inserted >> ");
            scanf("%d", &val);
            insertQAr(queue, val, MAX);
            break;
        case 2:
            val = deleteQAr(queue);
            if (val != -1) {
                printf("\nThe deleted element is: %d", val);
            }
            break;
        case 3:
            displayQAr(queue);
            break;
        case 4:
            exit(1);
        
        default:
            printf("\nWrong choice!!! Please choose correct value.\n");
            break;
        }
    }
}

// menu for linked list
void menuQLi() {
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