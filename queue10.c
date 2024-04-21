/* Circular Queue*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

struct Queue {
    int front, rear;
    int size;
    int *array;
};

void createCircularQueue(struct Queue* queue, int capacity) {
    queue->array = (int *)malloc(capacity * sizeof(int));
    queue->size = capacity;
    queue->rear = queue->front = -1;
}

void Enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_SIZE) {
        printf("Queue OverFlow\n");
        return;
    }
    
    queue->rear++;

    if (queue->rear == queue->size - 1) {
        queue->rear = 0;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->array[queue->rear] = value;
    printf("%d Enqueud In to Queue", value);
}

int Dequeue(struct Queue* queue) {

    if (queue->front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    int x = queue->array[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    }

    else if (queue->front == queue->size - 1)
    {
        queue->front = 0;
    }

    else {
        queue->front++;
    }

    return x;
}

void Display(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    else {
        for (int i = queue->front; i <= queue->rear; ++i) {
            printf("%d ", queue->array[i]);
        }
    }
}

int main() {
    struct Queue queue;
    createCircularQueue(&queue, MAX_SIZE);

    int choice, value;

    do {
        printf("\nMenu\n1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\n Enter Your Choice ? ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
            {
                printf("Enter the value ? ");
                scanf("%d", &value);
                Enqueue(&queue, value);
                break;
            }

            case 2:
            {
                printf("%d Dequeued", Dequeue(&queue));
                break;
            }

            case 3:
            {
                Display(&queue);
                break;
            }

            case 4:
            {
                printf("Exiting The Program\n");
                exit(0);
            }

            default:
            {
                printf("Invalid Choice Please Choose a correct one!");
                break;
            }
        }
    } while (1);

    return 0;
}