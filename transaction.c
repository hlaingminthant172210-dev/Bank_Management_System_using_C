#include "bank_structure.h"

void deposit(){
    int accNo;
    float amount;

    printf("Enter account no: ");
    scanf("%d",&accNo);

    printf("Enter amount : ");
    scanf("%f",&amount);

    AccountPtr temp=head;
    while (temp!=NULL)
    {
        if(temp->accNo==accNo){
            temp->balance+=amount;

            sprintf((temp->history[temp->historyCount]),"Deposit: %.2f",amount);
            temp->historyCount++;

            printf("Deposit successful!\n");
            return;
        }
        temp=temp->next;
    }
    printf("Account Not Found\n");
}

void withdraw(){
    int accNo;
    float amount;

    printf("Enter acount number : ");
    scanf("%d",&accNo);

    printf("Enter withdraw amount : ");
    scanf("%f",&amount);

    AccountPtr temp=head;
    while (temp!=NULL)
    {
        if(temp->accNo==accNo){
            if(temp->balance<amount){
                printf("Not enough money!");
                return;
            }else{
                temp->balance-=amount;

                sprintf(temp->history[temp->historyCount],"Withdraw amount : %.2f",amount);
                temp->historyCount++;

                printf("Withdraw Successful! ");
                return;
            }
        }
        temp=temp->next;
    }
    printf("Account Not Found\n");

}

void transfer(){
    int transferFrom_accNo,transferTo_accNo;
    float amount;

    printf("Transfer from :");
    scanf("%d",&transferFrom_accNo);

    printf("Transfer to :");
    scanf("%d",&transferTo_accNo);

    printf("Enter amount : ");
    scanf("%f",&amount);


    AccountPtr A=head;
    AccountPtr B=head;

    while((A!=NULL && A->accNo!=transferFrom_accNo )){
        A=A->next;
    }
    while((B!=NULL && B->accNo!=transferTo_accNo )){
        B=B->next;
    }
    if(!A || !B){
        printf("Account Not Found!\n");
        return;
    }
    if(A->balance<amount){
        printf("Not enough money!\n");
        return;
    }
    A->balance-=amount;
    B->balance+=amount;

    sprintf(A->history[A->historyCount++],"Transfer from %d: %.2f",transferFrom_accNo,amount);
    sprintf(B->history[B->historyCount++],"Transfer to %d: %.2f",transferTo_accNo,amount);

    printf("Transfer Successful!\n");

}

void checkBalance(){
    int accNo;
    printf("Enter account no :");
    scanf("%d",&accNo);

    AccountPtr temp=head;
    while(temp!=NULL){
        if(temp->accNo==accNo){
            printf("Balance : %.2f",temp->balance);
            return;
        }
        temp=temp->next;
    }

    printf("Account Not Found!\n");

}

