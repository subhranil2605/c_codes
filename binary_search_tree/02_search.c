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


node searchElement(node tree, int val) {
    if (tree == NULL || tree -> data == val) {
        return tree;
    } else {
        if (val < tree -> data) {
            tree = searchElement(tree -> left, val);
        } else {
            tree = searchElement(tree -> right, val);
        }
    }
    
}



// main function
void main() {
    node tree; 
    
    tree = NULL;

    tree = insert(tree, 5);
    tree = insert(tree, 6);
    tree = insert(tree, 4);

    tree = searchElement(tree, 5);

    // searching result
    (tree != NULL)
    ? printf("The element %d\n is in the tree\n", tree -> data)
    : printf("The element is not present in the tree!\n");


}