/* ------------ Assignment 6 ------------ */ 
/* ------------ Subhranil Sarkar ------------ */ 
/* ------------ M.Sc. Data Science 1st Semester ------------ */ 
/* ------------ University of Kalyani ------------ */ 
/* ------------ 18th March, 2022 ------------ */ 


#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
};

typedef struct node* node;


/* ------------ Function prototypes ------------ */ 

// menus
node menuListCreate(node);
node menuListOperations(node);
node menuInsert(node);
node menuDelete(node);

// others
void display(node);
node createNode();
node creatingSingleElementList(node, node);
node insertBeg(node);
node createListBeg();
node createListEnd();
node insertEnd(node);
node insertAfter(node);
node deleteBeg(node);
node deleteEnd(node);
node deleteItem(node);
void search(node);
node reverse(node);


/* ------------ Function declarations ------------ */ 

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

// adding element to a empty list
node creatingSingleElementList(node last, node newNode) {
    if (last != NULL) {
        return last;
    } else {
        last = newNode;
        newNode -> next = last;
        return last;
    }
}

// displaying the circular linked list
void display(node last) {
    node p;

    if (last == NULL) {
        printf("The list is empty\n");
    } else {
        p = last -> next;  // it points to the head of the list
        
        while (1) {
            if (p != last) {
                printf("-->%d", p -> data);
            } else {
                printf("-->%d---\n", p -> data);
                break;
            }
            p = p -> next;
        }
    }
}



// insert beginning
node insertBeg(node last) {
    node newNode;
    int data;

    newNode = createNode();
    printf("Enter the data to be inserted >> ");
    scanf("%d", &data);

    newNode -> data = data;

    if (last == NULL) {
        last = creatingSingleElementList(last, newNode);
    } else {
        newNode -> next = last -> next;
        last -> next = newNode;
    }
    return last;    
}


// creating a list
node createListBeg() {
    node last;
    char ch='y';
    last = NULL;

    while (ch != 'q') {
        last = insertBeg(last);
        printf("\nPress 'q' to stop OR Press anyting to continue >> ");
        scanf("\n%c", &ch);
    }

    return last;
}


// insert at the end
node insertEnd(node last) {
    node newNode;
    int data;

    newNode = createNode();
    printf("Enter the data to be inserted >> ");
    scanf("%d", &data);

    newNode -> data = data;

    if (last == NULL) {
        last = creatingSingleElementList(last, newNode);
    } else {
        newNode -> next = last -> next;     // links between new last and the first node
        last -> next = newNode;             // new node is the current last node
        last = newNode;                     // set the last pointer to the new node
    }
    return last;    
}


// creating a list
node createListEnd() {
    node last;
    char ch='y';
    last = NULL;

    while (ch != 'q') {
        last = insertEnd(last);
        printf("\nPress 'q' to stop OR Press anyting to continue >> ");
        scanf("\n%c", &ch);
    }

    return last;
}


// insert after a specific item
node insertAfter(node last) {
    node newNode, p;
    int data, item;
    
    if (last == NULL) {
        printf("The list is empty");
        return last;
    } else {
        printf("Enter the item after which new data to be inserted >> ");
        scanf("%d", &item);
        printf("Enter the data to be inserted >> ");
        scanf("%d", &data);
        newNode = createNode();
        newNode -> data = data;
        p = last -> next;

        do {
            if (p -> data == item) {
                newNode -> next = p -> next;
                p -> next = newNode;

                if (p == last) {
                    last = newNode;
                }
                return last;
            }
            p = p -> next;
        } while (p != last -> next);
        return last;
    }
}


// deleting from the start
node deleteBeg(node last) {
    node p;
    if (last == NULL) {
        printf("The list is empty!!!");
    } else {
        p = last -> next;
        if (last -> next != last -> next -> next) {
            last -> next = last -> next -> next;
        } else {
            free(last);
            last = NULL;
        }
    }
    return last;
}

// deleting from the end
node deleteEnd(node last) {
    node p; 

    if (last == NULL) {
        printf("The list is empty\n");
    } else {
        if (last == last -> next) {
            free(last);
            last = NULL;
        } else {
            p = last -> next;  // it points to the head of the list
            while (p -> next != last) {
                p = p -> next;
            }
            p -> next = last -> next;
            last = p;
        }
    }
    return last;
}


// deleting an item
node deleteItem(node last) {
    node p, deletedItem; 
    int data;

    // if list is empty
    if (last == NULL) {
        printf("The list is empty");
    } else {
        printf("Enter the data to be deleted >> ");
        scanf("%d", &data);
        // list consists of a single node
        if (last -> data == data && last -> next == last) {
            free(last);
            last = NULL;
        } else {
            p = last;
            // if the item at the end
            if (p -> data == data) {
                while (p -> next != last) {
                    p = p -> next;
                }
                p -> next = last -> next;
                last = p;
            } else {
                while (p -> next != last && p -> next -> data != data) {
                    p = p -> next;
                }
                if (p -> next -> data == data) {
                    deletedItem = p -> next;
                    p -> next = deletedItem -> next;
                    free(deletedItem);
                } 
            }
        }
    }
    return last;
}


