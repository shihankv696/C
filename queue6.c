#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue 
{
    int front;
    int rear;
    int size;
    int *array;
};

struct Queue *createQueue(int capacity) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->array = (int *)malloc(capacity * sizeof(int));
    return queue;
}

bool isQueueEmpty(struct Queue *queue) {
    return queue->size == 0;
}

void Enqueue(struct Queue *queue, int value) {
    queue->array[++queue->rear] = value;
    queue->size++;
}

int Dequeue(struct Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Is Underflow\n");
        return -1;
    }

    queue->size--;
    return queue->array[queue->front++];
}

struct MyStack {
    struct Queue *q1;
    struct Queue *q2;
};

struct MyStack *createStack() {
    struct MyStack *stack = (struct MyStack *)malloc(sizeof(struct MyStack));
    stack->q1 = createQueue(100);
    stack->q2 = createQueue(100);
    return stack;
}

void push(struct MyStack *stack, int value) {
    Enqueue(stack->q2, value);

    while (!isQueueEmpty(stack->q1)) {
        Enqueue(stack->q2, Dequeue(stack->q1));
    }

    struct Queue *Temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = Temp;
}

int pop(struct MyStack *stack) {
    if (isQueueEmpty(stack->q1)) {
        printf("Stack Underflow\n");
        return -1;
    }

    return Dequeue(stack->q1);
}

int main() {
    struct MyStack *myStack = createStack();

    // Push elements
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    // Pop elements
    printf("Popped: %d\n", pop(myStack));
    printf("Popped: %d\n", pop(myStack));

    // Push more elements
    push(myStack, 40);
    push(myStack, 50);

    // Pop remaining elements
    while (!isQueueEmpty(myStack->q1))
    {
        printf("Popped: %d\n", pop(myStack));
    }

    free(myStack->q1->array);
    free(myStack->q1);
    free(myStack->q2->array);
    free(myStack->q2);
    free(myStack);

    return 0;
}