/*Middle of the Linked List*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    if (node == NULL)
    {
        printf("Memory Allocation Failed.\n");
        exit(EXIT_FAILURE);
    }

    node->data = data;
    node->next = NULL;
    return node;
}

void insert(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
        *head = newNode;
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted into the list.\n", data);
}

struct Node* middleNode(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void Display(struct Node* head) {
    if (head == NULL) {
        printf("List is Empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, data;

    do {
        printf("\nMENU: \n1. Insert Node\n2. Find Middle\n3. Display List\n4. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                if (head == NULL)
                    printf("List is Empty.\n");
                else 
                    printf("Middle Of The List: %d\n", middleNode(head)->data);
                break;
            
            case 3:
                Display(head);
                break;
            
            case 4:
                printf("Exiting..\n");
                break;

            default:
                printf("Invalid Choice. please Try Again.\n");
        }
    } while (1);

    return 0;
}