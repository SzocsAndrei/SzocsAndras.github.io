// Simple Account 
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <vector>
#include <iostream>
#include <string>
#include "I_Printable.h"
class Account: public I_Printable{
    friend bool searchacc_deposit(std::string name, int amount);
    friend void searchacc_withdraw( std::string name, int amount);
    friend bool  search_acc(std::string name);
    friend void transferacc();
 private:   
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) = 0 ;
    virtual bool withdraw(double amount) = 0;
    virtual bool transfer(Account *obj, double amount) = 0;
    virtual void print(std::ostream &os) const override;
    virtual~Account() = default;
};
#endif