#include "bank_structure.h"

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
