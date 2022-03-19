#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
};

typedef struct node* node;



/* ------------- Function Prototypes ------------- */ 
void display(node);
node createNode();
node insertEnd(node);
node createList();
void swap(int* a, int* b);
node sortAsc(node);
node sortDesc(node);

// menus
node menuDelete(node);
node menuSort(node);
node menuMain(node);



/* ------------- Function Declarations ------------- */ 

// displaying the list
void display(node p) {
    if (p == NULL) {
        printf("\nThe list is empty\n");
    } else {
        while (p != NULL) {
            printf("%d-->", p -> data);
            p = p -> next;
        }
        printf("NULL\n");
    }
}


// create a single node
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


// inserting from the end 
node insertEnd(node head) {
    node newNode, p; 
    int value;

    newNode = createNode();
    printf("Enter the data to be inserted >> ");
    scanf("%d", &value);
    newNode -> data = value;

    if (head == NULL) {
        return newNode;
    } else {
        p = head;
        while (p -> next != NULL) {
            p = p -> next;
        }
        p -> next = newNode;
    }
    return head;
}


// creating list
node createList() {
    node head; 
    char ch = 'y';

    head = NULL;

    while (ch != 'q') {
        head = insertEnd(head);

        printf("\nPress 'q' to stop OR Press anything to continue >> ");
        scanf("\n%c", &ch);
    }

    return head;
}


// swapping
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


/* ------------- Menu Fucntions ------------- */ 

// delete menu
node menuDelete(node head) {
    int choice;

    printf("\n============ Delete Menu ==============\n");
    printf("Press 1: Delete from the Beginning\n");
    printf("Press 2: Delete from the End\n");
    printf("Press 3: Delete from any Position\n");
    printf("Press 4: Delete after a Node\n");
    printf("Press 5: Delete before a Node\n");
    printf("Press 6: Delete a Specific Node\n");
    printf("Press 7: EXIT");
    printf("\n==================================\n");
    printf("Enter your choice >> ");
    scanf("%d", &choice);


    switch (choice) {
        case 1:
            printf("\nDeleting from the beginning...\n");
            break;
        case 2:
            printf("\nDeleting from the end...\n");
            break;
        case 3:
            printf("\nDeleting from specific position...\n");
            break;
        case 4:
            printf("\nDeleting after a node...\n");
            break;
        case 5:
            printf("\nDeleting before a node...\n");
            break;
        case 6:
            printf("\nDeleting a specific node...\n");
            break;
        case 7:
            exit(1);
            break;
        
        default:
            printf("\nIncorrect choice!!!\n");
            head = menuDelete(head);
            break;
    }


    return head;
}


// sort menu
node menuSort(node head) {
    int choice;

    printf("\n============ Sort Menu ==============\n");
    printf("Press 1: Sort Ascending\n");
    printf("Press 2: Sort Descending\n");
    printf("Press 3: EXIT");
    printf("\n==================================\n");
    printf("Enter your choice >> ");
    scanf("%d", &choice);


    switch (choice) {
        case 1:
            printf("\nSorting in Ascending Order...\n");
            printf("Current list is: \n");
            display(head);
            head = sortAsc(head);
            printf("\nAfter sorting the list is: \n");
            display(head);
            break;
        case 2:
            printf("\nSorting in Descending Order...\n");
            printf("Current list is: \n");
            display(head);
            head = sortDesc(head);
            printf("\nAfter sorting the list is: \n");
            display(head);
            break;
        case 3:
            exit(1);
            break;
        
        default:
            printf("\nIncorrect choice!!!\n");
            head = menuSort(head);
            break;
    }


    return head;
}


// main menu
node menuMain(node head) {
    int choice;
    
    while (1) {
        printf("\n==================================\n");
        printf("Press 1: DISPLAY\n");
        printf("Press 2: DELETE\n");
        printf("Press 3: SORT\n");
        printf("Press 4: REVERSE\n");
        printf("Press 5: MERGE\n");
        printf("Press 6: EXIT");
        printf("\n==================================\n");
        printf("Enter your choice >> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nDisplaying...\n");
                display(head);
                break;
            case 2:
                printf("\nDeleting...\n");
                head = menuDelete(head);
                break;
            case 3:
                printf("\nSorting...\n");
                head = menuSort(head);
                break;
            case 4:
                printf("\nReversing...\n");
                break;
            case 5:
                printf("\nMerging..\n.");
                break;
            case 6:
                exit(1);
                break;
            
            default:
                printf("\nIncorrect choice!!!\n");
                head = menuMain(head);
                break;
        }
    }

    return head;
}




/* ------------- Main Fucntion ------------- */ 

void main() {
    node list;
    list = NULL;

    // creating a list for doing the operations on it
    list = createList(list);

    printf("\nThe Created List is\n");
    display(list);


    // main menu calling
    list = menuMain(list);
}