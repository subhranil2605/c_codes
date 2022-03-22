/* ------------ Assignment 10 ------------ */ 
/* ------------ Subhranil Sarkar ------------ */ 
/* ------------ M.Sc. Data Science 1st Semester ------------ */ 
/* ------------ University of Kalyani ------------ */ 
/* ------------ 23rd March, 2022 ------------ */ 


#include<stdio.h>
#include<stdlib.h>


// node structure
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


// maximum of two numbers
int max(int x, int y) {
    return (x > y) ? x : y;
}

// height of a tree
int height(node tree) {
    return (tree == NULL) ? 0 : 1 + max(height(tree -> left), height(tree -> right));
}


// is balanced checking
int isBalanced(node tree) {
    int leftHeight;
    int rightHeight;
    int lVal, rVal;

    if (tree == NULL) {
        return 1;
    } else {
        leftHeight = height(tree -> left);
        rightHeight = height(tree -> right);

        lVal = isBalanced(tree -> left);
        rVal = isBalanced(tree -> right);

        if (abs(leftHeight - rightHeight) <= 1 && lVal == 1 && rVal == 1) {
            return 1;
        }
    }
    return 0;
}


void main() {
    node tree1, tree2;


    // ------------------------------ first tree ------------------------------
    tree1 = NULL;

    /* Balanced tree

                        5
                      /   \
                    6      56
                   /
                  41
    */ 

    // root
    tree1 = createNode(5);
    
    // level 1
    tree1 -> left = createNode(6);
    tree1 -> right = createNode(56);

    // level 2
    tree1 -> left -> left = createNode(41);
    
    (isBalanced(tree1) == 1) ? printf("Balanced Tree\n") : printf("Not Balanced Tree\n");


    // ------------------------------ second tree ------------------------------
    tree2 = NULL;

    /* Not balanced tree

                        5
                      /   \
                    6      56
                   / \
                 41   50
                /
               100
    */ 

    // root
    tree2 = createNode(5);
    
    // level 1
    tree2 -> left = createNode(6);
    tree2 -> right = createNode(56);

    // level 2
    tree2 -> left -> left = createNode(41);
    tree2 -> left -> right = createNode(50);

    // level 3
    tree2 -> left -> left -> left = createNode(100);
    
    (isBalanced(tree2) == 1) ? printf("Balanced Tree\n") : printf("Not Balanced Tree\n");

}