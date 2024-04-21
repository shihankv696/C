#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

struct TreeNode {
    int Root;
    struct TreeNode *Left;
    struct TreeNode *Right;
};

struct Queue {
    int front;
    int rear;
    int size;
    struct TreeNode **array;
};

struct Queue *createQueue(int capacity) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->array = (struct TreeNode **)malloc(capacity * sizeof(struct TreeNode *));
    return queue;
}

int isQueueEmpty(struct Queue *queue) {
    return queue->size == 0;
}

void Enqueue(struct Queue *queue, struct TreeNode *node) {
    queue->array[++queue->rear] = node;
    queue->size++;
}

struct TreeNode *Dequeue(struct Queue *queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }

    struct TreeNode *DequeueNode = queue->array[queue->front++];
    queue->size--;
    return DequeueNode;
}

struct TreeNode *createNode(int value) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->Root = value;
    newNode->Left = NULL;
    newNode->Right = NULL;
    return newNode;
}

void levelOrderTraversal(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }

    struct Queue *queue = createQueue(100);

    Enqueue(queue, root);

    while (!isQueueEmpty(queue)) {
        struct TreeNode *currentNode = Dequeue(queue);
        printf("%d ", currentNode->Root);

        if (currentNode-> Left != NULL) {
            Enqueue(queue, currentNode->Left);
        }

        if (currentNode->Right != NULL) {
            Enqueue(queue, currentNode->Right);
        }
    }

    free(queue->array);
    free(queue);
}

int main()
{
    // Example binary tree
    struct TreeNode *root = createNode(1);
    root->Left = createNode(2);
    root->Right = createNode(3);
    root->Left->Left = createNode(4);
    root->Left->Right = createNode(5);
    root->Right->Left = createNode(6);
    root->Right->Right = createNode(7);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);

    return 0;
}