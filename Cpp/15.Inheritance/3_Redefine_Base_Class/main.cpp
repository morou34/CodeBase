#include "Account.h"
#include "Saving_Account.h"

int main(int argc, char const *argv[])
{
    Account pikolo{200};
    pikolo.withdraw(4000);
    pikolo.deposit(800);
    pikolo.withdraw(199.01);
    std::cout << pikolo << std::endl;

    std::cout << "____________________" << std::endl;
    Saving_Account appolo{1000, 5};
    Saving_Account ammolo{10'000, 2.99};
    appolo.deposit(3000);
    appolo.withdraw(1000);
    std::cout << appolo << std::endl;
    std::cout << ammolo << std::endl;

    std::cout << "____________________" << std::endl;
    Account *acc_ptr = new Saving_Account{4000, 3};
    std::cout << *acc_ptr << std::endl;

    return 0;
}