#include <Stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct CircularQueue
{
    int front, rear;
    int Queue[MAX_SIZE];
};

void initilize(struct CircularQueue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct CircularQueue *queue)
{
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}

int isEmpty(struct CircularQueue *queue)
{
    return (queue->front == -1);
}

void Enqueue(struct CircularQueue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue Overflow\n");
        return;
    }
    else
    {
        if (isEmpty(queue))
        {
            queue->front = 0;
        }

        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->Queue[queue->rear] = value;
        printf("%d Is Enqueued To The Queue\n", value);
    }
}

void dequeue(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow\n");
        return;
    }
    else
    {
        int value = queue->Queue[queue->front];
        printf("%d Is Dequeued From The Queue\n", value);
        if (queue->front == queue->rear)
        {
            initilize(queue);
        }
        else
        {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
    }

}

void Display(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow\n");
        return;
    }

    else
    {
        printf("Queue Elements\n");
        int i = queue->front;
        do
        {
            /* code */
            printf("%d ", queue->Queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main()
{
    struct CircularQueue *myQueue;
    initilize(&myQueue);

    Enqueue(&myQueue, 10);
    Enqueue(&myQueue, 20);
    Enqueue(&myQueue, 30);

    Display(&myQueue);

    dequeue(&myQueue);

    Display(&myQueue);

}