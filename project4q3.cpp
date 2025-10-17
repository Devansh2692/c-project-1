#include <iostream>
#include <string>
using namespace std;

// Assuming BankAccount is already defined

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit; // e.g., -500.0

public:
    // Default Constructor
    CheckingAccount() : BankAccount(), overdraftLimit(0.0) {}

    // Parameterized Constructor
    CheckingAccount(string accNo, string holderName, double bal, double limit)
        : BankAccount(accNo, holderName, bal), overdraftLimit(limit) {}

    // Setter and Getter
    void setOverdraftLimit(double limit) { overdraftLimit = limit; }
    double getOverdraftLimit() const { return overdraftLimit; }

    // Method to check if overdraft is allowed
    bool checkOverdraft(double amount) const {
        return (balance - amount) >= overdraftLimit;
    }

    // Override withdraw to include overdraft check
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (!checkOverdraft(amount)) {
            cout << "Withdrawal exceeds overdraft limit!\n";
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        }
    }

    // Override displayAccountInfo to show overdraft
    void displayAccountInfo() const {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};
