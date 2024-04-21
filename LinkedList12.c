// Palidrome Using Linked List

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void displayList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL, *current = head, *nextNode = NULL;
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    displayList(prev);
    return prev;
}

bool isPalindrome(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("%d\n", slow->next->val);
    struct ListNode *secondHalf = reverseList(slow->next);
    struct ListNode *firstHalf = head;

    while (secondHalf != NULL)
    {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}



int main()
{
    struct ListNode *head = NULL;
    int choice, val;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert node\n");
        printf("2. Check palindrome\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
            newNode->val = val;
            newNode->next = NULL;
            if (head == NULL)
                head = newNode;
            else
            {
                struct ListNode *temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
            }
            break;
        case 2:
            if (isPalindrome(head))
                printf("List is palindrome.\n");
            else
                printf("List is not palindrome.\n");
            break;
        case 3:
            printf("List: ");
            displayList(head);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
