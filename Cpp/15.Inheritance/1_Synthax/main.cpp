#include "Account.h"
#include "Saving_Account.h"

int main(int argc, char const *argv[])
{
    Account account;
    Account *account_ptr = new Account;

    Saving_Account saving_acc;
    Saving_Account *saving_acc_ptr = new Saving_Account();

    account.deposit(19.99);
    account_ptr->deposit(39.99);
    saving_acc.withdraw(499.99);
    saving_acc_ptr->withdraw(199.99);

    delete account_ptr, saving_acc_ptr;
    return 0;
}
