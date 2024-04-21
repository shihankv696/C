#include <stdio.h>
#include <stdlib.h>

struct priorityQueue {
    int *heap;
    int capacity;
    int size;
};

struct priorityQueue *createPriorityQueue(int capacity) {
    struct priorityQueue *cp = (struct priorityQueue *)malloc(sizeof(struct priorityQueue));
    cp->heap = (int *)malloc((capacity + 1) * sizeof(int));
    cp->capacity = capacity;
    cp->size = 0;
    return cp;
}

void swap(int *a, int *b) {
    int Temp = *a;
    *a = *b;
    *b = Temp;
}

void maxHeapify(struct priorityQueue *queue, int index) {
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;
    int largest = index;

    if (leftChild < queue->size && queue->heap[index] > queue->heap[largest]) {
        largest = leftChild;
    }

    if (rightChild < queue->size && queue->heap[index] > queue->heap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&queue->heap[index], &queue->heap[largest]);
        maxHeapify(queue, largest);
    }
}

void insert(struct priorityQueue *queue, int priority)
{
    if (queue->size == queue->capacity) {
        printf("Queue Overflow\n");
        return;
    }

    queue->size++;
    int index = queue->size;
    queue->heap[index] = priority;

    while (index > 0 && queue->heap[index / 2] < queue->heap[index]) {
        swap(&queue->heap[index / 2], &queue->heap[index]);
        index /= 2;
    }
}

int extractMax(struct priorityQueue* queue)
{
    if (queue->size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }

    int maxPriority = queue->heap[1];
    queue->heap[1] = queue->heap[queue->size];
    queue->size--;

    maxHeapify(queue, 1);

    return maxPriority;
}

int isEmpty(struct priorityQueue *queue) {
    return queue->size == 0;
}

void freePriorityQueue(struct priorityQueue *queue)
{
    free(queue->heap);
    free(queue);
}

int main() {
    struct PriorityQueue *myPriorityQueue = createPriorityQueue(5);

    insert(myPriorityQueue, 3);
    insert(myPriorityQueue, 7);
    insert(myPriorityQueue, 6);

    while (!isEmpty(myPriorityQueue)) {
        printf("Max priority: %d\n", extractMax(myPriorityQueue));
    }

    freePriorityQueue(myPriorityQueue);

    return 0;
}