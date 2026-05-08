#include <stdio.h>
#include <stdlib.h>

typedef struct Account{
    int accNo;
    char accName[20];
    float balance;

    char history[10][100];
    int historyCount;

    struct Account *next;

}AccountSize,*AccountPtr;

extern AccountPtr head;
extern int nextAccNo;

void createAccount();
void displayAccounts();
void deposit();
void withdraw();
void transfer();
void checkBalance();
void updateAccount();
void deleteAccount();
void viewHistory();

