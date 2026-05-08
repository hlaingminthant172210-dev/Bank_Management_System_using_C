#include "bank_structure.h"

void createAccount(){

    AccountPtr newNode=(AccountPtr)malloc(sizeof(AccountSize));
    newNode->accNo=nextAccNo;
    nextAccNo++;


    printf("Generate account no: %d\n",newNode->accNo);

    printf("Enter name : ");
    scanf(" %[^\n]",newNode->accName);

    newNode->balance=0;
    newNode->historyCount=0;
    newNode->next=NULL; 

    if(head==NULL){
        head=newNode;
    }else{
        AccountPtr temp=head;

        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Account Created \n");

}

void displayAccounts(){
    AccountPtr temp=head;
    while(temp!=NULL){
        printf("Account No: %d | Account name: %s | Balance: %.2f \n",
               temp->accNo,temp->accName,temp->balance);
        temp=temp->next;
        return;
    }
    if(temp==NULL){
        printf("Account Not Found!\n");
    }
}

void updateAccount(){
    int accNo;
    printf("Enter account no: ");
    scanf("%d",&accNo);

    AccountPtr temp=head;
    while (temp!=NULL && temp->accNo!=accNo){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Account Not Found\n");
        return;
    }
    if(temp->accNo==accNo){
        printf("Enter new name : ");
        scanf(" %[^\n]",temp->accName);

        printf("Updated Successfully!\n");
        return;
    }

}

void deleteAccount(){
    int accNo;
    printf("Enter account no : ");
    scanf("%d",&accNo);

    AccountPtr prev=NULL;
    AccountPtr temp=head;
    if (temp!=NULL && temp->accNo==accNo)
    {
        head=temp->next; //I wrote temp=temp->next,It is false.
        free(temp);
        printf("Deleted account successfully!\n");
        return;
    }else{
        while (temp!=NULL && temp->accNo!=accNo)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            printf("Account Not Found\n");
            return;
        }
        prev->next=temp->next;
        free(temp);
        printf("Deleted account successfully!\n");
        return;
    }
}
