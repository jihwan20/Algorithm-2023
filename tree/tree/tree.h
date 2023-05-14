#pragma once
typedef struct _Node {
    int value;
    struct _Node* left;
    struct _Node* right;
} Node;

Node* makeTree();
Node* createNode(int value);
void printNode(Node* root);
void preorder(Node* n);
void inorder(Node* n);
void postorder(Node* n);
Node* findNode(int value, Node* root);
Node* insertLeftNode(Node* where, Node* new_node);
Node* insertRightNode(Node* where, Node* new_node);