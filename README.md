# Bank Management System in C

## Overview

This is a simple Bank Management System project written in C language using Linked List data structure.

The project can create bank accounts and perform some basic banking operations like deposit, withdraw, transfer money, check balance, and view transaction history.

I made this project to practice Data Structures and understand how Linked List can be used in a real application.

---

## Features

- Create New Account
- Display All Accounts
- Update Account Information
- Delete Account
- Deposit Money
- Withdraw Money
- Transfer Money
- Check Balance
- View Transaction History

---

## Data Structure Used

This project uses a Single Linked List.

Each account is stored as a node containing:
- Account Number
- Account Name
- Balance
- Transaction History
- Pointer to Next Node

Example:

```text
Head → Account1 → Account2 → NULL
```

Linked List is useful because accounts can be added or deleted dynamically during runtime.

---

## How the Program Works

### Create Account
When a user creates an account:
- memory is allocated using `malloc()`
- account number is generated automatically
- the new account is added into the linked list

### Deposit
The program searches the account using account number.
If the account exists:
- deposit amount is added to balance
- transaction history is updated

### Withdraw
The program first checks balance.
If balance is enough:
- money is deducted
- history is stored

### Transfer
The program searches both sender and receiver accounts.
If both accounts exist and balance is enough:
- money is transferred
- histories of both accounts are updated

### Delete Account
The linked list is traversed to find the account node.
After finding the node:
- it is removed from linked list
- memory is freed using `free()`

### View History
Every account stores simple transaction records.
The program prints all saved transaction history for that account.

---

## Files Used

```text
main.c             → menu and main program
bank_structure.h   → structure and function declarations
data.c             → global variables
account.c          → account related functions
transaction.c      → deposit, withdraw, transfer, checkBalance
history.c          → transaction history
```

---

## Concepts Practiced

- Linked List
- Pointer
- Dynamic Memory Allocation
- Structures
- Multiple Source Files
- String Functions

---

## Compile and Run

### Compile

```bash
gcc main.c data.c account.c transaction.c history.c -o bank
```

### Run

```bash
./bank
```

---

## Limitations

- Data is not saved permanently
- Transaction history size is fixed
- No login system

---

## Future Improvements

In the future, this project can be improved by adding:
- File handling
- Login system
- Better UI
- Search and sorting features

---

## Conclusion

This project helped me understand Linked List more clearly and improved my understanding of pointers, structures, and multi-file programming in C.