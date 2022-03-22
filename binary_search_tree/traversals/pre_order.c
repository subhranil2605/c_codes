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


// preorder traversal
void preorder(node tree) {
    if (tree != NULL) {
        printf("%d -> ", tree -> data);
        preorder(tree -> left);
        preorder(tree -> right);
    }
}




// main function
void main() {
    node tree; 
    
    tree = NULL;

    tree = insert(tree, 5);
    tree = insert(tree, 6);
    tree = insert(tree, 4);

    preorder(tree);
}