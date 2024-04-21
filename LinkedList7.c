/*Implement Stack Using Linked List*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the stack
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Structure to represent the stack
struct Stack
{
    struct Node *top;
};

// Function to initialize the stack
struct Stack *initialize()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
    struct Node *node = newNode(data);
    node->next = stack->top;
    stack->top = node;
    printf("%d pushed to stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    struct Node *temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

// Function to traverse and display elements of the stack
void traverse(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Elements of the stack are: ");
    struct Node *current = stack->top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Stack *stack = initialize();
    int choice, element;

    do
    {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(stack, element);
            break;
        case 2:
            element = pop(stack);
            if (element != -1)
                printf("Popped element: %d\n", element);
            break;
        case 3:
            traverse(stack);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}