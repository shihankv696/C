/*Single Linked List*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertNodeFirst(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("The %d value Is Inserted\n", value);
}

void insertNodeLast(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;

    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }

    else
    {
        newNode->data = value;
        if (head == NULL)
        {
            newNode->next = NULL;
            head = newNode;
            printf("The Value %d is Inserted\n", value);
        }

        else
        {
            head = temp;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = NULL;
            printf("The Value %d Is Inserted\n", value);
        }
    }
}

void RandomInsert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;

    int position;

    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }

    else
    {
        printf("Enter The Position To Inserted ? ");
        scanf("%d", &position);
        newNode->data = value;
        temp = head;

        for (int i = 0; i < position; ++i)
        {
            temp = temp->next;

            if (temp == NULL)
            {
                printf("Cannot Insert At %d this Location\n", position);
            }
        }

        newNode->next = temp->next;
        temp->next = newNode;
        printf("The %d is Insert at %d Position successfully\n");
    }
}

void DeleteFront()
{
    struct Node *ptr;

    if (ptr == NULL)
    {
        printf("Overflow\n");
        return;
    }

    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("The Node Deleted From The Begining\n");
    }
}

void DeleteLast()
{
    struct Node *ptr, *ptr1;

    if (head == NULL)
    {
        printf("List Is Empty\n");
        return;
    }

    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("Only One Node In The List Is Deleted\n");
    }

    else
    {
        ptr = head;

        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }

        ptr1->next = NULL;
        free(ptr);
        printf("Deleted Node From The Last\n");
    }
}

void DeleteRandom(int key)
{
    struct Node *current = head, *prev = NULL;

    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        head = current->next;
    }

    else
        prev->next = current->next;

    free(current);
    printf("Node With value %d Deleted successfully.\n", key);
}

void searchNode(int key)
{
    struct Node *current = head;

    while (current != NULL)
    {

        if (current->data == key)
        {

            printf("Node With Value %d found.\n", key);
            return;
        }

        current = current->next;
    }

    printf("Node With value %d Not Found.\n", key);
}

void traverseList()
{
    struct Node *current = head;

    printf("Linked List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice, value, key;

    do
    {
        printf("\nMenu:\n1. InsertNode At first\n2. InsertNode At Last\n3. InsertNode At Random\n4. Delete At Front\n5. Delete At Last\n6. Delete At Random\n7. Search\n8. Traverse\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("Enter The Value To Insert: ");
                scanf("%d", &value);
                insertNodeFirst(value);
                break;
            }

            case 2:
            {
                printf("Enter The Value To Insert: ");
                scanf("%d", &value);
                insertNodeLast(value);
                break;
            }

            case 3:
            {
                printf("Enter The VAlue To Insert ? ");
                scanf("%d", &value);
                RandomInsert(value);
                break;
            }

            case 4:
            {
                DeleteFront();
                break;
            }

            case 5:
            {
                DeleteEnd();
                break;
            }

            case 6:
            {
                printf("Enter The Value To Delete: ");
                scanf("%d", &key);
                DeleteRandom(key);
                break;
            }

            case 7:
            {
                printf("Enter The Value To Search: ");
                scanf("%d", &key);
                searchNode(key);
                break;
            }

            case 8:
            {
                traverseList();
                break;
            }

            case 9:
            {
                printf("Exiting The Program\n");
                exit(0);
            }

            default:
            {
                printf("Invalid Choice. Please Enter a Valid Option\n");
            }
            }
        } while (1);

    return 0;
}