#include<stdio.h>
#include<stdlib.h>


struct node {
	int coef, exp;
	struct node* next;
};

typedef struct node* node;

node createNode();
node insert(node, int, int);

// creating a single node
node createNode() {
	node temp;
	temp = (node) malloc(sizeof(node));
	if (temp == NULL) {
		return NULL;
	} else {
		temp -> next = NULL;
		return temp;
	}
}


// inserting
node insert(node poly, int coef, int exp) {
	node newNode, temp;

	newNode = createNode();

	newNode -> coef = coef;
	newNode -> exp = exp;

	if (newNode == NULL) {
		printf("\nMemory Allocation Failed\n");
	} else {
		if (poly == NULL || poly -> exp < exp) {
			newNode -> next = poly;
			poly = newNode;
		} else {
			temp = poly;
			while (temp -> next != NULL && temp -> next -> exp > exp) {
				if (temp -> next -> exp == exp) {
					temp -> next -> coef = temp -> next -> coef + coef;
					free(temp);
					return poly;
				}
				temp = temp -> next;
			}
			newNode -> next = temp -> next;
			temp -> next = newNode;
		}
	}
	return poly;
}