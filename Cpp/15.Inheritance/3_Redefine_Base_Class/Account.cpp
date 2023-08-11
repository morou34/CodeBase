#include "Account.h"
#include <ostream>
#include <typeinfo>

Account::Account() : Account{0.0} {}
Account::Account(double balance) : balance{balance} {}

void Account::deposit(double amount)
{
    balance += amount;
    std::cout << "Deposit: $" << balance << std::endl;
}

void Account::withdraw(double amount)
{
    if (balance - amount < 0)
        std::cout << "Balance is unsuffisant." << std::endl;
    else
    {
        balance -= amount;
        std::cout << "Withdraw: $" << amount << std::endl;
    }

    std::cout << "Balance: $" << this->balance << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Account &account)
{
    os << "Type: " << typeid(account).name() << " | Balance: $" << account.balance;
    return os;
}