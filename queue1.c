#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));

    return queue;
}

bool isEmpty(struct Queue *queue)
{
    return queue->size == 0;
}

bool isFull(struct Queue *queue)
{
    return queue->size == queue->capacity;
}

void Enqueue(struct Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue Overflow\n");
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = value;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", value);
}

int Dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return value;
}

int peek(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return queue->array[queue->front];
}

int rear(struct Queue *queue)
{
    if (queue == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    return queue->array[queue->rear];
}



void display(struct Queue *queue)
{
    printf("\nQueue Opertion\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Rear\n");
    printf("4. peek\n");
    printf("5. isEmpty\n");
    printf("6. isFull\n");
    printf("7. Exit\n");
    printf("Enter Your Choice ? ");
}

int main()
{
    int choice, value;
    struct Queue *queue = createQueue(10);

    while (1)
    {
        display(queue);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter The Value ? ");
            scanf("%d", &value);
            Enqueue(queue, value);
            break;
        }

        case 2:
        {
            printf("%d deequeued To Queue\n", Dequeue(queue));
            break;
        }

        case 3:
        {
            printf("%d Is Peek Of Queue\n", rear(queue));
            break;
        }

        case 4:
        {
            printf("%d Is Rear Of Queue\n", peek(queue));
            break;
        }

        case 5:
        {
            printf("Is Queue Is Empty ? %s\n", isEmpty(queue) ? "Yes" : "No");
            break;
        }

        case 6:
        {
            printf("Is Queue Is Full ? %s\n", isFull(queue) ? "Yes" : "No");
            break;
        }

        case 7:
        {
            printf("Exiting Program.\n");
            exit(0);
        }

        default:
        {
            printf("Invalid Input\n");
            break;
        }
        }
    }

    return 0;
}