/*Binary Tree and Three Type traversal like In-Order, Pre-Order, Post-Order*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation Failed\n");
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data < root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d -> ", root->data);
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d -> ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d -> ", root->data);
}

int main()
{
    Node *root = NULL;

    // Insert nodes into the binary tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print the tree in different orders
    printf("In-order traversal: ");
    inOrder(root);
    printf("NULL\n");

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("NULL\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("NULL\n");

    return 0;
}
