#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE_ACCOUNT 100
#define MAX_SIZE 50
typedef struct 
{
    char Name[MAX_SIZE];
    int accountNumber;
    float Balence;
}Account;

void Display()
{
    printf("\nWelcome To Bank Management System.\n");
    printf("1. Add account\n");
    printf("2. Delete Account\n");
    printf("3. Add Money\n");
    printf("4. Check Balence.\n");
    printf("5. Exit\n");
}

void addAccount(Account Acc[], int *size)
{
    if (*size < MAX_SIZE_ACCOUNT)
    {
        printf("Enter The Name: ");
        scanf("%s", Acc[*size].Name);
        printf("Enter The Account Number: ");
        scanf("%d", Acc[*size].accountNumber);
        (*size)++;
    }
    else
    {
        printf("Sorry Task Limit reached. Cannot add more tasks.\n");
    }
}

void Delete_Account(Account Acc[], int *size, int Key)
{
    for (int i = 0; i < *size; i++)
    {
        if (Acc[i].accountNumber == Key)
        {
            Acc[i] = Acc[i + 1];
            printf("The account Deleted successfully\n");
            (*size)--;
            break;
        }
    }
}

void addmoney(Account Acc[], int size)
{
    printf("Eneter the Amount do want to add to your account\n");
    scanf("%f", Acc[size].Balence);
} 

void Balence(Account Acc[], int size)
{
    int Account;
    printf("Enter your Account number: ");
    scanf("%d", &Account);
    for (int i = 0; i < size; i++)
    {
        if (Acc[i].accountNumber == Account)
        {
            printf("Your Balence: %d");
            scanf("%d", Acc[i].Balence);
        }
    }
}

int main()
{
    Account Acc[MAX_SIZE_ACCOUNT];
    int numAccounts = 0;
    int choice;

    do
    {
        Display();
        printf("Enter Your Choice: ");
        scanf("%d ", &choice);

        switch (choice)
        {
            case 1:
            {
                addAccount(Acc, &numAccounts);
                break;
            }
            case 2:
            {
                int Delete;
                printf("Enter the Account number to Delete: ");
                scanf("%d", &Delete);
                Delete_Account(Acc, &numAccounts, Delete);
                break;
            }
            case 3:
            {
                addmoney(Acc, numAccounts);
                break;
            }
            case 4:
            {
                Balence(Acc, numAccounts);
                break;
            }
            case 5:
            {
                printf("Thanku for using me!\n");
                break;
            }
            default:
            {
                printf("Please Enter an correct Choice.\n");
            }
        }
    } while (1);

    return 0;
}
