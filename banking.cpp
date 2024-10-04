#include <iostream>
#include <string>
#include <fstream>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

    public:
    BankAccount(std::string accNumber, std::string holderName, double balance)
    : accountNumber(accNumber), accountHolderName(holderName), balance(balance) {}

    void saveToFile() const {
        std::ofstream outFile("banking.txt", std::ios::app);
        if (outFile) {
            outFile << accountNumber << " " << accountHolderName << " " << balance << std::endl;
        outFile.close();
        std::cout << "Account saved to file" << std::endl;
        } else {
            std::cout << "Error saving account to file" << std::endl;
        }
    }
    static BankAccount loadFromFile() {
        std::ifstream inFile("banking.txt");
        std::string accNumber, holderName;
        double initbalance;
        if (inFile) {
            getline(inFile, accNumber);
            getline(inFile, holderName);
            inFile >> initbalance;
            inFile.ignore();
            inFile.close();
            std::cout << "Account loaded from file" << std::endl;
            return BankAccount(accNumber, holderName, initbalance);
        } else {
            std::cerr << "Error loading account from file" << std::endl;
            return BankAccount("", "", 0.0);
        }
    }
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
    BankAccount myAccount = BankAccount::loadFromFile();
    if (myAccount.getBalance() == 0.0) {
        std::string accNumber, holderName;
        double initBalance;
        std::cout << "No account found. Let's create one.\n";
        std::cout << "Enter account number: ";
        std::cin >> accNumber;
        std::cout << "Enter account holder name: ";
        std::cin.ignore();
        std::cin >> holderName;
        std::cout << "Enter initial balance: ";
        std::cin >> initBalance;

        myAccount = BankAccount(accNumber, holderName, initBalance);
        myAccount.saveToFile();
    }

    int choice;
    do {
        std::cout << "\n--- Simple Banking System ---\n";
        std::cout << "1. View Account Info\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Check Balance\n";
        std::cout << "5. Save Account to File\n";
        std::cout << "6. Exit\n";
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
                std::cout << "Save changes to account?" << std::endl;
                myAccount.saveToFile();
            case 6:
                std::cout << "Exiting the system. Thank you!\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}