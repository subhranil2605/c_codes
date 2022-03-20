/* ------------ Assignment 7 ------------ */ 
/* ------------ Subhranil Sarkar ------------ */ 
/* ------------ M.Sc. Data Science 1st Semester ------------ */ 
/* ------------ University of Kalyani ------------ */ 
/* ------------ 20th March, 2022 ------------ */ 


#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node* node;


/* ------------ Function prototypes ------------ */ 

node createNode();
void display(node );
node insertBeg(node );
node createListBeg();
node insertEnd(node);
node createListEnd();
node insertPos(node); 

// menus
node menuInsert(node);
node menuDelete(node);
node menuSort(node);
node menuMain(node);


/* ------------ Function declarations ------------ */ 

// creating a single node
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


// displaying 
void display(node p) {
    if (p == NULL) {
        printf("The list is empty\n");
    } else {
        printf("NULL");
        while (p != NULL) {
            printf("<--%d-->", p -> data);
            p = p -> next;
        }
        printf("NULL\n");
    }
}


// inserting into the list at front
node insertBeg(node head) {
    node newNode;
    int value;

    newNode = createNode();

    printf("Enter the number to be inserted >> ");
    scanf("%d", &value);

    newNode -> data = value;

    if (head == NULL) {
        return newNode;
    } else {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
    return head;
}



// creating list with inserting from the start
node createListBeg() {
    node head;
    char ch = 'y';

    head = NULL;

    while (ch != 'q') {
        head = insertBeg(head);

        printf("\nPress 'q' to stop OR Press anything to continue >> ");
        scanf("\n%c", &ch);
    }

    return head;
}

// inserting at the end
node insertEnd(node head) {
    node newNode, p;
    int value;

    newNode = createNode();

    printf("Enter the number to be inserted >> ");
    scanf("%d", &value);

    newNode -> data = value;

    if (head == NULL) {
        return newNode;
    } else {
        p = head;
        while (p -> next != NULL) {
            p = p -> next;
        }
        newNode -> prev = p;
        p -> next = newNode;
    }
    return head;
}


// creating list with inserting from the end
node createListEnd() {
    node head;
    char ch = 'y';

    head = NULL;

    while (ch != 'q') {
        head = insertBeg(head);

        printf("\nPress 'q' to stop OR Press anything to continue >> ");
        scanf("\n%c", &ch);
    }

    return head;
}


// insert any
node insertPos(node head) {
    int choice, i, value;
    node current, newNode;

    printf("\nYour current list is : \n");
    display(head);

    printf("\nEnter the position where you want to insert the new value (starting from 0) >> ");
    scanf("%d", &choice);

    newNode = createNode();
    printf("Enter the data >>");
    scanf("%d", &value);
    newNode -> data = value;

    // inserting at the beginning
    if (choice == 0) {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    } else {          
        current = head;
        for (i = 0; i < choice; i++) {
            current = current -> next;

            if (current == NULL) {
                printf("\nIndex out of range!\nReturning the current list:\n");
                return head;
            }
        }
        current -> prev -> next = newNode;         // previous node's next node is the new node
        newNode -> prev = current -> prev;         // new node's previous is the prev node
        newNode -> next = current;      // new node's next node is the current node
        current -> prev = newNode;      // new node's previous node is the newnode
    }
    return head;
    
}

// deleting from the front
node deleteBeg(node head) {
    node p;
    int deletedItem;
    if (head == NULL) {
        printf("The list is empty!!!\n");
    } else {
        if (head -> next == NULL) {
            deletedItem = head -> data;
            free(head);
            head = NULL;
            printf("The deleted element is: %d\n", deletedItem);
        } else {
            p = head;
            head = head -> next;            // head is now the 2nd element
            head -> prev = NULL;            // new head's previous node is now NULL
            printf("The deleted element is: %d\n", p -> data);
        }
    }
    return head;
}


// deleting from the last
node deleteEnd(node head) {
    node p;
    int deletedItem;
    if (head == NULL) {
        printf("The list is empty!!!\n");
    } else {
        // if the list has only one component
        if (head -> next == NULL) {
            deletedItem = head -> data;
            free(head);
            head = NULL;
            printf("The deleted element is: %d\n", deletedItem);
        }else {
            p = head;
            while (p -> next != NULL) {
                p = p -> next;
            }
            printf("The deleted element is: %d\n", p -> data);
            p = p -> prev;
            p -> next = NULL;
        }

    }
    return head;
}


// delete at any position
node deletePos(node head) {
    node current;
    int temp, pos, i;

    printf("\nYour current list is : \n");
    display(head);

    printf("\nEnter the position of the node to delete(starting from 0):: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("\nList is empty!\n");
        return 0;
    } else {
        if (pos == 0) {
            temp = head -> data;
            head = head -> next;
            head -> prev = NULL;
        } else {
            current = head;
            for (i = 0; i < pos; i++) {
                current = current -> next;
                if (current == NULL) {
                    printf("\nIncorrect position! Indexing out of range.\n");
                    return head;
                }
            }
            temp = current -> data;
            
            // if the element is at last
            if (current -> next == NULL) {  
                current = current -> prev;
                current -> next = NULL;
            } else {
                current -> prev -> next = current -> next;
                current -> next -> prev = current -> prev;
            }
        }
    }
    printf("\nDeleted element is: %d\n", temp);
    display(head);
    return head;
}




/* ------------ Menus ------------ */ 

// insert menu
node menuInsert(node head) {
    int choice;

    printf("\n============ Insert Menu ==============\n");
    printf("Press 1: Insert at the Beginning\n");
    printf("Press 2: Insert at the End\n");
    printf("Press 3: Insert at the specific position\n");
    printf("Press 4: EXIT");
    printf("\n==================================\n");
    printf("Enter your choice >> ");
    scanf("%d", &choice);


    switch (choice) {
        case 1:
            printf("\nInserting at the beginning...\n");
            head = insertBeg(head);
            break;
        case 2:
            printf("\nInserting at the end...\n");
            head = insertEnd(head);
            break;
        case 3:
            printf("\nInserting at the specific position...\n");
            head = insertPos(head);
            break;
        case 4:
            exit(1);
            break;
        
        default:
            printf("\nIncorrect choice!!!\n");
            head = menuInsert(head);
            break;
    }
    return head;
}


// delete menu
node menuDelete(node head) {
    int choice;

    printf("\n============ Delete Menu ==============\n");
    printf("Press 1: Delete from the Beginning\n");
    printf("Press 2: Delete from the End\n");
    printf("Press 3: Delete from the specific position\n");
    printf("Press 4: EXIT");
    printf("\n==================================\n");
    printf("Enter your choice >> ");
    scanf("%d", &choice);


    switch (choice) {
        case 1:
            printf("\nDeleting from the beginning...\n");
            head = deleteBeg(head);
            break;
        case 2:
            printf("\nDeleting from the end...\n");
            head = deleteEnd(head);
            break;
        case 3:
            printf("\nDeleting from the specific position...\n");
            head = deletePos(head);
            break;
        case 4:
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
    node list2;
    list2 = NULL;
    
    while (1) {
        printf("\n=============== Main Menu ===============\n");
        printf("Press 1: DISPLAY\n");
        printf("Press 2: INSERT\n");
        printf("Press 3: DELETE\n");
        printf("Press 4: SORT\n");
        printf("Press 5: REVERSE\n");
        printf("Press 6: MERGE\n");
        printf("Press 7: EXIT");
        printf("\n==================================\n");
        printf("Enter your choice >> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nDisplaying...\n");
                display(head);
                break;
            case 2:
                printf("\nInserting...\n");
                head = menuInsert(head);
                display(head);
                break;
            case 3:
                printf("\nDeleting...\n");
                head = menuDelete(head);
                break;
            case 4:
                printf("\nSorting...\n");
                head = menuSort(head);
                break;
            case 5:
                printf("\nReversing...\n");

                printf("Current list is: \n");
                display(head);

                head = reverse(head);

                printf("\nAfter Reversing the list is: \n");
                display(head);
                break;
            case 6:
                printf("\nMerging...\n");
                printf("\n\nCreating another list....\n");
                list2 = createList(list2);

                printf("\nThe first list is\n");
                display(head);

                printf("\nThe second list is\n");
                display(list2);

                head = concat(head, list2);
                printf("\nAfter Merging them together the list is\n");
                display(head);
                break;
            case 7:
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


/* ------------ Main funcion ------------ */ 
void main() {
    node list; 
    list = NULL;

}