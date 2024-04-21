/*Number Of Recent Calls*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

struct RecentCounter
{
    int front, rear;
    int items[MAX_SIZE];
};

void initializeQueue(struct RecentCounter *rc)
{
    rc->front = -1;
    rc->rear = -1;
}

int isFull(struct RecentCounter *rc)
{
    return (rc->rear == MAX_SIZE - 1);
}

int isEmpty(struct RecentCounter *rc)
{
    return (rc->front == -1);
}

void enqueue(struct RecentCounter *rc, int data)
{
    if (isFull(rc))
    {
        // Implement queue resizing logic if needed
        printf("Queue is full. Cannot enqueue.\n");
    }
    else
    {
        if (isEmpty(rc))
        {
            rc->front = 0;
        }
        rc->items[++rc->rear] = data;
    }
}

void trimOldRequests(struct RecentCounter *rc, int currentTime)
{
    // Remove requests that are older than 3000 milliseconds
    while (!isEmpty(rc) && rc->items[rc->front] < (currentTime - 3000))
    { 
        if (rc->front == rc->rear)
        {
            initializeQueue(rc);
        }
        else
        {
            rc->front++;
        }
    }
}

int ping(struct RecentCounter *rc, int t)
{
    enqueue(rc, t);
    trimOldRequests(rc, t);
    return (rc->rear - rc->front + 1);
}

int main()
{
    struct RecentCounter myCounter;
    initializeQueue(&myCounter);

    // Example usage
    printf("Ping at time 1, count: %d\n", ping(&myCounter, 1));
    printf("Ping at time 100, count: %d\n", ping(&myCounter, 100));
    printf("Ping at time 3001, count: %d\n", ping(&myCounter, 3001));
    printf("Ping at time 3002, count: %d\n", ping(&myCounter, 3002));

    return 0;
}
