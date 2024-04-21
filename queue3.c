/*Queue Implemented Using Two Stack*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

struct Stack
{
    int Top;
    int Arr[MAX_SIZE];
};

void initilize(struct Stack *stack)
{
    stack->Top = -1;
}

int isEmpty(struct Stack *stack)
{
    return (stack->Top == -1);
}

int isFull(struct Stack *stack)
{
    return (stack->Top == MAX_SIZE - 1);
}

void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }

    else
    {
        stack->Arr[++stack->Top] = value;
        printf("%d is Pushed Into Stack\n", value);
    }
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    else
    {
        return stack->Arr[stack->Top--];
    }
}

struct QueueUsingStack
{
    struct Stack stack1;
    struct Stack stack2;
};

void initilizeQueueUsingStack(struct QueueUsingStack *stack)
{
    initilize(&stack->stack1);
    initilize(&stack->stack2);
}

void Enqueue(struct QueueUsingStack *stack, int value)
{
   while (!isEmpty(&stack->stack1))
   {
       push(&stack->stack2, pop(&stack->stack1));
   }

   push(&stack->stack1, value);

   while (!isEmpty(&stack->stack2))
   {
       push(&stack->stack1, pop(&stack->stack2));
   }

   printf("%d Enqueued Into The Stack\n", value);
}

void Dequeue(struct QueueUsingStack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
    }

    else
    {
        int value = pop(&stack->stack1);
        printf("%d IS Dequeued From The Stack\n", value);
    }
}

void Display(struct QueueUsingStack *stack)
{
    if (isEmpty(&stack->stack1))
    {
        printf("Stack Underflow\n");
    }

    else
    {
        printf("Queue Elements: ");
        for (int i = 0; i <= stack->stack1.Top; ++i)
        {
            printf("%d ", stack->stack1.Arr[i]);
        }
        printf("\n");
    }
}