#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct
{
    char Title[MAX_SIZE];
    char Author[50];
    int year;
}BOOK;

void DisplayMenu()
{
    Printf("\nWelcome E-library. How can i help you\n");
    printf("1. Add books\n");
}

void Addbooks(BOOK book[], int *size)
{
    if (MAX_SIZE > *size)
    {
        printf("Enter title of book.");
        scanf("%[^\n]%*c", book[*size]);
        printf("Enter Author of book");
        scanf("%[^\n]%*c", book[*size]);
        printf("Enter year of book");
        scanf("%d", book[*size].year);
        (*size)++;
    }
    else
    {
        printf("Sorry the stroge is full cannot add more!\n");
    }
}

void Delete(BOOK Books[], int *size, char Delete)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(Books[i].Title, Delete) == 0)
        {
            Books[i] = Books[i + 1];
            printf("Deleted successfull\n");
            (*size)--;
            break;
        }
    }
}

int main()
{
    BOOK Books[MAX_SIZE];
    int size = 0;
    int choice;
   

    do
    {
        DisplayMenu();
        printf("Enter your chpice: ");
        scanf("%d ", &choice);
        switch(choice)
        {
            case 1:
            {
                Addbooks(Books, &size);
                break;
            }
            case 2:
            {
                int Delete[MAX_SIZE];
                printf("Enter Book Name to delete: ");
                scanf("%{^\n}s", Delete);
                DeleteBook(Books, size, Delete);
                break;
            }
            case 3:
            {
                Display(Books, size);
                break;
            }
            case 4:
            {
                printf("Exiting From The Book Data Base.\n");
                break;
            }
            default:
            {
                printf("You choose an wrong number.\n");
            }
        }
       
    } while (choice != 4);

    return 0;
}