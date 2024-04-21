/*Circular Single Linked List 2*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void InsertFirst(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }

    else {
        struct Node *lastNode = head;
        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }

        newNode->next = head;
        head = newNode;
        lastNode->next = head;
    }

    printf("Node With Value %d Inserted At The Beginning\n", value);
}

void InsertEnd(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }

    else {
        struct Node *lastNode = head;
        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
        newNode->next = head;
    }

    printf("Node With Value %d Inserted At The End\n", value);
}

void DeleteFirst() {
    if (head == NULL) {
        printf("List Is Empty. Cannot Delete From The Beginning.\n");
        return;
    }

    struct Node *temp = head;
    struct Node *lastNode = head;
    while (lastNode->next != head) {
        lastNode = lastNode->next;
    }

    head = head->next;
    lastNode->next = head;

    free(temp);
    printf("Node At The Beginning Deleted Successfully.\n");
}

void DeleteEnd() {
    if (head == NULL) {
        printf("List Is Empty. Cannot Delete From The End.\n");
        return;
    }

    struct Node *lastNode = head;
    struct Node *secondLastNode = NULL;

    while (lastNode->next != head) {
        secondLastNode = lastNode;
        lastNode = lastNode->next;
    }

    if (secondLastNode == NULL) {
        free(head);
        head = NULL;
    }

    else {
        secondLastNode->next = head;
        free(lastNode);
    }

    printf("Node At The End Deleted Successfully\n");
}

void search(int key) {
    if (head == NULL) {
        printf("List Is Empty. Cannot Search.\n");
        return;
    }

    struct Node *current = head;

    do {
        if (current->data == key) {
            printf("Node With Value %d Found.\n", key);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Node With Value %d Not Founded\n", key);
}

void Traverse() {
    if (head == NULL) {
        printf("List Is Empty.\n");
        return;
    }

    struct Node *current = head;

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("NULL\n");

}

int main() {
    int choice, value;

    do{
        printf("\nMenu\n1. Insert At Front\n2. Insert  At End\n3. Delete At Beginning\n4. Delete At End\n5. Search\n6. Traverse\n7. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            {
                printf("Enter The Value To Insert At The Beginning: ");
                scanf("%d", &value);
                InsertFirst(value);
                break;
            }

            case 2:
            {
                printf("Enter The Value To Insert At The End: ");
                scanf("%d", &value);
                InsertEnd(value);
                break;
            }

            case 3:
            {
                DeleteFirst();
                break;
            }

            case 4:
            {
                DeleteEnd();
                break;
            }

            case 5:
            {
                printf("Enter The Value To Search: ");
                scanf("%d", &value);
                search(value);
                break;
            }

            case 6:
            {
                Traverse();
                break;
            }

            case 7:
            {
                printf("Exiting The Program\n");
                exit(0);
            }

            default:
            {
                printf("Invalid Choice. Please Enter A Valid Option\n");
            }
        }
    } while (1);

    return 0;
}