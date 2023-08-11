#include "Saving_Account.h"
#include <typeinfo>

Saving_Account::Saving_Account() : Saving_Account{0.0, 0.0} {}
Saving_Account::Saving_Account(double balance, double rate) : Account{balance}, interest_rate{rate} {}

void Saving_Account::deposit(double amount)
{
    std::cout << "Amount: " << amount << std::endl;
    double somme = amount + (amount * interest_rate / 100);
    Account::deposit(somme);
}

std::ostream &operator<<(std::ostream &os, const Saving_Account &account)
{
    os << "Type: " << typeid(account).name() << " | Balance: $" << account.balance << " | Interest rate: %" << account.interest_rate;
    return os;
}
