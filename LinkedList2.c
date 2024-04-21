/* Double Linked List */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head;

void InsertNodeFront(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
    printf("The Value %d Is Inserted Successfully\n\n", value);
} 

void InsertNodeEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = head;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    else {
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }
}

void InsertNodeRandom(int value, int position) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }

    else {
        struct Node *current = head;
        int currentPosition = 1;

        while (currentPosition < position && current->next != NULL) {
            current = current->next;
            currentPosition++;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    printf("Node With Value %d Inserted At Position %d\n", value, position);
}

void DeleteFirst() {
    struct Node *ptr = head;

    if (head == NULL) {
        printf("UNDERFLOW\n");
        return;
    }

    else if (head->next == NULL) {
        head = NULL;
        free(head);
        printf("Node Is Deleted\n");
    }

    else {
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("Node Is Deleted\n");
    }
}

void DeleteLast() {
    struct Node *ptr = head;

    if (head == NULL) {
        printf("UNDERFLOW\n");
    }

    else if (head->next == NULL) {
        head = NULL;
        free(head);
        printf("Node Deleted\n");
    }

    else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->prev->next = NULL;
        free(ptr);
        printf("Node Deleted\n");
    }
}

void DeleteRandom(int position) {
    if (head == NULL) {
        printf("List Is Empty. Nothing To Delete\n");
        return;
    }

    struct Node *current = head;

    for (int i = 1; i < position; ++i) {
        current = current->next;

        if (current == NULL) {
            printf("Invalid Position. Node Not Found\n");
            return;
        }
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);

    printf("Node At Position %d Deleted Successfully\n", position);
}

void Search(int value) {
    struct Node *ptr = head;
    int i = 0, flag;

    if (ptr == NULL) {
        printf("UNDERFLOW\n");
    }

    else {
        while (ptr != NULL) {
            if (ptr->data == value) {
                printf("The Value %d Is On The Position %d\n", value, i + 1);
                flag = 0;
                break;
            }

            else {
                flag = 1;
            }
            ++i;
            ptr = ptr->next;
        }

        if (flag == 1) {
            printf("The %d is Not In Linked List\n", value);
        }
    }
}

void Traverse() {
    struct Node *ptr = head;

    printf("Elements: ");
    if (head == NULL) {
        printf("UNDERFLOW LIST\n");
    }

    else {
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
    }

    printf("NULL\n");
}

int main() {
    struct Node *Create;
    int choice, value, position;

    do {
        printf("\nMENU \n1. Insert At First\n2. Insert At End\n3. Insert At Random\n4. Delete At Front\n5. Delete At End\n6. Delete At Random\n7. Search\n8. Traverse\n9. Exit\nEnter Your Choice ? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
            {
                printf("Enter The Value ? ");
                scanf("%d", &value);
                InsertNodeFront(value);
                break;
            }

            case 2:
            {
                printf("Enter The Value ? ");
                scanf("%d", &value);
                InsertNodeEnd(value);
                break;
            }

            case 3:
            {
                printf("Enter The Value ? ");
                scanf("%d", &value);
                printf("Enter The Position To Insert ? ");
                scanf("%d", &position);
                InsertNodeRandom(value, position);
                break;
            }

            case 4:
            {
                DeleteFirst();
                break;
            }

            case 5:
            {
                DeleteLast();
                break;
            }

            case 6:
            {
                printf("Enter The Position To Deleted ? ");
                scanf("%d", &position);
                DeleteRandom(position);
                break;
            }

            case 7:
            {
                printf("Enter The Value ? ");
                scanf("%d", &value);
                Search(value);
                break;
            }

            case 8:
            {
                Traverse();
                break;
            }

            case 9:
            {
                printf("Exiting The Program. Good Bye\n");
                exit(0);
                break;
            }
        }
    } while (1);

    return 0;
}