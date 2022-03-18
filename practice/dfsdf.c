/*
Subhranil Sarkar
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
// typedef struct node* node;

// Function declarations
struct node* createNode();
struct node* insertEnd(struct node* head, int i);
struct node* createList();
struct node* reverse(struct node* head);


// Function definitions


// create a node
struct node* createNode() {
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp -> next = NULL;
    return temp;
}


// inserting at the end
struct node* insertEnd(struct node* head, int i) {
    struct node* newNode, *p;
    int value;

    newNode = createNode();

    printf("Enter the %d-th element of the list:: ", i);
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
struct node* createList() {
    char ch = 'y';
    struct node* head;
    int i = 0;

    head = NULL;

    while (ch != 'q') {
        head = insertEnd(head, i);
        printf("\nPress 'q' to exit the loop OR press any key to continue:: ");
        scanf("\n%c", &ch);
        i++;
    }
    return head;
}


// reversing
struct node* reverse(struct node* head) {
    struct node* preptr = NULL, *ptr, *temp = NULL;

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


// main function
int main() {
    struct node* list;
    list = createList();
    printf("\nAfter reversing\n");
    list = reverse(list);
    return 0;
}
