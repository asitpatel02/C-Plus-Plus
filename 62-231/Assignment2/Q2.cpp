#include<simplecpp>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
    vector<string> transactions;

public:
    /**
     * @brief Constructor to initialize the BankAccount object.
     *
     * @param accNumber The account number.
     * @param accHolderName The account holder's name.
     * @param initialBalance The initial balance of the account.
     */
    BankAccount(int accNumber, string accHolderName, double initialBalance) {
        accountNumber = accNumber;
        accountHolderName = accHolderName;
        balance = initialBalance;
    }

    /**
     * @brief Deposits the specified amount into the account.
     *
     * @param amount The amount to be deposited.
     */
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Error: Invalid deposit amount." << endl;
            return;
        }
        balance += amount;
        transactions.push_back("Deposit: +" + doubleToString(amount));
    }

    /**
     * @brief Withdraws the specified amount from the account.
     *
     * @param amount The amount to be withdrawn.
     */
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Invalid withdrawal amount." << endl;
            return;
        }
        if (balance >= amount) {
            balance -= amount;
            transactions.push_back("Withdrawal: -" + doubleToString(amount));
        } else {
            cout << "Insufficient funds." << endl;
        }
    }


    /**
     * @brief Gets the current balance of the account.
     *
     * @return The current balance.
     */
    double getBalance() {
        return balance;
    }

    /**
     * @brief Displays the account balance.
     */
    void displayBalance() {
        cout << "Balance: $" << balance << endl;
    }

    /**
     * @brief Displays the account details.
     */
    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        displayBalance();
    }

    /**
     * @brief Displays all the transactions made on the account.
     */
    void displayTransactions() {
        cout << "----- All Transactions -----" << endl;
        for (const string &transaction : transactions) {
            cout << transaction << endl;
        }
    }

private:
    /**
     * @brief Converts a double value to a string.
     *
     * @param value The double value to be converted.
     * @return The string representation of the double value.
     */
    string doubleToString(double value) {
        stringstream ss;
        ss << value;
        return ss.str();
    }
};

int main() {
    // Ask for opening balance
    double openingBalance;
    cout << "Enter opening balance: $";
    cin >> openingBalance;

    while (cin.fail()) {
        cout << "Error: Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter opening balance: $";
        cin >> openingBalance;
    }

    // Create a bank account object
    BankAccount account1(190309, "Asit Patel", openingBalance);

    // Show initial account balance
    cout << "\nInitial Account Balance: $" << openingBalance << endl;
    account1.display();

    char choice;
    do {
        account1.displayBalance();
        cout << "\nEnter the command (D for deposit, W for withdrawal, Q to quit): ";
        cin >> choice;

        // Convert the input to uppercase
        choice = toupper(choice);

        if (choice == 'D' || choice == 'd') {
            // Deposit some money
            double depositAmount;
            cout << "Enter deposit amount: $";
            cin >> depositAmount;
            if (cin.fail()) {
                cout << "Error: Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            account1.deposit(depositAmount);
        } else if (choice == 'W' || choice == 'w') {
            // Withdraw some money
            double withdrawAmount;
            cout << "Enter withdrawal amount: $";
            cin >> withdrawAmount;
            if (cin.fail()) {
                cout << "Error: Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (withdrawAmount > account1.getBalance()) {
                cout << "Insufficient funds." << endl;
            } else {
                account1.withdraw(withdrawAmount);
            }
        }
    } while (choice != 'Q' && choice != 'q');

    // Show final account details
    cout << "\nFinal Account Details:\n";
    account1.display();

    // Show all transactions
    account1.displayTransactions();

    return 0;
}