// searching element
void search(node last) {
    node p;
    int item, count = 0, flag=0;

    if (last == NULL) {
        printf("The list is empty\n");
    } else {
        p = last -> next;

        printf("Enter the item you want to search >> ");
        scanf("%d", &item);

        while (1) {
            if (p != last) {
                if (p -> data == item) {
                    printf("The element is found at position: %d\n", count + 1);
                    flag = 1;
                    break;
                } else {
                    flag = 0;
                }
            } else {
                // if the item is at the end
                if (p -> data == item) {
                    printf("The element is found at position: %d\n", count + 1);
                    flag = 1;
                }
                break;
            }
            count++;
            p = p -> next;
        }

        if (flag != 1) {
            printf("The item is not present in the list!!!\n");
            return;
        }
    }
}


// reverse
node reverse(node last) {
    node current, next, prev;

    if (last == NULL) {
        printf("The list is empty!\n");
    } else {
        // single element in the list
        if (last == last -> next) {
            printf("It is the single list. So, no reverse is possible!!\n");
        } else {
            current = last -> next;     // first node
            next = current -> next;     // second node

            while (current != last) {
                prev = current;
                current = next;
                next = current -> next;
                current -> next = prev;
            } 

            next -> next = last;
            last = next;
        }
    }
    return last;
}



// menu for creating a list
node menuListCreate(node list) {
    int choice;

    printf("\n========= CREATING A LIST =========\n");
    printf("Press 1: Insert from the Beginning\n");
    printf("Press 2: Insert from the End\n");
    printf("Press 3: Exit");
    printf("\n=========================\n");
    printf("Enter your choice >> ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nCreating List with Inserting elements from the beginning...\n");
            list = createListBeg(list);
            break;
        case 2:
            printf("\nCreating List with Inserting elements from the end...\n");
            list = createListEnd(list);
            break;
        case 3:
            exit(1);
        default:
            printf("\nIncorrect choice!!!\n");
            list = menuListCreate(list);
            break;
    }

    return list;
}


// inserting
node menuInsert(node list) {
    int choice;

    printf("\n========= INSERTING INTO A LIST =========\n");
    printf("Press 1: Insert at the Start\n");
    printf("Press 2: Insert at the End\n");
    printf("Press 3: Insert after an Element\n");
    printf("Press 4: Exit");
    printf("\n=========================\n");
    printf("Enter your choice >> ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nInserting at the beginning...\n");
            list = insertBeg(list);
            break;
        case 2:
            printf("\nInserting at the end...\n");
            list = insertEnd(list);
            break;
        case 3:
            printf("\nInserting after an item...\n");
            list = insertAfter(list);
            break;
        case 4:
            exit(1);
        default:
            printf("\nIncorrect choice!!!\n");
            list = menuInsert(list);
            break;
    }

    return list;
}


// deleting
node menuDelete(node list) {
    int choice;

    printf("\n========= INSERTING INTO A LIST =========\n");
    printf("Press 1: Delete from the Start\n");
    printf("Press 2: Delete from the End\n");
    printf("Press 3: Delete an Element\n");
    printf("Press 4: Exit");
    printf("\n=========================\n");
    printf("Enter your choice >> ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nDeleting from the beginning...\n");
            list = deleteBeg(list);
            break;
        case 2:
            printf("\nDeleting from the end...\n");
            list = deleteEnd(list);
            break;
        case 3:
            printf("\nDeleting an item..\n");
            list = deleteItem(list);
            break;
        case 4:
            exit(1);
        default:
            printf("\nIncorrect choice!!!\n");
            list = menuDelete(list);
            break;
    }

    return list;
}


// menu for list operations
node menuListOperations(node list) {
    int choice;

    while(1) {
        printf("\n=========================\n");
        printf("Press 1: Display\n");
        printf("Press 2: Insert\n");
        printf("Press 3: Delete\n");
        printf("Press 4: Search\n");
        printf("Press 5: Reverse\n");
        printf("Press 6: Exit");
        printf("\n=========================\n");
        printf("Enter your choice >> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nDisplaying...\n");
                display(list);
                break;
            case 2:
                printf("\nInserting...\n");
                list = menuInsert(list);
                break;
            case 3:
                printf("\nDeleting...\n");
                list = menuDelete(list);
                break;
            case 4:
                printf("\nSearching...\n");
                search(list);
                break;
            case 5:
                printf("\nReversing...\n");
                list = reverse(list);
                break;
            case 6:
                exit(1);
            default:
                printf("\nIncorrect choice!!!\n");
                list = menuListOperations(list);
                break;
        }
    } 

    return list;
}



/* ------------ Main function ------------ */ 

void main() {
    node list;
    list = NULL;

    // creating a list
    list = menuListCreate(list);

    // list operations
    list = menuListOperations(list);
}