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

AccountPtr head=NULL;

int nextAccNo=101;

void createAccount(){

    AccountPtr newNode=(AccountPtr)malloc(sizeof(AccountSize));
    newNode->accNo=nextAccNo;
    nextAccNo++;


    printf("Generate account no: %d\n",newNode->accNo);

    printf("Enter name : ");
    scanf(" %[^\n]",newNode->accName);

    newNode->balance=0;
    newNode->historyCount=0;
    newNode->next=NULL; //Don't forget this,'next' contains garbage value: linked list may crash

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
    printf("Created Account\n");

}

void displayAccounts(){
    AccountPtr temp=head;
    while(temp!=NULL){ //I directly use 'head' instead of using 'temp',it was false. And then I wrote temp->next!=NULL,it was also false.
        printf("Account No: %d | Account name: %s | Balance: %.2f \n",
               temp->accNo,temp->accName,temp->balance);
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Account Not Found!\n");
    }
}

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

void viewHistory(){
    int accNo;

    printf("Enter account no: ");
    scanf("%d",&accNo);

    AccountPtr temp=head;

    while (temp!=NULL && temp->accNo!=accNo)
    {
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Account Not Found!\n");
        return;
    }
    for(int i=0;i<temp->historyCount;i++){
        printf("%s\n",temp->history[i]);
    }
    
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Create\n2.Display\n3.Deposit\n4.Withdraw\n");
        printf("5.Transfer\n6.Check Balance\n7.Update\n");
        printf("8.Delete\n9.History\n10.Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAccounts(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: transfer(); break;
            case 6: checkBalance(); break;
            case 7: updateAccount(); break;
            case 8: deleteAccount(); break;
            case 9: viewHistory(); break;
            case 10: return 0;
            default: printf("Invalid\n");
        }
    }
}