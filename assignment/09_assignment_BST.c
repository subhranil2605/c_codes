/* ------------ Assignment 9 ------------ */ 
/* ------------ Subhranil Sarkar ------------ */ 
/* ------------ M.Sc. Data Science 1st Semester ------------ */ 
/* ------------ University of Kalyani ------------ */ 
/* ------------ 22nd March, 2022 ------------ */ 



#include<stdio.h>
#include<stdlib.h>


// node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node* node;


/* ------------ Function prototypes ------------ */ 

node createNode(int );
node insert(node , int);
node minValueElement(node );
node delete(node , int);
node search(node , int );
void inorder(node );
void preorder(node );
void postorder(node );



/* ------------ Function declarations ------------ */ 

// creating a single node
node createNode(int val) {
    node temp;
    temp = (node) malloc(sizeof(node));
    temp -> data = val;
    temp -> left = temp -> right = NULL;
    return temp;
}


// inserting a node in the tree
node insert(node tree, int val) {

    if (tree == NULL) {
        tree = createNode(val);
    } else {
        // if the value is lesser than the root node, then it will be inserted in left
        if (val < tree -> data) {
            tree -> left = insert(tree -> left, val);
        } 
        // if the value is greater than the root node, then it will be inserted in right
        else {
            tree -> right = insert(tree -> right, val);
        }
    }
    return tree;
}


//  minimum
node minValueElement(node tree) {
    node p;
    p = tree;

    while (p && p -> left != NULL) {
        p = p -> left;
    }
    return p;
}


// delete
node delete(node tree, int val) {
    node temp;

    if (tree == NULL) {
        return tree;
    } 

    if (val < tree -> data) {
        tree -> left = delete(tree -> left, val);
    } else if (val > tree -> data) {
        tree -> right = delete(tree -> right, val);
    } else {
        if (tree -> left == NULL) {
            temp = tree -> right;
            free(tree);
            return temp;
        } else if (tree -> right == NULL) {
            temp = tree -> left;
            free(tree);
            return temp;
        }

        temp = minValueElement(tree -> right);

        tree -> data = temp -> data;
        tree -> right = delete(tree -> right, temp -> data);
    }
    return tree;
}

// search
node search(node tree, int val) {
    if (tree == NULL || tree -> data == val) {
        return tree;
    } else {
        if (val < tree -> data) {
            tree = search(tree -> left, val);
        } else {
            tree = search(tree -> right, val);
        }
    }
    
}


// in-order traversal
void inorder(node tree) {
    if (tree != NULL) {
        inorder(tree -> left);
        printf("%d -> ", tree -> data);
        inorder(tree -> right);
    }
}


// preorder traversal
void preorder(node tree) {
    if (tree != NULL) {
        printf("%d -> ", tree -> data);
        preorder(tree -> left);
        preorder(tree -> right);
    }
}

// postorder traversal
void postorder(node tree) {
    if (tree != NULL) {
        postorder(tree -> left);
        postorder(tree -> right);
        printf("%d -> ", tree -> data);
    }
}




/* ------------ Menus ------------ */ 

// traversal menu
node menuTraversal(node tree) {
    int choice;

    printf("\n============= Traverse Menu =================\n");    
    printf("Press 1: Inorder Traversal\n");
    printf("Press 2: Preorder Traversal\n");
    printf("Press 3: Postorder Traversal\n");
    printf("Press 4: EXIT");
    printf("\n================================\n");
    printf("Enter your choice >> ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nInorder Traversing...\n");
            inorder(tree);
            break;
        case 2:
            printf("\nPreorder Traversing...\n");
            preorder(tree);
            break;
        case 3:
            printf("\nPostorder Traversing...\n");
            postorder(tree);
            break;
        case 4:
            exit(1);
        
        default:
            printf("Incorrect choie!!!\n");
            tree = menuTraversal(tree);
            break;
    }

    return tree;
}


// main menu
node menuMain(node tree) {
    int choice, val;
    node temp;

    while (1) {
        printf("\n============= Main Menu =================\n");
        printf("Press 1: INSERT\n");
        printf("Press 2: DELETE\n");
        printf("Press 3: SEARCH\n");
        printf("Press 4: TRAVERSE\n");
        printf("Press 5: EXIT");
        printf("\n================================\n");
        printf("Enter your choice >> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nInserting...\n");
                printf("\nEnter the value to be inserted >> ");
                scanf("%d", &val);
                tree = insert(tree, val);
                printf("Insertion Done!\n");
                printf("The tree is: ");
                inorder(tree);
                break;
            case 2:
                printf("\nDeleting...\n");
                printf("Current tree is: ");
                inorder(tree);
                printf("\nEnter the value to be deleted >> ");
                scanf("%d", &val);
                tree = delete(tree, val);
                printf("After deleting the tree is\n");
                inorder(tree);
                break;
            case 3:
                printf("\nSearching...\n");

                printf("\nEnter the value to be searched >> ");
                scanf("%d", &val);

                temp = search(tree, val);

                if (temp == NULL) {
                    printf("The element is not in the list\n");
                } else {
                    printf("The element %d is in the list.", temp -> data);
                }
                break;
            case 4:
                tree = menuTraversal(tree);
                break;
            case 5:
                exit(1);
            
            default:
                printf("Incorrect choie!!!\n");
                break;
        }
    }

    return tree;
}



/* ------------ Main Function ------------ */ 


void main() {
    node tree;
    tree = NULL;

    tree = menuMain(tree);
}