#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Node* makeTree()
{
	Node* root = createNode(100);
	root->left = createNode(200);
	root->right = createNode(300);
	root->right->left = createNode(400);
	root->right->right = createNode(500);
	return root;
}

Node* createNode(int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void preorder(Node* n)
{
	if (n != NULL) {
		printf("[%d] ", n->value);
		preorder(n->left);
		preorder(n->right);
	}
}

void inorder(Node* n)
{
	if (n != NULL) {
		inorder(n->left);
		printf("[%d] ", n->value);
		inorder(n->right);
	}
}

void postorder(Node* n)
{
	if (n != NULL) {
		postorder(n->left);
		postorder(n->right);
		printf("[%d] ", n->value);
	}
}
void printNode(Node* root)
{
	printf("Pre-Order : ");
	preorder(root);	// preorder 순회 출력
	printf("\n");
	printf("In-Order : ");
	inorder(root);	// inorder 순회 출력
	printf("\n");
	printf("Post-Order : ");
	postorder(root); // postorder 순회 출력
	printf("\n");
}

Node* findNode(int value, Node* root)
{
	if (root == NULL || root->value == value) {
		return root;
	}
	Node* found = findNode(value, root->left);
	if (found != NULL) {
		return found;
	}
	return findNode(value, root->right);
}

Node* insertLeftNode(Node* where, Node* new_node)
{
	if (where == NULL) {
		return NULL;
	}
	Node* left_node = where->left;
	where->left = new_node;
	new_node->left = left_node;
	return where;
}

Node* insertRightNode(Node* where, Node* new_node)
{
	if (where == NULL) {
		return NULL;
	}
	Node* right_node = where->right;
	where->right = new_node;
	new_node->right = right_node;
	return where;
}
