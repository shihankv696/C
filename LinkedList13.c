// Binary to decimal conversion

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode *head)
{
    int decimal = 0;
    while (head != NULL)
    {
        decimal = decimal * 2 + head->val;
        head = head->next;
    }
    return decimal;
}

struct ListNode *createList(int *nums, int size)
{
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    for (int i = 0; i < size; i++)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = nums[i];
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void displayList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

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
    int choice, val, size, decimal;

    do
    {
        printf("\nMenu:\n");
        printf("1. Create linked list\n");
        printf("2. Convert binary number to decimal\n");
        printf("3. Display linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the size of the linked list: ");
            scanf("%d", &size);
            printf("Enter elements for the linked list (0 or 1): ");
            int *nums = (int *)malloc(size * sizeof(int));
            for (int i = 0; i < size; i++)
                scanf("%d", &nums[i]);
            head = createList(nums, size);
            free(nums);
            printf("Linked list created successfully.\n");
            break;
        case 2:
            decimal = getDecimalValue(head);
            printf("Decimal value of the binary number: %d\n", decimal);
            break;
        case 3:
            printf("Linked list: ");
            displayList(head);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeList(head);
    return 0;
}
