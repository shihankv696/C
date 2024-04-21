/*Implement Queue Using Linked List*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    if (queue == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(EXIT_FAILURE);
    }

    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node *newNode = createNode(data);

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    }

    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d Enqueued to the queue.\n", data);
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    struct Node *temp = queue->front;
    int dequeued = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear == NULL;
    }

    free(temp);
    return dequeued;
}

int front(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is Empty.\n");
        exit(EXIT_FAILURE);
    }

    return queue->front->data;
}

int rear(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is Empty.\n");
        exit(EXIT_FAILURE);
    }

    return queue->rear->data;
}

void treverse(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is Empty.\n");
        return;
    }

    struct Node *temp = queue->front;
    printf("Queue Elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void Display() {
    printf("\nQueue Operation: \n");
    printf("1. Enqueue\n2. Dequeue\n3. Front\n4. rear\n5. Traverse\n6. Exit\n");
}

int main() {
    struct Queue *queue = createQueue();
    int choice, data;

    do {
        Display();
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter The Value To Enqueue ? ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            
            case 2:
                printf("Dequeued Element: %d\n", dequeue(queue));
                break;

            case 3:
                printf("Front Element: %d\n", front(queue));
                break;

            case 4:
                printf("Rear Element: %d\n", rear(queue));
                break;

            case 5:
                treverse(queue);
                break;

            case 6:
                printf("Exiting..\n");
                exit(0);
                break;

            default:
                printf("Invalid Choice Please Enter a valid option.\n");
        }
    } while (1);

    return 0;
}