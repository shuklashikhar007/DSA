// encapsulation_example.cpp
// Demonstrates Encapsulation using a BankAccount class.

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    // Data is hidden from the outside world (private access specifier)
    string ownerName;
    double balance;

public:
    // Constructor to initialize the object safely
    BankAccount(string name, double initialBalance) {
        ownerName = name;
        // Validate initial balance instead of blindly assigning it
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }

    // Public method (controlled access) to deposit money
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << balance << "\n";
    }

    // Public method (controlled access) to withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            cout << "Insufficient funds!\n";
            return;
        }
        balance -= amount;
        cout << "Withdrew: " << amount << " | New Balance: " << balance << "\n";
    }

    // Getter: read-only controlled access to balance
    double getBalance() const {
        return balance;
    }

    // Getter for owner name
    string getOwnerName() const {
        return ownerName;
    }
};

int main() {
    BankAccount account("Rahul Sharma", 1000.0);

    cout << "Account Owner: " << account.getOwnerName() << "\n";
    cout << "Initial Balance: " << account.getBalance() << "\n\n";

    account.deposit(500);
    account.withdraw(200);
    account.withdraw(5000);   // Should fail (insufficient funds)
    account.deposit(-50);     // Should fail (invalid amount)

    // account.balance = 999999; // NOT ALLOWED - balance is private!
    // This is the core benefit of encapsulation: external code cannot
    // bypass the rules enforced by deposit() and withdraw().

    cout << "\nFinal Balance: " << account.getBalance() << "\n";

    return 0;
}
