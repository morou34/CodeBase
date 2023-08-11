#ifndef _Saving_Account_H_
#define _Saving_Account_H_

#include "Account.h"

class Saving_Account : public Account
{
public:
    Saving_Account();
    ~Saving_Account();
    void deposit(double amount);
    void withdraw(double amount);
};

#endif // !1