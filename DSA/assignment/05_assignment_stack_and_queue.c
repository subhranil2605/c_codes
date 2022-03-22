#include<stdio.h>
#include<stdlib.h>


/* ------------------------------------------------------- */

int front = -1, rear = -1;
int top = -1;


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

// Stack
// stack using array 
void displaySAr(int st[]);
void pushSAr(int st[], int val, int MAX);
int popSAr(int st[]);
int peekSAr(int st[]);

// stack using linked list 
node createNode();
node pushSLi(node top, int val);
node popSLi(node top);
int peekSLi(node top);
void displaySLi(node p);


// Queue
// array Queue
void displayQAr(int que[]);
void insertQAr(int que[], int val, int MAX);
int deleteQAr(int que[]);

// linked list Queue
node createNode();
queue createQueue();
queue insertQLi(queue q, int val);
queue deleteQLi(queue q);
int peekQLi(queue q);
void displayQLi(queue q);

// menu Queue
// stack
void menuSAr();
void menuSLi();

// queue
void menuQAr();
void menuQLi();

void menuStack();
void menuQueue();


/*------------- Common functions -------------*/
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


/*------------------------ Stack ------------------------*/
/*------------- Array functions -------------*/

// display
void displaySAr(int st[]) {
    int i;
    if (top == -1) {
        printf("\nThe STACK is Empty!!!\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("%d\n", st[i]);
        }
    }
}

// PUSH Operation
void pushSAr(int st[], int val, int MAX) {
    if (top == MAX - 1) {
        printf("\nSTACK is Full!!!\n");
    } else {
        top++;
        st[top] = val;
    }
}


// POP Operation
int popSAr(int st[]) {
    int val;
    if (top == - 1) {
        printf("\nSTACK is Empty!!!\n");
        return -1;
    } else {
        val = st[top];
        top--;
        return val;
    }
}


// PEEK Opeation
int peekSAr(int st[]) {
    if (top == -1) {
        printf("\nStack is empty\n");
        return -1;
    } else {
        return st[top];
    }
}


/*------------- Linked List functions -------------*/

// display
void displaySLi(node p) {
    if (p == NULL) {
        printf("\nThe STACK is empty!");
    } else {
        while (1) {
            if (p != NULL) {
                printf("%d-->", p -> data);
            } else {
                printf("NULL\n");
                break;
            }
            p = p -> next;
        }
    }
}


// PUSH Operation
node pushSLi(node head, int val) {
    node newNode;
    newNode = createNode();
    newNode -> data = val;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
    return head;
}


// POP Operation
node popSLi(node top) {
    node ptr;
    ptr = top;
    
    if (top == NULL) {
        printf("\nThe STACK is empty");
    } else {
        top = top -> next;
        printf("\nThe deleted item is: %d", ptr -> data);
        free(ptr);
    }
    return top;
}


// PEEK Opeation
int peekSLi(node top){
    if (top == NULL) {
        printf("\nThe STACK is empty\n");
        return -1;
    } else {
        return top -> data;
    }   
}


/*------------------------------------------------*/

/*------------------------ Queue ------------------------*/
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

/*------------------------------------------------*/


// Menu functions

/* ------------------------ Stack ------------------------ */
// array menu function 
void menuSAr() {
    int choice, val, max;

    printf("Enter the amount of elements to be inserted in the stack >> ");
    scanf("%d", &max);
    int st[max];

    while (1) {
        printf("\n====================================================\n");
        printf("Press 1: PUSH\n");
        printf("Press 2: POP\n");
        printf("Press 3: PEEK\n");
        printf("Press 4: Display\n");
        printf("Press 5: Exit");
        printf("\n====================================================\n");
        printf("\nEnter Your Choice >> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the number to be pushed on stack >> ");
                scanf("%d", &val);
                pushSAr(st, val, max);
                break;
            case 2:
                val = popSAr(st);
                if (val != -1) {
                    printf("\nThe deleted data from the stack is: %d", val);
                }
                break;
            case 3:
                val = peekSAr(st);
                if (val != -1) {
                    printf("\nThe top most element is: %d", val);
                }
                break;
            case 4:
                printf("\nCurrent Stack is\n");
                displaySAr(st);
                break;
            case 5:
                exit(1);
            default:
                printf("\nWrong Choice\n");
                break;
        }
    }
}

