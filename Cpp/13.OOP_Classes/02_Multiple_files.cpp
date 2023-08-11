#include <iostream>
#include "Account.h"

int main(int argc, char const *argv[])
{
    double Mouaad_bal, Ali_bal;
    Account Mouaad;
    Account Ali("Ali Danger");
    Account James("James", 444.24);

    Mouaad.set_balance(3000.43);
    Ali.set_balance(299.99);

    Mouaad_bal = Mouaad.get_balance();
    Ali_bal = Ali.get_balance();

    std::cout << "Mouaad's account balance: $" << Mouaad_bal << std::endl;
    std::cout << Ali.get_name() << "'s account balance: $" << Ali_bal << std::endl;

    std::cout << James.get_name() << "'s account balance: $" << James.get_balance() << std::endl;

    return 0;
}
