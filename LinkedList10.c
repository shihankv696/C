//  Merge two linked list

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    struct ListNode *merged = NULL;
    if (l1->val < l2->val)
    {
        merged = l1;
        merged->next = mergeTwoLists(l1->next, l2);
    }
    else
    {
        merged = l2;
        merged->next = mergeTwoLists(l1, l2->next);
    }
    return merged;
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

int main()
{
    struct ListNode *l1 = NULL, *l2 = NULL;
    int choice, val;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert into list 1\n");
        printf("2. Insert into list 2\n");
        printf("3. Merge lists\n");
        printf("4. Display list 1\n");
        printf("5. Display list 2\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert into list 1: ");
            scanf("%d", &val);
            struct ListNode *newNode1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            newNode1->val = val;
            newNode1->next = NULL;
            if (l1 == NULL)
                l1 = newNode1;
            else
            {
                struct ListNode *temp = l1;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode1;
            }
            break;
        case 2:
            printf("Enter value to insert into list 2: ");
            scanf("%d", &val);
            struct ListNode *newNode2 = (struct ListNode *)malloc(sizeof(struct ListNode));
            newNode2->val = val;
            newNode2->next = NULL;
            if (l2 == NULL)
                l2 = newNode2;
            else
            {
                struct ListNode *temp = l2;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode2;
            }
            break;
        case 3:
            printf("Merged list: ");
            displayList(mergeTwoLists(l1, l2));
            break;
        case 4:
            printf("List 1: ");
            displayList(l1);
            break;
        case 5:
            printf("List 2: ");
            displayList(l2);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
