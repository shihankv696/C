/*Binary Tree with Basic Operation
    Insert - Delete - Search - Traversal*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Allocation is Failed realllocing the memory\n");
        newNode = (Node *)realloc(newNode,sizeof(newNode));
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* findMin(Node* root) {
    if (root == NULL) {
        return -1;
    }

    Node *current = root;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* findMax(Node* root) {
    if (root == NULL) {
        return -1;
    }

    Node *current = root;
    while (current != NULL) {
        current = current->right;
    }
    return current;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }

    if (root->data < data)
    {
        insertNode(root->left, data);
    }

    else if (data < root->data)
    {
        insertNode(root->right, data);
    }

    return root;
}

Node *searchNode(Node *root, int key) {
    if (root == NULL || root == key) {
        return root;
    }

    if (key < root->data){
        return searchNode(root->left, key);
    }
    else if(key > root->data) {
        return searchNode(root->right, key);
    }
}


Node *deleteNode(Node *root, int key) {
    if (root == NULL) {
        return root;
    }

    /*if the key to be deleted Node less than key 
      It will lies on the left side off the root Node*/
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }

    /*if the key to be deleted Node Greater than key
      It will lies on the  right side off the root Node*/
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }

    /*if The key is the same as root key, Than this is node
    to be deleted*/
    else {

        /*If the root node have one child node*/
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        /*If the root node have one child node*/
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        /*if the tree has two children Node: Get inorder successor in right subtree*/
        Node *temp = findMin(root->right);

        /*Copy the data of inorder successor to the root Node*/
        root->data = temp->data;

        /*Delete in order successor*/
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


void inOrder(Node* root) {
    if (root == NULL ) {
        return;
    }
    inOrder(root->left);
    printf("%d -> ", root->data);
    inOrder(root->right);
}

int main() {
    Node *root = NULL;
    int choice, key;

    while (1) {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertNode(root, key);
                break;
            case 2:
                printf("Enter Key to delete: ");
                scanf("%d", &key);
                deleteNode(root, key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                Node *res = searchNode(root, key);
                if (res == NULL) {
                    printf("Key %d Not Found in the Tree.\n", key);
                }
                else {
                    printf("Key %d Found in the tree.\n", key);
                }
                break;
            case 4:
                printf("In Order Traversal: ");
                inOrder(root);
                printf("NULL\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}