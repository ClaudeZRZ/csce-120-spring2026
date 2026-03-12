// TODO(student) - in class activity
#include <iostream>
#include <cassert>

class BankAccount {
    double balance_;

 public:
    BankAccount() : BankAccount(0) {}
    explicit BankAccount(double initial) : balance_{initial} {}
    void deposit(double amount) { balance_ =+ amount; }
    void withdraw(double amount) { balance_ -= amount; }
    double balance() { return balance_; }
};

int main() {
    BankAccount account(100.0);          // Given I have an account with $100
    assert(account.balance() == 100.0);  // Then my account balance should be $100

    account.deposit(20.0);               // When I deposit $20
    assert(account.balance() == 120.0);  // Then my account balance should be $120

    account.withdraw(25.0);              // When I withdraw $25
    assert(account.balance() == 95.0);   // Then my account balance should be $95

    account.withdraw(200.0);             // When I try to withdraw $200
    // expected behavior?                // Then ?

    std::cout << "All tests passed!\n";
    return 0;
}