// Linked list menu
void menuSLi() {
    int choice, val;
    node top = NULL;

    while (1) {
        printf("\n====================================================\n");
        printf("Press 1: PUSH\n");
        printf("Press 2: POP\n");
        printf("Press 3: PEEK\n");
        printf("Press 4: Display\n");
        printf("Press 5: Exit");
        printf("\n====================================================\n");
        printf("\nEnter Your Choice >> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the number to be pushed on stack >> ");
                scanf("%d", &val);
                top = pushSLi(top, val);
                break;
            case 2:
                top = popSLi(top);
                break;
            case 3:
                val = peekSLi(top);
                if (val != -1) {
                    printf("\nThe top most element is: %d", val);
                }
                break;
            case 4:
                printf("\nCurrent Stack is\n");
                displaySLi(top);
                break;
            case 5:
                exit(1);
            default:
                printf("\nWrong Choice\n");
                break;
        }
    }
}


/* ------------------------ Queue ------------------------ */
// menu for array
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
        printf("Press 4: Exit");
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
            // break;
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
                que = insertQLi(que, val);
                break;
            case 2:
                printf("\nDeleting...\n");
                que = deleteQLi(que);
                break;
            case 3:
                val = peekQLi(que);
                (val == -1) ? printf("\nQUEUE is empty.\n") 
                            : printf("\nThe front element is: %d\n", val);  
                break;
            case 4:
                printf("\nCurrent QUEUE is: ");
                displayQLi(que);
                break;
            case 5:
                exit(1);
            
            default:
                printf("\nWrong choice!!!\n");
                break;
        }
    }
}



// menu for stack array or linked list
void menuStack() {
    int choice;

    while (1) {
        printf("\n============================\n");
        printf("Press 1: Stack Using Array\n");
        printf("Press 2: Stack Using Linked List\n");
        printf("Press 3: Exit");
        printf("\n============================\n");
        printf("Enter Your Choice >> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nCreating STACK Using Array...\n");
                menuSAr();
                break;
            case 2:
                printf("\nCreating STACK Using Linked List...\n");
                menuSLi();
                break;
            case 3:
                exit(1);
            default:
                printf("\nWrong Choice\n");
                break;
        }
    }
}

// menu for queue array or linked list
void menuQueue() {
    int choice;
    while (1) {
        printf("\n===============\n");
        printf("Press 1: Create QUEUE using Array.\n");
        printf("Press 2: Create QUEUE using Linked List.\n");
        printf("Press 3: Exit");
        printf("\n===============\n");

        printf("\nEnter your choice >> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nCreating QUEUE using Array...\n\n");
                menuQAr();
                break;
            case 2:
                printf("\nCreating QUEUE using Linked List...\n\n");
                menuQLi();
                break;
            case 3:
                exit(1);
            
            default:
                printf("\nWrong choice!!!\n");
                break;
        }
    }
}



/* ----------------------------- main function ----------------------------- */
void main() {
    int choice;
    while (1) {
        printf("\n===============\n");
        printf("Press 1: Create a STACK.\n");
        printf("Press 2: Create a QUEUE.\n");
        printf("Press 3: Exit");
        printf("\n===============\n");

        printf("\nEnter your choice >> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nCreating STACK...\n\n");
                menuStack();
                break;
            case 2:
                printf("\nCreating QUEUE...\n\n");
                menuQueue();
                break;
            case 3:
                exit(1);
            
            default:
                printf("\nWrong choice!!!\n");
                break;
        }
    }
}