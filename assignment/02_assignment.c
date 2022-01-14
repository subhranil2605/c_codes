#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
};

typedef struct node* node;


/* function declarations */

// Menus
node createMenu(node list);
node insertMenu(node list);
node insertAnyMenu(node list);
node deleteMenu(node list);

// node functions
node createNode();
node insertBeg(node head);
node insertEnd(node head);
node createListBeg();
node createListEnd();
node printList(node p);
node insertAfter(node head);
node insertBefore(node head);
node insertAny(node head);
node createNodeWithValue();
node deleteBeg(node head);
node deleteEnd(node head);
node deleteAny(node head);
node sortAsc(node head);
node sortDesc(node head);
void swap(int* a, int* b);


/* -------------------------------------------------------------------- */
/* --------------------------- Menu Funtions ----------------------------------------- */
/* -------------------------------------------------------------------- */

// function definitions

node createMenu(node list) {
    int choice;

    printf("\nPress 1: Insert from the Beginning\n");
    printf("Press 2: Insert from the End\n");
    printf("\nEnter your choice to create a list:: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nInserting from the beginning...\n");
            list = createListBeg();
            break;
        case 2:
            printf("\nInserting from the end...\n");
            list = createListEnd();
            break;
        default:
            printf("\nIncorrect choice!\n");
            break;
    }
    printf("\nSuccessfully Created a list.\nThe list is: \n");
    printList(list);
    return list;
}

// Insertion menu
node insertMenu(node list) {
    int choice;

    printf("\nPress 1: Insert at the Beginning\n");
    printf("Press 2: Insert at the End\n");
    printf("Press 3: Insert at any position\n");
    printf("\nEnter your choice to create a list:: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nYour current list is: ");
            printList(list);
            printf("\nInserting at the beginning...\n");
            list = insertBeg(list);
            break;
        case 2:
            printf("\nYour current list is: ");
            printList(list);
            printf("\nInserting at the end...\n");
            list = insertEnd(list);
            break;
        case 3:
            printf("\nInserting any position...\n");
            list = insertAnyMenu(list);
            break;
        default:
            printf("Incorrect choice");
            break;
    }
    printf("\nSuccessfully Inserted!\n");
    printf("Your current list is: ");
    printList(list);
    return list;
}

// Inserting element menu
node insertAnyMenu(node list) {
    int choice;

    printf("\nPress 1: Insert After a Node.\n");
    printf("Press 2: Insert Before a Node.\n");
    printf("Press 3: Insert at Specific Position.\n");
    printf("\nEnter your choice:: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Inserting After...\n");
            list = insertAfter(list);
            break;
        case 2:
            printf("Inserting Before...\n");
            list = insertBefore(list);
            break;
        case 3:
            printf("Inserting at any position...\n");
            list = insertAny(list);
            break;
        default:
            printf("Incorrect choice");
            break;
    }
}

// delete menu
node deleteMenu(node list) {
    int choice;

    printf("\nPress 1: Delete the first node.\n");
    printf("Press 2: Delete the last node.\n");
    printf("Press 3: Delete at Specific Position\n");
    printf("\nEnter your choice:: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Deleting the first element...\n");
            list = deleteBeg(list);
            break;
        
        case 2:
            printf("Deleting the last element...\n");
            list = deleteEnd(list);
            break;
        
        case 3:
            printf("Deleting the specific element...\n");
            list = deleteAny(list);
            break;
        
        default:
            printf("Incorrect choice");
            break;
    }
    return list;
}


// Sorting menu
node sortingMenu(node list) {
    int choice;

    printf("\nPress 1: Sort Ascending Order.\n");
    printf("Press 2: Sort Descending Order.\n");
    printf("\nEnter your choice:: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Sorting in ascending order...\n");
            list = sortAsc(list);
            break;
        
        case 2:
            printf("Sorting in descending order...\n");
            list = sortDesc(list);
            break;
        
        default:
            printf("Incorrect choice");
            break;
    }
    return list;
}
/* -------------------------------------------------------------------- */
/* ----------------- End of Menus --------------------------   */
/* -------------------------------------------------------------------- */



// displaying the whole list
node printList(node p) {
    while(1) {
        if(p != NULL) {
            printf("%d-->", p -> data);
        } else {
            printf("NULL\n");
            break;
        }
        p = p -> next;
    }
}


