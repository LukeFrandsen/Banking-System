#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;
    std::vector<std::string> transactions;

    public:
    BankAccount(std::string accNumber, std::string holderName, double balance)
    : accountNumber(accNumber), accountHolderName(holderName), balance(balance) {}

    void saveToFile() const {
        std::ofstream outFile("banking.txt", std::ios::app);
        if (outFile) {
            outFile << accountNumber << " " << accountHolderName << " " << balance << std::endl;
            for (const auto& transaction : transactions) {
                outFile << transaction << std::endl;
            }
            outFile.close();
            std::cout << "Account saved to file" << std::endl;
        } else {
            std::cout << "Error saving account to file" << std::endl;
        }
    }
    static BankAccount loadFromFile() {
        std::ifstream inFile("banking.txt");
        std::string accNumber, holderName;
        double initBalance;

        if (inFile.is_open()) {
            if (inFile >> accNumber >> holderName >> initBalance) {
                BankAccount account(accNumber, holderName, initBalance);
                std::string transaction;
                while (getline(inFile, transaction)) {
                    if (!transaction.empty()) {
                        account.transactions.push_back(transaction);
                    }
                }
                std::cout << "Account loaded from file" << std::endl;
                return account;
            } else {
                std::cerr << "No account found in the file." << std::endl;
                return BankAccount("", "", 0.0);  // Blank account if no data
            }
        } else {
            std::cerr << "Error loading account from file" << std::endl;
            return BankAccount("", "", 0.0);
        }

        // std::ifstream inFile("./banking.txt");
        // std::string accNumber, holderName, initbalance;
        
        // while (!inFile.eof()){
        //     std::string line;
        //     getline(inFile, line);
        //     int spaceIndexOne = 0;
        //     int spaceIndexTwo = 0;
        //     for (int i = 0; i < line.length(); i++){
        //         if (line[i] == ' '){
        //             if(spaceIndexOne == 0){
        //                 spaceIndexOne = i;
        //             } else if (spaceIndexTwo == 0){
        //                 spaceIndexTwo = i;
        //                 break;
        //             }
                    
        //         }
        //     }

        //     accNumber = line.substr(0, spaceIndexOne);
        //     holderName = line.substr(spaceIndexOne + 1,spaceIndexTwo - spaceIndexOne - 1); 
        //     initbalance = line.substr(spaceIndexTwo + 1, line.length() - spaceIndexTwo - 1);
        //     std::cout << "Account number: " << accNumber << " holderName " << holderName << " initbalance " << (int)(initbalance) << std::endl;
        // }
        // if (inFile.is_open()) {
        //     std::cout << "No account found" << std::endl;
        //     return BankAccount("", "", 0.0);
        // }
        // std::cout << "Account number: ";
        // getline(inFile, accNumber);
        // std::cout << accNumber << std::endl;
        
        // if (inFile) {
        //     getline(inFile, accNumber);
        //     std::cout << "Account number: ";
        //     std::cout << accNumber << std::endl;
        //     getline(inFile, holderName);
        //     inFile >> initbalance;
        //     inFile.ignore();
        //     inFile.close();
        //     std::cout << "Account loaded from file" << std::endl;
        //     return BankAccount(accNumber, holderName, initbalance);
        // } else {
        //     std::cerr << "Error loading account from file" << std::endl;
        //return BankAccount("", "", 0.0);
        // }
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions.push_back("Deposit: " + std::to_string(amount));
            std::cout << "Deposit successful! Ne Balance: "<< balance << std::endl;
        } else {
            std::cout << "Invalid amount" << std::endl;
        }
    }
    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            transactions.push_back("Withdrawal: " + std::to_string(amount));
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
    void displayTransactionHistory() const {
        std::cout << "Transaction History: " << std::endl;
        for (const auto& transaction : transactions) {
            std::cout << transaction << std::endl;
        }
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
        std::cout << "6. View Transaction History\n";
        std::cout << "7. Exit\n";
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
                std::cout << "Save changes to account" << std::endl;
                myAccount.saveToFile();
                break;
            case 6:
                myAccount.displayTransactionHistory();
                break;
            case 7:
                std::cout << "Exiting the system. Thank you!\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}