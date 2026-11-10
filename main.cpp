#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

// Read one complete line of input.
string readLine(string message)
{
    string input;
    cout << message;

    if (!getline(cin, input))
    {
        cout << "\nInput closed.\n";
        exit(0);
    }

    return input;
}

// Read text that is not empty.
string readText(string message)
{
    while (true)
    {
        string input = readLine(message);

        if (input.find_first_not_of(" \t\r") != string::npos)
        {
            return input;
        }

        cout << "Input cannot be empty. Please try again.\n";
    }
}

// Read a valid menu choice.
int readChoice()
{
    while (true)
    {
        string input = readLine("Enter your choice: ");
        stringstream ss(input);

        int choice;
        char extra;

        if ((ss >> choice) && !(ss >> extra))
        {
            if (choice >= 1 && choice <= 5)
            {
                return choice;
            }
        }

        cout << "Invalid choice! Enter a whole number from 1 to 5.\n";
    }
}

// Read money and convert it into paise.
// Example: 125.50 rupees becomes 12550 paise.
long long readAmount(string message)
{
    while (true)
    {
        string input = readLine(message);

        // Remove spaces from the beginning and end.
        size_t first = input.find_first_not_of(" \t\r");

        if (first == string::npos)
        {
            cout << "Amount cannot be empty.\n";
            continue;
        }

        size_t last = input.find_last_not_of(" \t\r");
        input = input.substr(first, last - first + 1);

        long long rupees = 0;
        long long paise = 0;

        int decimalDigits = 0;
        int wholeDigits = 0;

        bool decimalPoint = false;
        bool valid = true;

        for (int i = 0; i < static_cast<int>(input.size()); i++)
        {
            char character = input[i];

            if (character == '.' && !decimalPoint)
            {
                decimalPoint = true;
            }
            else if (character >= '0' && character <= '9')
            {
                int digit = character - '0';

                if (!decimalPoint)
                {
                    rupees = rupees * 10 + digit;
                    wholeDigits++;

                    // Limit each transaction to Rs. 1,000,000,000.
                    if (rupees > 1000000000LL)
                    {
                        valid = false;
                        break;
                    }
                }
                else
                {
                    decimalDigits++;

                    if (decimalDigits > 2)
                    {
                        valid = false;
                        break;
                    }

                    paise = paise * 10 + digit;
                }
            }
            else
            {
                valid = false;
                break;
            }
        }

        if (wholeDigits == 0)
        {
            valid = false;
        }

        if (decimalPoint && decimalDigits == 0)
        {
            valid = false;
        }

        // Example: 10.5 means 10 rupees and 50 paise.
        if (decimalDigits == 1)
        {
            paise *= 10;
        }

        if (valid)
        {
            long long amount = rupees * 100 + paise;

            if (amount > 0 && amount <= 100000000000LL)
            {
                return amount;
            }
        }

        cout << "Invalid amount! Enter a positive amount with "
             << "at most 2 decimal places.\n";
        cout << "Maximum amount per transaction: Rs. 1000000000.00\n";
    }
}

// Convert paise to a formatted rupees string.
string formatMoney(long long paise)
{
    stringstream ss;

    ss << paise / 100 << "."
       << setw(2) << setfill('0') << paise % 100;

    return ss.str();
}

// Stores the details of one successful transaction.
struct Transaction
{
    string type;
    long long amount;
    long long balanceAfter;
};

// Represents a bank account.
class BankAccount
{
private:
    string accountHolder;
    string accountNumber;
    long long balance;

    vector<Transaction> history;

public:
    BankAccount(string holder, string number)
    {
        accountHolder = holder;
        accountNumber = number;
        balance = 0;
    }

    void displayAccountDetails() const
    {
        cout << "\n========== ACCOUNT DETAILS ==========\n";
        cout << "Account Holder : " << accountHolder << "\n";
        cout << "Account Number : " << accountNumber << "\n";
        cout << "Current Balance: Rs. "
             << formatMoney(balance) << "\n";
        cout << "=====================================\n";
    }

