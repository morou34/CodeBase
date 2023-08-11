#include "Account.h"
#include <iostream>

Account::Account() {}
Account::~Account() {}
void Account::deposit(double amount)
{
    std::cout << "Account desposit: " << amount << std::endl;
}
void Account::withdraw(double amount)
{
    std::cout << "Account withdraw: " << amount << std::endl;
}