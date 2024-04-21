#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct CircularQueue {
    int front, rear;
    int capacity;
    int *array;
};

struct CircularQueue *createCircularQueue(int capacity)
{
    struct CircularQueue *cq = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    cq->front = -1;
    cq->rear = -1;
    cq->capacity = capacity;
    cq->array = (int *)malloc(capacity * sizeof(int));
    return cq;
}

bool isQueueEmpty(struct CircularQueue *queue) {
    return queue->front == -1;
}

bool isQueueFull(struct CircularQueue *queue) {
    return (queue->rear + 1) % queue->capacity;
}

void Enqueue(struct CircularQueue *queue, int value) {
    if (isQueueFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }

    if (isQueueEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->front] = value;
    printf("%d Is Enqueued To The Queue\n", value);
}

void Dequeue(struct CircularQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow\n");
        return ;
    }

    int value = queue->array[queue->front];
    printf("%d IS Dequeued From The Queue\n", value);

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }

    else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
}

void Display(struct CircularQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow\n");
    }

    printf("Circular Queue Elements: ");
    int i = queue->front;
    do {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    } while (i != (queue->rear + 1) % queue->capacity);
    printf("\n");
}

int main()
{
    struct CircularQueue *myCircularQueue = createCircularQueue(5);

    // Enqueue elements
    Enqueue(myCircularQueue, 10);
    Enqueue(myCircularQueue, 20);
    Enqueue(myCircularQueue, 30);

    // Display the circular queue
    Display(myCircularQueue);

    // Dequeue elements
    Dequeue(myCircularQueue);

    // Display the updated circular queue
    Display(myCircularQueue);

    free(myCircularQueue->array);
    free(myCircularQueue);

    return 0;
}