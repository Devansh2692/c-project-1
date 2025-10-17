#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Default Constructor
    BankAccount() : accountNumber(""), accountHolderName(""), balance(0.0) {}

    // Parameterized Constructor
    BankAccount(string accNo, string holderName, double bal)
        : accountNumber(accNo), accountHolderName(holderName), balance(bal) {}

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient funds.\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    // Get current balance
    double getBalance() const {
        return balance;
    }

    // Display account info
    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};
