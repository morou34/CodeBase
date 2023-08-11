#include "Account.h"

Account::Account()
{
}
Account::Account(std::string name)
{
    this->name = name;
}
Account::Account(std::string name, double balance) : name{name}, balance{balance}
{
}
void Account::set_balance(double bal)
{
    balance = bal;
}

double Account::get_balance()
{
    return balance;
}
std::string Account::get_name()
{
    return name;
}
