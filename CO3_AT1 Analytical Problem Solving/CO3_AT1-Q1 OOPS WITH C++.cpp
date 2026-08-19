#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    string name;
    long account_no;
    string type;
    double balance;

public:

    // Constructor
    BankAccount(string n, long acc, string t, double b)
    {
        name = n;
        account_no = acc;
        type = t;
        balance = b;
    }

    // Deposit amount
    void deposit(long acc, string n, double amount)
    {
        if (account_no == acc && name == n)
        {
            balance = balance + amount;
            cout << "Amount deposited successfully." << endl;
        }
        else
        {
            cout << "Invalid account number or name." << endl;
        }
    }

    // Withdraw amount
    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount withdrawn successfully." << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    // Display details
    void display()
    {
        cout << "\nName: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    // Destructor
    ~BankAccount()
    {
        cout << "Bank Account object destroyed." << endl;
    }
};

int main()
{
    string name, type;
    long account_no;
    double balance;
    double amount;
    long check_acc;
    string check_name;

    cout << "Enter depositor name: ";
    cin >> name;

    cout << "Enter account number: ";
    cin >> account_no;

    cout << "Enter account type: ";
    cin >> type;

    cout << "Enter initial balance: ";
    cin >> balance;

    BankAccount b(name, account_no, type, balance);

    cout << "\nEnter account number for deposit: ";
    cin >> check_acc;

    cout << "Enter customer name: ";
    cin >> check_name;

    cout << "Enter deposit amount: ";
    cin >> amount;

    b.deposit(check_acc, check_name, amount);

    cout << "\nEnter withdrawal amount: ";
    cin >> amount;

    b.withdraw(amount);

    b.display();

    return 0;
}