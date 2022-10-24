/*
    BANK MANAGEMENT DEMO USING "OOP"
    - Create Account
    - Add money to Account
    - Deposit money from Account
    - Add money to myCash from Bank Account
*/

#include <bits/stdc++.h>
using namespace std;
class BankAccount
{
public:
    string account_holder;
    int account_number;
    int age;
    string address;

protected:
    int balance;

private:
    string password;

public:
    BankAccount(string account_holder, string address, int age, string password)
    {
        this->account_holder = account_holder;
        this->address = address;
        this->age = age;
        this->password = password;
        this->account_number = rand() % 1000000000;
        this->balance = 0;
        cout << "YOUR ACC NO IS : " << this->account_number << endl;
    };
    int show_balance(string password)
    {
        return this->balance;
    }
    void addMoney(string password, int amount)
    {
        if (this->password == password && amount > 0)
        {
            this->balance += amount;
            cout << "Add money successfull!" << endl;
        }
        else
        {
            cout << "ERROR!!! \n invalid password / amount !" << endl;
        }
    };

    void depositMoney(string password, int amount)
    {
        if (this->password == password && this->balance > amount && amount > 0)
        {
            this->balance -= amount;
            cout << "Deposit money successfull!" << endl;
        }
        else
        {
            cout << "ERROR!!! \n invalid password/amount!" << endl;
        }
    };
    friend class MyCash;
};

class MyCash
{
protected:
    int balance;

public:
    MyCash()
    {
        this->balance = 0;
    };
    void add_money_from_bank(BankAccount *myAccount, string password, int amount)
    {

        if (myAccount->password == password && myAccount->balance > amount && amount > 0)
        {
            this->balance = amount;
            myAccount->balance -= amount;
            cout << "ADD money on mycash successful!" << endl;
        }
        else
        {
            cout << "ERROR, invalid credentials/password" << endl;
        };
    };
    int show_balance()
    {
        return balance;
    }
};

void account_status(BankAccount *myAccount, MyCash *myCash)
{
    string password;
    cout << "BALANCE QUERY-> ENTER YOUR PASSWORD:" << endl;
    cin >> password;
    cout << "Bank Balance :" << myAccount->show_balance(password) << endl;
    cout << "MyCash Balance :" << myCash->show_balance() << endl;
}
BankAccount *
createBankAccount()
{
    string account_holder, password, address;
    int age;
    cout << "Creating Account: ENTER:: \n name > address > age > passcode " << endl;
    cin >> account_holder >> address >> age >> password;
    BankAccount *myAccount = new BankAccount(account_holder, address, age, password);
    return myAccount;
};

void add_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "Add money Password: " << endl;
    cin >> password;
    cout << "Add money amount ;" << endl;
    cin >> amount;
    myAccount->addMoney(password, amount);
    cout << "Your Bank Balance is :" << myAccount->show_balance(password) << endl;
}

void deposit_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "deposit money -> Password: " << endl;
    cin >> password;
    cout << "deposit money -> Amount ;" << endl;
    cin >> amount;
    myAccount->depositMoney(password, amount);
}
void add_money_from_bank(MyCash *myCash, BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "Adding money to myCash ->> Password: " << endl;
    cin >> password;
    cout << "Adding money to myCash ->>  Amount ;" << endl;
    cin >> amount;
    myCash->add_money_from_bank(myAccount, password, amount);
};

int main()
{
    // creating bank acc and mycash
    BankAccount *myAccount = createBankAccount();
    MyCash *myCash = new MyCash();
    while (true)
    {
        cout << "Select option: " << endl;
        cout << "1. Add money to Bank" << endl;
        cout << "2. Deposit Money from Bank" << endl;
        cout << "3. Add Money to MyCash from Bank" << endl;
        cout << "0. EXIT" << endl;
        int option;
        cin >> option;
        if (option == 1)
        {
            add_money(myAccount);
            account_status(myAccount, myCash);
            continue;
        }
        else if (option == 2)
        {
            deposit_money(myAccount);
            account_status(myAccount, myCash);
            continue;
        }
        else if (option == 3)
        {
            add_money_from_bank(myCash, myAccount);
            account_status(myAccount, myCash);
            continue;
        }
        else
        {
            break;
        }
    }

    // calling functions
    // add_money(myAccount);
    // add_money_from_bank(myCash, myAccount);
    // deposit_money(myAccount);
    // account_status(myAccount, myCash);
    delete myAccount;
    delete myCash;
    return 0;
}
