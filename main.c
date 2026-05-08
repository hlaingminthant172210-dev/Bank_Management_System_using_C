#include "bank_structure.h"

int main() {
    int choice;

    while (1) {
        printf("\n1.Create\n2.Display\n3.Deposit\n4.Withdraw\n");
        printf("5.Transfer\n6.Check Balance\n7.Update\n");
        printf("8.Delete\n9.History\n0.Exit\n");

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
            case 0: return 0;
            default: printf("Invalid\n");
        }
    }
}