#include <iostream>
#include <string>
using namespace std;

// Assuming BankAccount is already defined as shown previously
class SavingsAccount : public BankAccount {
private:
    double interestRate; // percentage e.g., 5.0 for 5%

public:
    // Default Constructor
    SavingsAccount() : BankAccount(), interestRate(0.0) {}

    // Parameterized Constructor
    SavingsAccount(string accNo, string holderName, double bal, double rate)
        : BankAccount(accNo, holderName, bal), interestRate(rate) {}

    // Setter and Getter
    void setInterestRate(double rate) { interestRate = rate; }
    double getInterestRate() const { return interestRate; }

    // Method to calculate interest
    double calculateInterest() const {
        return (balance * interestRate) / 100.0;
    }

    // Override displayAccountInfo to include interest rate
    void displayAccountInfo() const {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Accrued Interest: $" << calculateInterest() << endl;
    }
};
