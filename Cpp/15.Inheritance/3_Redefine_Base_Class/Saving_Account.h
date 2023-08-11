#ifndef _Saving_Account_H_
#define _Saving_Account_H_
#include "Account.h"

class Saving_Account : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const Saving_Account &acc);

protected:
    double interest_rate;

public:
    Saving_Account();
    Saving_Account(double balance, double rate);
    void deposit(double amount);
};

#endif // !