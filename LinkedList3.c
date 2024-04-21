/*Circular single Linked List*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocatio Failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void InsertEnd(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        head->next = head;
    }

    else {
        struct Node *current = head;

        while (current->next != head) {
            current = current->next;
        }

        current->next = newNode;
        newNode->next = head;
    }

    printf("Node With Value %d Inserted At The End\n", value);
}

void DeleteEnd(int key) {
    if (head == NULL) {
        printf("List Is Empty. Cannot Delete\n");
        return;
    }

    struct Node *current = head, *prev = NULL;

    do {
        if (current->data == key) {
            if (prev == NULL) {
                if (current->next == head) {
                    head = NULL;
                }

                else {
                    struct Node *lastNode = head;
                    while (lastNode->next != head) {
                        lastNode = lastNode->next;
                    }

                    head = current->next;
                    lastNode->next = head;
                }
            }

            else {
                prev->next = current->next;
            }

            free(current);
            printf("Node With Value %d Deletec Successfully\n", key);
            return;
        }

        prev = current;
        current = current->next;
    } while (current != head);

    printf("Node With Value %d Not Found\n", key);
}

void searchNode(int key) {
    if (head == NULL) {
        printf("List Is Empty. Cannot Search\n");
        return;
    }

    struct Node *current = head;

    do {
        if (current->data == key) {
            printf("Node With Value %d found\n", key);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Node With Value %d Not Found\n", key);
}

void traverse() {
    struct Node *current = head;

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("head\n");
}

int main() {
    int choice, value, key;

    do {
        printf("\nMENU\n1. Insert End\n2. Delete\n3. Search\n4. Traverse\n5. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            {
                printf("Enter The Value To Insert: ");
                scanf("%d", &value);
                InsertEnd(value);
                break;
            }

            case 2:
            {
                if (head == NULL) {
                    printf("List Is Empty. Cannot Delete\n");
                }

                else {
                    printf("Enter The Value To Delete: ");
                    scanf("%d", &key);
                    DeleteEnd(key);
                }
                break;
            }

            case 3:
            {
                if (head == NULL ) {
                    printf("List Is Empty. Cannot Search\n");
                }

                else {
                    printf("Enter The Value To Search\n");
                    scanf("%d", &key);
                    searchNode(key);
                }
                break;
            }

            case 4:
            {
                if (head == NULL) {
                    printf("List Is Empty. Cannot Traverse\n");
                }

                else {
                    traverse();
                }
                break;
            }

            default:
                printf("Invalid Choice. Please Enter An Valid Option\n");
        }
    } while (1);

    return 0;
}