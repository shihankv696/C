#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Deque {
    int Front, Rear;
    int capacity;
    int *array;
};

struct Deque *createDeque(int capacity) {
    struct Deque *deque = (struct Deque *)malloc(sizeof(struct Deque));
    deque->Front = -1;
    deque->Rear = 0;
    deque->capacity = capacity;
    deque->array = (int *)malloc(capacity * sizeof(int));
    return deque;
}

int isEmpty(struct Deque *deque) {
    return deque->Front == -1;
}

int isFull(struct Deque *deque)
{
    return (deque->Front == 0 && deque->Rear == deque->capacity - 1) || (deque->Front == deque->Rear + 1);
}

void EnqueuFront(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Queue Overflow\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->Front = deque->Rear = 0;
    }

    else if (deque->Front == 0) {
        deque->Front = deque->capacity - 1;
    }

    else {
        deque->Front--;
    }

    deque->array[deque->Front] = value;
    printf(" Inserted % d at the front of the Deque.\n ", value);
}

void EnqueuRear(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Queue Overflow\n");
        return;
    }

    if (isEmpty(deque)) {
        deque->Front = deque->Rear = 0;
    }

    else if (deque->Rear == deque->capacity - 1) {
        deque->Front = 0;
    }

    else {
        deque->Rear++;
    }

    deque->array[deque->Rear] = value;
    printf("Inserted %d at the front of the Deque.\n", value);
}

void deleteFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Queue UnderFlow\n");
        return;
    }

    if (deque->Front == deque->Rear) {
        deque->Front = -1;
        deque->Rear = 0;
    }

    else if (deque->Front = deque->capacity - 1) {
        deque->Front = 0;
    }

    else {
        deque->Front++;
    }

    printf("Deleted element from the front of the Deque.\n");
}

void deleteRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Queue Underflow\n");
        return;
    }

    if (deque->Front == deque->Rear) {
        deque->Front = -1;
        deque->Rear = 0;
    }

    else if (deque->Rear == 0) {
        deque->Rear = deque->capacity - 1;
    }

    else {
        deque->Rear--;
    }

    printf("Deleted element from the Rear of the Deque.\n");
}

int getFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Queue Underflow\n");
        return -1;
    }

    return deque->array[deque->Front];
}

int getRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Queue Underflow\n");
        return -1;
    }

    return deque->array[deque->Rear];
}

void displayDeque(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Elements of the Deque are: ");
    int i = deque->Front;

    while (1) {
        printf("%d ", deque->array[i]);

        if (i == deque->Rear) {
            break;
        }

        i = (i + 1) % deque->capacity;
    }
    printf("\n");
}

void freeDeque(struct Deque *deque) {
    free(deque->array);
    free(deque);
}

int main()
{
    struct Deque *deque = createDeque(MAX_SIZE);
    int choice, value;

    do
    {
        printf("\n----- Deque Operations -----\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Get Front Element\n");
        printf("6. Get Rear Element\n");
        printf("7. Display Deque\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert at the front: ");
            scanf("%d", &value);
            EnqueuFront(deque, value);
            break;
        case 2:
            printf("Enter the value to insert at the rear: ");
            scanf("%d", &value);
            EnqueuRear(deque, value);
            break;
        case 3:
            deleteFront(deque);
            break;
        case 4:
            deleteRear(deque);
            break;
        case 5:
            printf("Front Element: %d\n", getFront(deque));
            break;
        case 6:
            printf("Rear Element: %d\n", getRear(deque));
            break;
        case 7:
            displayDeque(deque);
            break;
        case 8:
            printf("Exiting the program.\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 8);

    // Free allocated memory
    freeDeque(deque);

    return 0;
}