// create a node
node createNode() {
    node temp;
    temp = (node) malloc(sizeof(node));
    temp -> next = NULL;
    return temp;
}


// inserting at the beginning
node insertBeg(node head) {
    node newNode;
    int value;
    newNode = createNode();

    printf("Enter the data you want to insert into the list:: ");
    scanf("%d", &value);

    newNode -> data = value;
    
    if(head == NULL) {
        head = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
}


// creating list
node createListBeg() {
    char ch;
    node head;

    head = NULL;

    while (ch != 'q') {
        head = insertBeg(head);

        printf("\nPress 'q' to exit the loop OR press any key to continue:: ");
        scanf("\n%c", &ch);
    }
    return head;
}

// inserting at the end
node insertEnd(node head) {
    node newNode, p;
    int value;

    newNode = createNode();

    printf("Enter the value of the list:: ");
    scanf("%d", &value);

    newNode -> data = value;

    if (head == NULL) {
        return newNode;
    } else {
        p = head;
        while(p -> next != NULL) {
            p = p -> next;
        }
        p -> next = newNode;
    }
    return head;

}

// creating list
node createListEnd() {
    char ch;
    node head;
    int i = 0;

    head = NULL;

    while (ch != 'q') {
        head = insertEnd(head);
        printf("\nPress 'q' to exit the loop OR press any key to continue:: ");
        scanf("\n%c", &ch);
    }
    return head;
}


// insert after
node insertAfter(node head) {
    int choice, i, value;
    node ptr, newNode;

    printf("\nYour current list is : \n");
    printList(head);

    printf("\nEnter the position after which you want to insert the new node (starting from 0):: ");
    scanf("%d", &choice);

    newNode = createNodeWithValue();

    if (choice == 0) {
        // inserting at the beginning
        newNode -> next = head -> next;
        head -> next = newNode;
    } else {
        ptr = head;
        for (i = 0; i < choice; i++) {
            ptr = ptr -> next;
            if (ptr == NULL) {
                printf("\nIndex out of range!\nReturning the current list:\n");
                return head;
            }
        }
        newNode -> next = ptr -> next;
        ptr -> next = newNode;
    }
    return head;
    
}


// insert before
node insertBefore(node head) {
    int choice, i, value;
    node ptr, preptr, newNode;

    printf("\nYour current list is : \n");
    printList(head);

    printf("\nEnter the position before which you want to insert the new node (starting from 0):: ");
    scanf("%d", &choice);

    newNode = createNodeWithValue();

    if (choice == 0) {
        // inserting at the beginning
        newNode -> next = head;
        head  = newNode;
    } else {
        ptr = head;
        for (i = 0; i < choice; i++) {
            preptr = ptr;
            ptr = ptr -> next;
            if (ptr == NULL) {
                printf("\nIndex out of range!\nReturning the current list:\n");
                return head;
            }
        }
        preptr -> next = newNode;
        newNode -> next = ptr;
    }
    return head;
    
}


// insert any
node insertAny(node head) {
    int choice, i, value;
    node ptr, preptr, newNode;

    printf("\nYour current list is : \n");
    printList(head);

    printf("\nEnter the position where you want to insert the new value (starting from 0):: ");
    scanf("%d", &choice);

    newNode = createNodeWithValue();

    if (choice == 0) {
        // inserting at the beginning
        newNode -> next = head;
        head = newNode;
    } else {
        ptr = head;
        for (i = 0; i < choice; i++) {
            preptr = ptr;
            ptr = ptr -> next;
            if (ptr == NULL) {
                printf("\nIndex out of range!\nReturning the current list:\n");
                return head;
            }
        }
        preptr -> next = newNode;       // previous node's next node is the new node
        newNode -> next = ptr;          // new node's next is the node that sit on the desired position
    }
    return head;
    
}


node createNodeWithValue() {
    node newNode;
    int value;
    
    newNode = createNode();

    if (newNode == NULL) {
        printf("\nCould not create a new node!\n");
        return 0;
    }

    printf("\nEnter the new data:: ");
    scanf("%d", &value);
    newNode -> data = value;
    return newNode;
}

// delete at the beginning
node deleteBeg(node head) {
    node temp = NULL;
    if (head == NULL) {
        printf("\nList is empty!\n");
        return 0;
    } else {
        temp = head;
        head = head -> next;
        printf("\nThe deleted element is: %d\n", temp -> data);
    }
    printf("\nAfter deleting the list is => \n");
    printList(head);
    return head;
}


// delete at the end
node deleteEnd(node head) {
    node p, q;
    int temp;
    if (head == NULL) {
        printf("\nList is empty!\n");
        return 0;
    } else if (head -> next == NULL) {
        p = head;
        head = NULL;
        temp = p -> data;
    } else {
        q = head;
        p = head -> next;
        while (p -> next != NULL) {
            q = p;
            p = p -> next;
        }
        q -> next = NULL;
        temp = p -> data;
    }
    printf("\nDeleted element is: %d\n", temp);
    printf("\nAfter deleting the list is => \n");
    printList(head);
    return head;
}

// delete at any position
node deleteAny(node head) {
    node ptr, preptr;
    int temp, pos, i;

    printf("\nYour current list is : \n");
    printList(head);

    printf("\nEnter the position of the node to delete(starting from 0):: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("\nList is empty!\n");
        return 0;
    } else {
        if (pos == 0) {
            temp = head -> data;
            head = head -> next;
        } else {
            preptr = head;
            ptr = head;
            for (i = 0; i < pos; i++) {
                preptr = ptr;
                ptr = ptr -> next;
                if (ptr == NULL) {
                    printf("\nIncorrect position! Indexing out of range.\n");
                    return head;
                }
            }
            temp = ptr -> data;
            preptr -> next = ptr -> next;
        }
    }
    printf("\nDeleted element is: %d\n", temp);
    printf("Your list:: \n");
    printList(head);
    return head;
}

// creating list
node createList() {
    char ch;
    node head;

    head = NULL;

    while (ch != 'q') {
        head = insertBeg(head);

        printf("\nPress 'q' to exit the loop OR press any key to continue:: ");
        scanf("\n%c", &ch);
    }
    return head;
}

// sorting
node sortAsc(node head) {
    node p, q;
    if (head == NULL) {
        printf("\nThe list is empty.\n");
    }else {
        printf("\nYour current list is =>\t");
        printList(head);
        for (p = head; p != NULL; p = p -> next) {
            for (q = p -> next; q != NULL; q = q -> next) {
                if (p -> data > q -> data) {
                    swap(&p -> data, &q -> data);
                }
            }
        }
        printf("\nThe sorted list is =>\n");
        printList(head);
        return head;
    }

}

// descending sorting
node sortDesc(node head) {
    node p, q;
    if (head == NULL) {
        printf("\nThe list is empty.\n");
    }else {
        printf("\nYour current list is =>\t");
        printList(head);
        for (p = head; p != NULL; p = p -> next) {
            for (q = p -> next; q != NULL; q = q -> next) {
                if (p -> data < q -> data) {
                    swap(&p -> data, &q -> data);
                }
            }
        }
        printf("\nThe sorted list is =>\n");
        printList(head);
        return head;
    }

}

// swapping using call by reference
void swap(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


/* ----------------------Main Function-------------------------*/
void main() {
    int choice;
    node list = NULL;

    while (1) {
        printf("\n<====================================================>\n");
        printf("Press 1: Create a List\n");
        printf("Press 2: Display List\n");
        printf("Press 3: Insert an Element\n");
        printf("Press 4: Delete an Element\n");
        printf("Press 5: Sorting the List\n");
        printf("Press 6: Exit");
        printf("\n<====================================================>\n");
        printf("Enter your choice:: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nCreating a List...\n");
                list = createMenu(list);
                break;

            case 2:
                printf("\nDisplaying a List...\n");
                if (list != NULL) {
                    printList(list);
                } else {
                    printf("\nThe list is empty!\n");
                }
                break;

            case 3:
                printf("\nInserting into a List...\n");
                list = insertMenu(list);
                break;
            
            case 4:
                printf("\nDeleting an element from the list...\n");
                list = deleteMenu(list);
                break;
            
            case 5:
                printf("\nSorting...\n");
                list = sortingMenu(list);
                break;
            
            case 6:
                // exiting condition
                exit(1);
            
            default:
                printf("\nIncorrect choice!\n");
                break;
        }
    }
}