    void deposit(long long amount)
    {
        if (amount <= 0)
        {
            cout << "\nDeposit amount must be positive.\n";
            return;
        }

        // Keep the simulated account balance within this limit.
        const long long MAX_BALANCE = 1000000000000LL;

        if (amount > MAX_BALANCE - balance)
        {
            cout << "\nDeposit failed! Maximum account balance is "
                 << "Rs. " << formatMoney(MAX_BALANCE) << ".\n";
            return;
        }

        balance += amount;

        Transaction transaction;
        transaction.type = "Deposit";
        transaction.amount = amount;
        transaction.balanceAfter = balance;

        history.push_back(transaction);

        cout << "\nDeposit successful!\n";
        cout << "Amount Deposited: Rs. "
             << formatMoney(amount) << "\n";

        displayBalance();
    }

    void withdraw(long long amount)
    {
        if (amount <= 0)
        {
            cout << "\nWithdrawal amount must be positive.\n";
            return;
        }

        if (amount > balance)
        {
            cout << "\nWithdrawal failed! Insufficient balance.\n";
            cout << "Available Balance: Rs. "
                 << formatMoney(balance) << "\n";
            return;
        }

        balance -= amount;

        Transaction transaction;
        transaction.type = "Withdrawal";
        transaction.amount = amount;
        transaction.balanceAfter = balance;

        history.push_back(transaction);

        cout << "\nWithdrawal successful!\n";
        cout << "Amount Withdrawn: Rs. "
             << formatMoney(amount) << "\n";

        displayBalance();
    }

    void displayBalance() const
    {
        cout << "Current Balance: Rs. "
             << formatMoney(balance) << "\n";
    }

    void displayTransactionHistory() const
    {
        cout << "\n================ TRANSACTION HISTORY ================\n";
        cout << "Account Holder: " << accountHolder << "\n";
        cout << "Account Number: " << accountNumber << "\n";

        if (history.empty())
        {
            cout << "\nNo successful transactions recorded.\n";
        }
        else
        {
            cout << "\n" << string(64, '-') << "\n";

            cout << left << setw(8) << "S.No."
                 << setw(16) << "Type"
                 << right << setw(20) << "Amount (Rs.)"
                 << setw(20) << "Balance (Rs.)" << "\n";

            cout << string(64, '-') << "\n";

            for (int i = 0; i < static_cast<int>(history.size()); i++)
            {
                cout << left << setw(8) << i + 1
                     << setw(16) << history[i].type
                     << right << setw(20)
                     << formatMoney(history[i].amount)
                     << setw(20)
                     << formatMoney(history[i].balanceAfter)
                     << "\n";
            }

            cout << string(64, '-') << "\n";
        }

        cout << "\nFinal Balance: Rs. "
             << formatMoney(balance) << "\n";
        cout << "=====================================================\n";
    }
};

int main()
{
    cout << "========================================\n";
    cout << "        BANK ACCOUNT SIMULATION\n";
    cout << "========================================\n";

    string holder = readText("Enter account holder name: ");

    // A sample account number for this single-account simulation.
    BankAccount account(holder, "100001");

    cout << "\nAccount created successfully!\n";
    account.displayAccountDetails();

    while (true)
    {
        cout << "\n=============== MAIN MENU ===============\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
        cout << "=========================================\n";

        int choice = readChoice();

        switch (choice)
        {
            case 1:
            {
                long long amount =
                    readAmount("Enter deposit amount (Rs.): ");

                account.deposit(amount);
                break;
            }

            case 2:
            {
                long long amount =
                    readAmount("Enter withdrawal amount (Rs.): ");

                account.withdraw(amount);
                break;
            }

            case 3:
            {
                cout << "\n";
                account.displayBalance();
                break;
            }

            case 4:
            {
                account.displayTransactionHistory();
                break;
            }

            case 5:
            {
                // Print the transaction history before exiting.
                account.displayTransactionHistory();

                cout << "\nThank you for using "
                     << "Bank Account Simulation!\n";

                return 0;
            }
        }
    }
}