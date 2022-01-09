#include<stdio.h>
#include<stdlib.h>

// Function Prototypes
void showingInsertionMenu();
void showingDeletionMenu();


// Main Function
void main() {
    int choice;

    while(1) {
        printf("\nDisplay the list: 1");
        printf("\nInsertion: 2");
        printf("\nReverse: 3");
        printf("\nDeletion: 4");
        printf("\nExit: 5");
        printf("\nEnter your choice:: ");
        scanf("%d", &choice);

        // case statement
        switch(choice) {
            case 1:
                printf("\nDisplaying\n");
                break;
            case 2:
                showingInsertionMenu();
                break;
            case 3:
                printf("\nReversing\n");
                break;
            case 4:
                showingDeletionMenu();
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("\nIncorrect choice\n");
                break;
        }
    }
}


/*----------------------------------------------------------------------------------------------------------*/
// Function Definitions

// Showing Insertion Menu in the main menu
void showingInsertionMenu() {
    int choice;         // creating a local variable for storing the user choice

    printf("\n-----------------------Inserting-----------------------\n");
    printf("\nInsert at the beginning: 1");
    printf("\nInsert at the end: 2");
    printf("\nInsert at any position: 3");
    printf("\nEnter your choice:: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("\nInserting at the start\n");
            break;
        case 2:
            printf("\nInserting at the end\n");
            break;
        case 3:
            printf("\nInserting at any position\n");
            break;
        default:
            printf("\nIncorrect choice!\n");
            break;
    }
    printf("--------------------------------------------------------");
}

// Showing Deletion Menu in the main menu
void showingDeletionMenu() {
    int choice;
    printf("\n-----------------------Deleting-----------------------\n");
    printf("\nDelete at the beginning: 1");
    printf("\nDelete at the end: 2");
    printf("\nDelete at any position: 3");
    printf("\nEnter your choice:: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("\nDeleting at the start\n");
            break;
        case 2:
            printf("\nDeleting at the end\n");
            break;
        case 3:
            printf("\nDeleting at any position\n");
            break;
        default:
            printf("\nIncorrect choice!\n");
            break;
    }
    printf("--------------------------------------------------------");
}
