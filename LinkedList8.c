/*Reverse A Single Linked List*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
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

void insert(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
        head = newNode;
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted into the list.\n", data);
}

struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL, *current = head, *nextNode = NULL;
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } 
    return prev;
}
/*
    struct Node *reverseList(struct Node *head) // Recursive Solution
    {
        
    }
*/

void Display(struct Node *head)
{
    printf("Linked List Elements: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, data;

    do
    {
        printf("\nMenu\n1. Insert Node\n2. Reverse List\n3. Display List\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = NULL;
            if (head == NULL)
                head = newNode;
            else
            {
                struct Node *temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
            }
            printf("%d inserted into the list.\n", data);
            break;

        case 2:
            head = reverseList(head);
            printf("List is reversed.\n");
            break;

        case 3:
            Display(head);
            break;

        case 4:
            printf("Exiting The Program.\n");
            exit(0);
            break;

        default:
            printf("Invalid Choice. please Try Again.\n");
        }
    } while (1);

    return 0;
}