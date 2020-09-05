#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
}

bool Checking_Account::withdraw(double amount)  {
    amount += per_check_fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount){
    return Account::deposit(amount);
}
bool Checking_Account::transfer(Account *obj, double amount){
    return Account::transfer(obj, amount);
}
void Checking_Account::print(std::ostream &os) const {
      os << "[Checking_Account: " << name << ", " << balance<<".]";
}



