#include <iostream>
#include <string>
using namespace std;

// Assuming BankAccount is already defined above

class FixedDepositAccount : public BankAccount {
private:
    int term; // in months
    const double annualInterestRate = 6.0; // Fixed 6% annual interest

public:
    // Default Constructor
    FixedDepositAccount() : BankAccount(), term(0) {}

    // Parameterized Constructor
    FixedDepositAccount(string accNo, string holderName, double bal, int t)
        : BankAccount(accNo, holderName, bal), term(t) {}

    // Setter and Getter
    void setTerm(int t) { term = t; }
    int getTerm() const { return term; }

    // Interest = (balance * rate * months) / (12 * 100)
    double calculateInterest() const {
        return (balance * annualInterestRate * term) / (12 * 100.0);
    }

    // Override display
    void displayAccountInfo() const {
        BankAccount::displayAccountInfo();
        cout << "Term (months): " << term << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Accrued Interest: $" << calculateInterest() << endl;
    }
};
