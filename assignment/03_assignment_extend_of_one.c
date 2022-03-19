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

node deleteBeg(node);
node deleteEnd(node);
node deletePos(node);
node deleteAfter(node);
node deleteBefore(node);
node deleteNode(node);

node sortAsc(node);
node sortDesc(node);

node reverse(node);

node concat(node, node);


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

//-------------- Delete functions

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
    return head;
}

// delete at any position
node deletePos(node head) {
    node ptr, preptr;
    int temp, pos, i;

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
    return head;
}



// delete after a node
node deleteAfter(node head) {
    node current, next;
    int item;

    printf("Enter the element after which you want to delete >> ");
    scanf("%d", &item);

    if (head == NULL) {
        printf("The list is empty!!!\n");
    } else {
        if (head -> data == item) {
            printf("The deleted element is: %d", head -> next -> data);
            head -> next = head -> next -> next;
            return head;
        } else {
            current = head;
            while (current -> data != item) {
                current = current -> next;
                next = current -> next;

                if (current -> next == NULL) {
                    printf("Not in the list OR the last item\n");
                    return head;
                } 

            }
            printf("The deleted element is: %d\n", next -> data);
            current -> next = next -> next;
        }
    }
    return head;
}


// delete before a node
node deleteBefore(node head) {
    node current, prev;
    int item;

    printf("Enter the element before which you want to delete >> ");
    scanf("%d", &item);

    if (head == NULL) {
        printf("The list is empty!!!\n");
    } else {
        if (head -> data == item) {
            printf("There's no data before this item!!!\n");
            return head;
        } else if (head -> next -> data == item) {
            printf("The deleted element is: %d\n", head -> data);
            head = head -> next;
            return head;
        } else {
            current = head;
            while (current -> next -> data != item) {
                prev = current;
                current = current -> next;

                if (current -> next == NULL) {
                    printf("Not in the list\n");
                    return head;
                } 

            }
            printf("The deleted element is: %d\n", current -> data);
            prev -> next = current -> next;

        }
    }
    return head;
}



// delete a specific node
node deleteNode(node head) {
    node current, prev;
    int item;

    printf("Enter the element you want to delete >> ");
    scanf("%d", &item);

    if (head == NULL) {
        printf("The list is empty!!!\n");
    } else {
        if (head -> data == item) {
            head = head -> next;
        } else {
            current = head;
            while (current -> data != item) {
                prev = current;
                current = current -> next;

                if (current == NULL) {
                    printf("Not in the list\n");
                    return head;
                } 
            }
            prev -> next = current -> next;

        }
    }
    return head;
}


//-------------- ---------------------------


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


// reversing
node reverse(node head) {
    node preptr = NULL, ptr, temp = NULL;

    if (head == NULL) {
        printf("\nThe list is empty.\n");
    } else{
        ptr = head;
        while (ptr != NULL) {
            temp = ptr -> next;
            ptr -> next = preptr;
            preptr = ptr;
            ptr = temp;
        }
        return preptr;
    }
}

// merging
node concat(node a, node b) {
    node p;
    if (a == NULL) {
        return b;
    } 
    if (b == NULL){
        return a;
    } 
    p = a;
    while (a -> next != NULL) {
        a = a -> next;
    }
    a -> next = b;
    return p;
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
            printf("\nThe current list is\n");
            display(head);
            head = deleteBeg(head);
            printf("\nAfter deleting the list is\n");
            display(head);
            break;
        case 2:
            printf("\nDeleting from the end...\n");
            printf("\nThe current list is\n");
            display(head);
            head = deleteEnd(head);
            printf("\nAfter deleting the list is\n");
            display(head);
            break;
        case 3:
            printf("\nDeleting from specific position...\n");
            printf("\nThe current list is\n");
            display(head);
            head = deletePos(head);
            printf("\nAfter deleting the list is\n");
            display(head);
            break;
        case 4:
            printf("\nDeleting after a node...\n");
            printf("\nThe current list is\n");
            display(head);
            head = deleteAfter(head);
            printf("\nAfter deleting the list is\n");
            display(head);
            break;
        case 5:
            printf("\nDeleting before a node...\n");
            printf("\nThe current list is\n");
            display(head);
            head = deleteBefore(head);
            printf("\nAfter deleting the list is\n");
            display(head);
            break;
        case 6:
            printf("\nDeleting a specific node...\n");
            printf("\nThe current list is\n");
            display(head);
            head = deleteNode(head); 
            printf("\nAfter deleting the list is\n");
            display(head);
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
    node list2;
    list2 = NULL;
    
    while (1) {
        printf("\n=============== Main Menu ===============\n");
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

                printf("Current list is: \n");
                display(head);

                head = reverse(head);

                printf("\nAfter Reversing the list is: \n");
                display(head);
                break;
            case 5:
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
    printf("\nCreating a list...\n\n");
    list = createList(list);

    printf("\nThe Created List is\n");
    display(list);


    // main menu calling
    list = menuMain(list);
}