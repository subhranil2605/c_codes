#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node* node;


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


// in-order traversal
void inorder(node tree) {
    if (tree != NULL) {
        inorder(tree -> left);
        printf("%d -> ", tree -> data);
        inorder(tree -> right);
    }
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




// main function
void main() {
    node tree; 
    
    tree = NULL;

    tree = insert(tree, 5);
    // tree = insert(tree, 6);
    // tree = insert(tree, 4);

    printf("Before deleting the tree is: ");
    inorder(tree);

    tree = delete(tree, 5);
    printf("\nAfter deleting the tree is: ");
    inorder(tree);
}   