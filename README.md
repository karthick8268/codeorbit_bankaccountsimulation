# Bank Account Simulation Using C++

A menu-driven C++ console application that simulates basic banking operations, including deposits, withdrawals, balance checks, and transaction history.

The project uses a class to represent a bank account and a structure to store individual transactions. It validates user input, prevents withdrawals exceeding the available balance, and displays a transaction report before exiting.

## Project Overview

This application manages a single simulated bank account during one program session.

The user enters an account holder name, and the program creates an account with a sample account number and an opening balance of ₹0.00.

Users can deposit money, withdraw available funds, check their balance, and review successful transactions through a console menu.

## Features

### Account Creation

- Accepts the account holder's full name.
- Rejects empty or whitespace-only names.
- Assigns the sample account number `100001`.
- Initializes the balance to ₹0.00.
- Displays account details after creation.

### Deposit Money

- Accepts positive deposit amounts.
- Supports amounts with up to two decimal places.
- Updates the account balance after a successful deposit.
- Records the deposit in the transaction history.
- Prevents deposits that would exceed the account balance limit.

### Withdraw Money

- Accepts positive withdrawal amounts.
- Checks the available balance before processing a withdrawal.
- Rejects withdrawals exceeding the available balance.
- Allows withdrawal of the entire available balance.
- Records successful withdrawals in the transaction history.

### Check Balance

- Displays the current account balance.
- Formats monetary values with two decimal places.

### View Transaction History

Each successful transaction records:

- Transaction type
- Transaction amount
- Account balance after the transaction

Transactions appear in the order in which they occurred. Users can view the history from the menu, and the program automatically displays it when they select Exit.

### Input Validation

- Rejects invalid menu choices.
- Requires a whole-number menu choice from 1 to 5.
- Rejects zero and negative transaction amounts.
- Rejects non-numeric amount input.
- Rejects amounts with more than two decimal places.
- Rejects amounts exceeding the transaction limit.
- Prevents withdrawals when funds are insufficient.

## Technologies Used

| Technology | Purpose |
|---|---|
| C++ | Application logic |
| Standard C++ library | Input handling, formatting, strings, and transaction storage |
| Console / Terminal | User interface |

## Libraries Used

| Library | Purpose |
|---|---|
| `<iostream>` | Console input and output |
| `<iomanip>` | Table alignment and monetary formatting |
| `<string>` | Names, account numbers, and input text |
| `<sstream>` | Menu validation and formatted string creation |
| `<vector>` | Storing transaction history |
| `<cstdlib>` | Terminating the program when input closes |

## Programming Concepts Demonstrated

- Classes and objects
- Structures
- Encapsulation
- Constructors
- Private data members
- Public member functions
- Constant member functions
- Vectors
- Loops and conditional statements
- Switch statements
- String processing
- Input validation
- Integer-based monetary calculations
- Formatted console output

## Class Design

### BankAccount

The `BankAccount` class stores account details and provides methods for banking operations.

#### Private Data Members

| Member | Purpose |
|---|---|
| `accountHolder` | Stores the account holder's name |
| `accountNumber` | Stores the sample account number |
| `balance` | Stores the current balance in paise |
| `history` | Stores successful transaction records |

Keeping these members private ensures that account operations are performed through the class methods.

#### Public Methods

| Method | Purpose |
|---|---|
| `BankAccount()` | Initializes the account name, number, and starting balance |
| `displayAccountDetails()` | Displays the account holder, account number, and balance |
| `deposit()` | Validates and processes a deposit |
| `withdraw()` | Validates and processes a withdrawal |
| `displayBalance()` | Displays the current balance |
| `displayTransactionHistory()` | Displays successful transactions and the final balance |

## Transaction Structure

The `Transaction` structure represents one successful deposit or withdrawal.

| Field | Purpose |
|---|---|
| `type` | Identifies a deposit or withdrawal |
| `amount` | Stores the transaction amount in paise |
| `balanceAfter` | Stores the balance after the transaction |

A vector stores these records in chronological entry order.

Failed transactions and balance checks are not added to the history.

## Helper Functions

| Function | Purpose |
|---|---|
| `readLine()` | Reads a complete line of input |
| `readText()` | Accepts text that is not empty or whitespace-only |
| `readChoice()` | Validates menu selections |
| `readAmount()` | Validates monetary input and converts rupees into paise |
| `formatMoney()` | Converts paise into a string with two decimal places |

## Money Representation

The application stores money as integer paise using `long long`.

| Amount in Rupees | Stored Value in Paise |
|---|---:|
| ₹1.00 | 100 |
| ₹10.50 | 1050 |
| ₹125.75 | 12575 |
| ₹1000.00 | 100000 |

This approach avoids floating-point rounding errors during deposits and withdrawals.

Amounts are converted back to rupees when displayed.

### Accepted Amount Formats

Examples of valid input:

- `500`
- `500.5`
- `500.50`
- `0.25`

Enter amounts without currency symbols or commas. For amounts below one rupee, include the leading zero, such as `0.50`.

## Application Limits

