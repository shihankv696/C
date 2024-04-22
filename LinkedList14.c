// Retrieve the Nth node from the list or from the end

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

// Function to create a linked list
struct ListNode *createList()
{
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    int val;
    while (1)
    {
        printf("Enter value (-1 to stop): ");
        scanf("%d", &val);
        if (val == -1)
            break;
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }
    return head;
}

// Function to retrive N th node from front
struct ListNode *getNthNodeFromStart(struct ListNode *head, int n)
{
    if (head == NULL || n <= 0)
        return NULL;
    for (int i = 1; i < n; i++)
    {
        if (head == NULL)
            return NULL;
        head = head->next;
    }
    return head;
}

// Function to retrive N th node, from end 
struct ListNode *getNthNodeFromEnd(struct ListNode *head, int n)
{
    if (head == NULL || n <= 0)
        return NULL;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    for (int i = 0; i < n; i++)
    {
        if (fast == NULL)
            return NULL;
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

// To Display List
void displayList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// To Delete the Linked list Using dynamic memory allocation
void freeList(struct ListNode *head)
{
    while (head != NULL)
    {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct ListNode *head = NULL;
    int choice, n;
    struct ListNode *nthNode;

    do
    {
        printf("\nMenu:\n");
        printf("1. Create linked list\n");
        printf("2. Retrieve Nth node from start\n");
        printf("3. Retrieve Nth node from end\n");
        printf("4. Display linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (head != NULL)
                freeList(head);
            head = createList();
            printf("Linked list created successfully.\n");
            break;
        case 2:
            printf("Enter the position of the node from start: ");
            scanf("%d", &n);
            nthNode = getNthNodeFromStart(head, n);
            if (nthNode != NULL)
                printf("Node value at position %d from start: %d\n", n, nthNode->val);
            else
                printf("Invalid position.\n");
            break;
        case 3:
            printf("Enter the position of the node from end: ");
            scanf("%d", &n);
            nthNode = getNthNodeFromEnd(head, n);
            if (nthNode != NULL)
                printf("Node value at position %d from end: %d\n", n, nthNode->val);
            else
                printf("Invalid position.\n");
            break;
        case 4:
            printf("Linked list: ");
            displayList(head);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    if (head != NULL)
        freeList(head);

    return 0;
}
