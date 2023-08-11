#include "Saving_Account.h"
#include <iostream>

Saving_Account::Saving_Account() {}
Saving_Account::~Saving_Account() {}
void Saving_Account::deposit(double amount)
{
    std::cout << "Saving_Account desposit: " << amount << std::endl;
}
void Saving_Account::withdraw(double amount)
{
    std::cout << "Saving_Account withdraw: " << amount << std::endl;
}