| Setting | Value |
|---|---|
| Accounts per session | 1 |
| Opening balance | ₹0.00 |
| Minimum transaction amount | ₹0.01 |
| Maximum amount per transaction | ₹1,000,000,000.00 |
| Maximum account balance | ₹10,000,000,000.00 |
| Decimal places supported | Up to 2 |

These are limits defined by this simulation.

## Application Menu

| Option | Operation |
|---|---|
| 1 | Deposit Money |
| 2 | Withdraw Money |
| 3 | Check Balance |
| 4 | View Transaction History |
| 5 | Exit |

## Program Workflow

1. The application asks for the account holder's name.
2. A simulated account is created with a zero balance.
3. Account details and the main menu are displayed.
4. The user selects a banking operation.
5. The application validates the input.
6. Successful deposits and withdrawals update the balance and transaction history.
7. The menu repeats after each operation.
8. Selecting Exit prints the transaction history and final balance before closing.

## Requirements

- A C++ compiler supporting C++11 or later.
- A terminal or configured C++ development environment.
- The source code saved as `main.cpp`.

The application can be built using a configured environment such as Visual Studio Code, CLion, Code::Blocks, or a terminal with GCC.

## Installation and Execution

### 1. Download the Project

Download and extract the repository, or clone it using your Git client.

### 2. Open the Project Folder

Open a terminal in the folder containing `main.cpp`.

### 3. Compile the Application

**Windows with GCC / MinGW:**

```bash
g++ -std=c++11 main.cpp -o bank_account.exe
```

**Linux / macOS with an available g++ command:**

```bash
g++ -std=c++11 main.cpp -o bank_account
```

### 4. Run the Application

**Windows PowerShell:**

```powershell
.\bank_account.exe
```

**Windows Command Prompt:**

```bat
bank_account.exe
```

**Linux / macOS:**

```bash
./bank_account
```

You can also build and run `main.cpp` through your configured C++ IDE.

## Usage Guide

### Create the Account

Enter the account holder's name when prompted.

The application displays the account details with the sample account number and an opening balance of ₹0.00.

### Deposit Money

1. Select option **1**.
2. Enter a positive amount.
3. Review the deposit confirmation and updated balance.

### Withdraw Money

1. Select option **2**.
2. Enter a positive amount.
3. If sufficient funds are available, the withdrawal is processed.
4. Otherwise, the application displays an insufficient balance message.

### Check the Balance

Select option **3** to view the current balance.

### Review Transaction History

Select option **4** to view all successful deposits and withdrawals.

If no successful transactions exist, the application displays an appropriate message.

### Exit

Select option **5** to display the final transaction report and close the application.

## Example Session

Starting balance: **₹0.00**

| Step | Operation | Amount | Result | Balance |
|---|---|---:|---|---:|
| 1 | Deposit | ₹1000.00 | Successful | ₹1000.00 |
| 2 | Withdraw | ₹250.50 | Successful | ₹749.50 |
| 3 | Deposit | ₹100.25 | Successful | ₹849.75 |
| 4 | Withdraw | ₹1000.00 | Rejected: insufficient funds | ₹849.75 |

The transaction history contains only the three successful transactions:

| S.No. | Type | Amount | Balance After |
|---|---|---:|---:|
| 1 | Deposit | ₹1000.00 | ₹1000.00 |
| 2 | Withdrawal | ₹250.50 | ₹749.50 |
| 3 | Deposit | ₹100.25 | ₹849.75 |

**Final balance: ₹849.75**

## Suggested Manual Checks

Use these scenarios to verify the application:

| Scenario | Expected Behavior |
|---|---|
| Enter a blank account holder name | Requests a valid name |
| Check the initial balance | Displays ₹0.00 |
| Deposit ₹1000.00 | Updates the balance to ₹1000.00 |
| Withdraw ₹250.50 after that deposit | Updates the balance to ₹749.50 |
| Withdraw more than the available balance | Rejects the withdrawal without changing the balance |
| Withdraw the entire available balance | Updates the balance to ₹0.00 |
| Enter a zero or negative amount | Rejects the input |
| Enter letters as an amount | Rejects the input |
| Enter an amount with three decimal places | Rejects the input |
| Enter ₹0.01 as `0.01` | Accepts the amount |
| Enter an invalid menu option | Requests a valid choice |
| View history before any transactions | Displays a no-transactions message |
| Select Exit | Displays the history and final balance before closing |

These are suggested manual checks, not a claim of completed automated testing.

## Current Limitations

- Supports one simulated account per session.
- Uses a fixed sample account number.
- Stores account data and transaction history only in memory.
- Does not preserve data after the application closes.
- Does not include login, PIN verification, or authentication.
- Does not support transfers between accounts.
- Does not record transaction dates or times.
- Does not include failed attempts in the transaction history.
- Automatically prints the final report only when Exit is selected from the menu.
- Does not connect to a real banking service.

## Possible Future Enhancements

- Save and load account information using files.
- Support multiple accounts with unique account numbers.
- Add account authentication.
- Transfer money between accounts.
- Add transaction timestamps.
- Record failed transaction attempts.
- Export transaction reports.
- Search and filter transaction history.

These are proposed improvements and are not included in the current version.

## Author

**Karthick B**

GitHub repository 
https://github.com/karthick8268/codeorbit_bankaccountsimulation