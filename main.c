#include <stdio.h>
#include <stdlib.h>
#define MAX_ACC 5
char names[MAX_ACC][20];
int pincodes[MAX_ACC];
int ideposit[MAX_ACC];
char cnic[MAX_ACC][15];

int acc_counter = 0;

void initialize()
{
    int i;
    for(i = 0; i < MAX_ACC; i++)
        ideposit[i] = -1;
}

int open(char name[20], int pin, int deposit, char id[15])
{
    strcpy(names[acc_counter], name);
    pincodes[acc_counter] = pin;
    ideposit[acc_counter] = deposit;
    strcpy(cnic[acc_counter], id);
    acc_counter++;
    return acc_counter - 1;
}

int deposit(int account_no, int pin, int amount)
{
    if(account_no < MAX_ACC && ideposit[account_no]!=-1)
    {
        if(pin == pincodes[account_no])
        {
            ideposit[account_no] = ideposit[account_no] + amount;
            return ideposit[account_no];
        }
        else
        {
            printf("Invalid Pin \n");
            return -1;
        }
    }
    else
    {
        printf("Account does not exist \n");
        return -1;
    }
}

int main() {
    char name[20];
    int pin;
    char id[15];
    int acc_no;
    int amount;
    int i;
    initialize();
    char choice;
    char more;
    do {
        printf("What do you want to do : \n");
        printf("Press O for opening bank account: \n");
        printf("Press W for withdrawing cash: \n");
        printf("Press D for depositing cash: \n");
        printf("Press T for transfering amount: \n");
        printf("Press B for checking balance: \n");
        scanf(" %c", &choice);
        switch (choice)
        {
            case 'O':
                printf("Enter your name: \n");
                scanf("%s", name);
                printf("Enter your pin: \n");
                scanf("%d", &pin);
                printf("Enter your initial deposit: \n");
                scanf("%d", &amount);
                printf("Enter your cnic: \n");
                scanf("%s", id);

                printf("Opening your account: \n");
                acc_no = open(name, pin, amount, id);

                printf("Your account is successfully opened : \n");
                printf("Account no = %d \n", acc_no);
                break;
            case 'W':
                break;
            case 'D':
                printf("Enter your account number: \n");
                scanf("%d", &acc_no);
                printf("Enter your pin: \n");
                scanf("%d", &pin);
                printf("Enter the amount you wish to deposit: \n");
                scanf("%d", &amount);
                int bal = deposit(acc_no, pin, amount);
                if(bal != -1)
                    printf("Updated balance: %d \n", bal);
                break;
            case 'T':
                break;
            default:
                printf("Please enter a valid choice \n");
        }
        printf("Press Y to do another transaction \n");
        scanf(" %c", &more);
    } while(more == 'Y' || more == 'y');


	return 0;
}

