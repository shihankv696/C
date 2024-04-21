#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int Top;
    int capacity;
    int *array;
};

struct QueueUsingStack {
    struct Stack *stack1;
    struct Stack *stack2;
};

struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(capacity * sizeof(stack));
    stack->capacity = capacity;
    stack->Top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(stack));
    return stack;
}

int isStackEmpty(struct Stack *stack) {
    return stack->Top == -1;
}

int isStackFull(struct Stack *stack) {
    return stack->Top == stack->capacity - 1;
}

void push(struct Stack *stack, int value) {
    if (isStackFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }

    stack->array[++stack->Top] = value;
}

int pop(struct Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack->array[stack->Top--];
}

void Enqueue(struct QueueUsingStack *queue, int value) {
    push(queue->stack1, value);
}

int Dequeue(struct QueueUsingStack *queue) {
    if (isStackEmpty(queue->stack1)) {
        printf("Queue Underflow\n");
        return -1;
    }

    if (isStackEmpty(queue->stack2)) {
        while 
    }
}