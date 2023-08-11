#ifndef _Account_H_
#define _Account_H_
#include <ostream>
#include <iostream>
// #include "Saving_Account.h"

class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
    friend class Saving_Account;

protected:
    double balance;

public:
    Account();
    Account(double balance);
    void deposit(double amount);
    void withdraw(double amount);
};

#endif
