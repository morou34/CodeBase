#ifndef Account_H_
#define Account_H_
#include <string>
class Account
{
private:
    std::string name;
    double balance;

public:
    void set_balance(double bal);
    double get_balance();
    std::string get_name();
    Account();
    Account(std::string name);
    Account(std::string name, double balance);
};

#endif