#include <iostream>
#include <vector>
using namespace std;

// Transaction class
class Transaction {
private:
    string type;  
    float amount;

public:
    Transaction(string t, float a) : type(t), amount(a) {}

    void display() {
        cout << type << ": " << amount << endl;
    }
};

// Customer class
class Customer {
private:
    string name;
    int customerID;
    string contact;

public:
    Customer() {}

    void createCustomer() {
        cout << "Enter customer name: ";
        cin >> name;
        cout << "Enter customer ID: ";
        cin >> customerID;
        cout << "Enter contact number: ";
        cin >> contact;
    }

    void displayCustomer() {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Contact: " << contact << endl;
    }
};

// BankAccount class
class BankAccount {
private:
    int accountNumber;
    float balance;
    Customer customer;
    vector<Transaction> transactions;

    void showBalanceAndTransactions() {
        cout << "Current Balance: " << balance << endl;
        cout << "Transaction History:"<<endl;
        for (auto &t : transactions) {
            t.display();
        }
        cout << endl;
    }

public:
    void createAccount() {
        customer.createCustomer();
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter initial balance: ";
        cin >> balance;
    }

    void deposit() {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Deposit successful!"<<endl;
        showBalanceAndTransactions();
    }

    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= balance) {
            balance -= amount;
            transactions.push_back(Transaction("Withdrawal", amount));
            cout << "Withdrawal successful!"<<endl;
        } else {
            cout << "Insufficient balance!"<<endl;
        }
        showBalanceAndTransactions();
    }

    void display() {
        customer.displayCustomer();
        cout << "Account Number: " << accountNumber << endl;
        showBalanceAndTransactions();
    }
};

int main() {
    BankAccount account;
    int choice;

    account.createAccount();

    do {
        cout << "---- Banking Menu ----"<<endl;
        cout << "1. Deposit"<<endl;
        cout << "2. Withdraw"<<endl;
        cout << "3. Display Account"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: account.deposit(); break;
            case 2: account.withdraw(); break;
            case 3: account.display(); break;
            case 4: cout << "Thank you!"<<endl; break;
            default: cout << "Invalid choice!"<<endl;
        }

    } while(choice != 4);

    return 0;
}
