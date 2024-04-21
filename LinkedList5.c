/*Circular Double Linked List*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertFirst(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->prev = newNode->next = newNode;
    }

    else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    printf("Node With Value %d Inserted At The Beginning.\n", value);
}

void InsertEnd(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->prev = newNode->next = newNode;
    }

    else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }

    printf("Node With Value %d Is Inserted At The End\n", value);
}

void DeleteFirst() {
    if (head == NULL) {
        printf("List Is Empty. Cannot Delete From The Beginning.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    head->prev = temp->prev;
    temp->prev->next = head;

    free(temp);
    printf("Node At The Beginning Deleted Successfully.\n");
}

void DeleteEnd() {
    if (head == NULL) {
        printf("List Is Empty. Cannnot Delete From The End.\n");
        return;
    }

    struct Node *temp = head->prev;
    temp->prev->next = head;
    head->prev = temp->prev;

    free(temp);
    printf("Node At The End Deleted Successfully.\n");
}

void Traverse() {
    if (head == NULL) {
        printf("List Is Empty.\n");
        return;
    }

    struct Node *current = head;

    printf("Circular Double Linked List: ");
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);

    printf("NULL\n");
}

int main() {
    int choice, value;

    do {
        printf("\nMenu\n1. Insert At Beginning\n2. Insert At End\n3. Delete At Beginning\n4. Delete At End\n5. Traverse\n6. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter The Value To Insert At The Beginning: ");
                scanf("%d", &value);
                InsertFirst(value);
                break;

            case 2:
                printf("Enter The Value To Insert At The End: ");
                scanf("%d", &value);
                InsertEnd(value);
                break;

            case 3:
                DeleteFirst();
                break;
            case 4:
                DeleteEnd();
                break;
            case 5:
                Traverse();
                break;
            case 6:
                printf("Exiting The Program.\n");
                exit(0);
            default:
                printf("Invalid Choice. Please Enter A Valid Option.\n");
        }
    } while (1);

    return 0;
}