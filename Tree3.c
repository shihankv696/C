/* Basic Binary tree with basic operations*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *right;
    struct Node *left;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed. Reallocating The memory\n");
        Node* newNode = (Node *)realloc(newNode, sizeof(Node));
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* findMax(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

Node* delete(Node* root, int data) {
    if (root == NULL) {
        printf("The %d is Not Founded in the Tree\n", data);
        return root;
    }

    if (data < root->data) {
        root->left = delete (root->left, data);
    }
 
    else if (data > root->data) {
        root->right = delete (root->right, data);
    }

    else {

        //  Node with 1 || 0 child nodes 
        if (root->left == NULL) {
            Node* temp = root->right;
            printf("The %d is deleted from the tree\n", root->data);
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            printf("The %d is deleted from the tree\n", root->data);
            free(root);
            return temp;
        }

        // Node with 2 child nodes
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
    
}

int height(Node* root) {
    if (root == NULL) {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight >rightHeight ? leftHeight : rightHeight) + 1;
}

int depth(Node* root, Node* node, int level) {
    if (root == NULL) {
        return -1;
    }

    if (root == node) {
        return level;
    }
 
    int leftDepth = depth(root->left, node, level + 1);
    
    if (leftDepth != -1) {
        return leftDepth;
    }
    return depth(root->right, node, level + 1);
}

int level(Node* root, Node* node) {
    if (root == node) {
        return 0;
    }
    return depth(root, node, 0);
}

Node* findParent(Node* root, Node* node) {
    if (root == NULL || root->left == node || root->right == node) {
        return node;
    }
    Node *foundParent = findParent(root->left, node);
    if (foundParent == NULL) {
        foundParent = findParent(root->right, node);
    }

    return foundParent;
}

int diameter(Node* root, int* height) {
    int lh = 0,rh = 0;
    int ldiameter = 0, rdiameter = 0;

    if (root == NULL) {
        *height = 0;
        return 0;
    }

    ldiameter = diameter(root->left, &lh);
    rdiameter = diameter(root->right, &rh);

    *height = (lh > rh ? lh : rh) + 1;

    return (lh + rh + 1) > (ldiameter > rdiameter ? ldiameter : rdiameter) ? (lh + rh + 1) : (ldiameter > rdiameter ? ldiameter : rdiameter);
}

void findLeaves(Node* root) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%d -> ", root->data);
    }

    findLeaves(root->left);
    findLeaves(root->right);
}

Node* findSibling(Node* root, Node* node) {
    if (root == NULL || root->left == NULL || root->right == NULL) {
        return NULL;
    }

    if (root->left != NULL && root->right != NULL) {
        if (root->left == node) {
            return root->right;
        }
        if (root->right == node) {
            return root->left;
        }
    }

    Node *foundSibling = findSibling(root->left, node);
    foundSibling = findSibling(root->right, node);

    if (foundSibling == NULL) {
        return NULL;
    }
    return foundSibling;
}

void findChildren(Node* node) {
    if (node == NULL) {
        printf("Underflow\n");
        return;
    }

    if (node->left != NULL) {
        printf(" %d and ", node->left->data);
    }

    if (node->right != NULL) {
        printf("%d\n", node->right->data);
    }
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

void printCurrentLevel(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) 
    {
        printf("%d -> ", root->data);
    }
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
} 

void levelOrder(Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; ++i) {
        printCurrentLevel(root, i);
    }
}

int main() {

    Node *root = NULL;
    int choice, data, treeHeight = 0;
    Node *node;

    do {
        printf("\n\tMenu\n1. Insert\n2. Delete\n3. Search\n4. Height Of the tree\n5. Depth of Node\n6. Level of Node\n7. Find the Parent of Node\n8. Diameter of Tree\n9. Find all leaf Nodes\n10. Find Siblings of Node\n11. Find Children Of of Node\n12. In - Order Traversal\n13. Pre - Order Traversal\n14. Post - Order Traversal\n15. Level - Order Traversal\n16. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("The %d in inserted to the Tree\n", data);
                break;
            
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;

            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                node = search(root, data);
                if (node != NULL) {
                    printf("Value %d found in the tree.\n", data);
                }
                else {
                    printf("Value %d Not found in the tree.\n", data);
                }
                break;

            case 4:
                printf("Height Of the Tree: %d", height(root));
                break;

            case 5:
                printf("Enter node value find depth: ");
                scanf("%d", &data);
                node = search(root, data);
                if (node != NULL) {
                    printf("Depth of the node %d: %d\n", data, depth(root, node, 0));
                }
                else {
                    printf("Node %d not found in the tree.\n", data);
                }
                break;

            case 6:
                printf("Enter The node to find level; ");
                scanf("%d", &data);
                node = search(root, data);
                if (node != NULL) {
                    printf("Level of the node %d: %d\n", data, level(root, node));
                }
                else {
                    printf("Node %d not found in the tree.\n", data);
                }
                break;

            case 7:
                printf("Enter node value to find parent: ");
                scanf("%d", &data);
                node = search(root, data);
                if (node != NULL) {
                    Node* parent = findParent(root, node);
                    if (parent != NULL) {
                        printf("Parent of node %d: %d\n", data, parent->data);
                    }
                    else {
                        printf("Node %d is the root node and has no parent.\n", data);
                    }
                }
                break;

            case 8:
                printf("Diameter of tree: %d\n", diameter(root, &treeHeight));
                break;

            case 9:
                printf("Leaf node: ");
                findLeaves(root);
                printf("NULL\n");
                break;

            case 10:
                printf("Enter Node value to find sibling: ");
                scanf("%d", &data);
                node = search(root , data);
                if (node != NULL) {
                    Node *sibling = findSibling(root, node);
                    if (sibling != NULL) {
                        printf("Sibling of node %d: %d\n", data, sibling->data);
                    }
                    else {
                        printf("Node %d has no sibling.\n", data);
                    }
                }
                else {
                    printf("Node %d not found in the tree.\n", data);
                }
                break;

            case 11:
                printf("Enter node value to find children: ");
                scanf("%d", &data);
                node = search(root, data);
                if (node != NULL) {
                    findChildren(node);
                }
                else {
                    printf("Node %d not found in the tree.\n", data);
                }
                break;

            case 12:
                printf("In - order Traversal: ");
                inOrder(root);
                printf("NULL\n");
                break;

            case 13:
                printf("Pre - Order Traversal: ");
                preOrder(root);
                printf("NULL\n");
                break;

            case 14:
                printf("Post - Order Traversal: ");
                postOrder(root);
                printf("NULL\n");
                break;

            case 15:
                printf("Level - Order Traversal: ");
                levelOrder(root);
                printf("NULL\n");
                break;

            case 16:
                printf("Exiting The Program. Good Bye\n");
                exit(0);

            default:
                printf("Invalid option. please choose a correct one!\n");
                break;
        }
    } while (1);

    return 0;
}