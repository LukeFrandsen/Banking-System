#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

    public:
    BankAccount(std::string accNumber, std::string holderName, double balance)
    : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance) {}
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful! Ne Balance: "<< balance << std::endl;
        } else {
            std::cout << "Invalid amount" << std::endl;
        }
    }
    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal successful! New Balance: " << balance << std::endl;
            return true;
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds" << std::endl;
            return false;
        }
    }
    double getBalance() {
        return balance;
    }
    void displayAccountInfo() {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder Name: " << accountHolderName << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }
};

int main() {
    // Create a bank account for the user
    BankAccount myAccount("12345678", "John Doe", 500.0); // Sample account

    int choice;
    do {
        std::cout << "\n--- Simple Banking System ---\n";
        std::cout << "1. View Account Info\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Check Balance\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                myAccount.displayAccountInfo();
                break;
            case 2: {
                double depositAmount;
                std::cout << "Enter amount to deposit: ";
                std::cin >> depositAmount;
                myAccount.deposit(depositAmount);
                break;
            }
            case 3: {
                double withdrawAmount;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> withdrawAmount;
                myAccount.withdraw(withdrawAmount);
                break;
            }
            case 4:
                std::cout << "Your balance is: $" << myAccount.getBalance() << std::endl;
                break;
            case 5:
                std::cout << "Exiting the system. Thank you!\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}