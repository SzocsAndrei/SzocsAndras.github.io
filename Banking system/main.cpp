// Study project made by Szocs Andras

#include <iostream>
#include <vector>
#include <string>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "I_Printable.h"
#include "Account_Util.h"
using namespace std; 



vector <Account *> accounts {};
void openacc();
void depositacc();
void withdrawacc();
void transferacc();
bool search_acc(string name);

int main() {
    //Test accounts
    Account *p2 = new Checking_Account("George");
    Account *p3 = new Savings_Account("John",200);
    Account *p4 = new Trust_Account("Emily",500,2.0);
    accounts.push_back(p2); accounts.push_back(p3); accounts.push_back(p4);
    char option {};
    cout.precision(2);
    cout << fixed;
    cout<<"This is a simple bank sistem application made by Szocs Andras as a student project."<<endl<<endl;
   

    do{
    cout<<endl<<"========================================="<<endl
           <<"Menu : "<<endl<<"Press N for opening a new account"<<endl
           <<"Press D for deposit"<<endl<<"Press W for withdraw"<<endl<<"Press T for transfer"<<endl 
           <<"Press S for searching an account"<<endl<<"Presa E for displayng all accounts"<<endl
           <<"Press Q to exit"<<endl;
    cin>>option;
    option = toupper(option);

    switch(option){
        
    case 'N' :
    openacc();
    break;
    
    case 'D' :
    depositacc();
    break;
    
    case 'W' :
    withdrawacc();
    break;
    
    case 'T' :
     transferacc();  
     break;
    
    case 'S' :
    {
    string name;
    cout<<"Enter the name of the account : ";
    cin.seekg(0,ios::end);
    cin.clear();
    getline(cin,name);
    search_acc(name);
    break;
    }
    
    case 'E' :
    display(accounts);
    break; 
    
    case 'Q' :
    cout<<"Have a nice day!"<<endl;
    break;
    
    default:
    cout<<"Not a valid option."<<endl;
    };
    } while(option != 'Q');
    return 0;
}

void openacc(){
    char option {}; string name; double balance; double rate;
    cout<<endl<<"Press C to open a Cheking Account"<<endl<<"Press S to open a Saving Account"
           <<endl<<"Press T to open a Trust Account"<<endl;
    cin>>option;
    option = toupper(option);
    
    switch(option){
        
        case 'C' :
        {cout<<endl<<"Enter a name for the new Checking Account ";
        cin.seekg(0,ios::end);
        cin.clear();
        getline(cin,name);
        cout<<"Enter a starting balance for the new Checking Account ";
        cin>>balance;
        Account *temp = new Checking_Account(name, balance);
        cout<<"The new account is : "<<endl<<*temp<<endl;
        accounts.push_back(temp);
        break;}
        
        case 'S' :
       {cout<<endl<<"Enter a name for the new Saving Account ";
        cin.seekg(0,ios::end);
        cin.clear();
        getline(cin,name);
        cout<<"Enter a starting balance for the new Saving Account ";
        cin>>balance;
        cout<<"Enter a interes rate for the new Saving Account ";
        cin>>rate;
        Account *temp = new Savings_Account(name, balance,rate);
        cout<<"The new account is : "<<endl<<*temp<<endl;
        accounts.push_back(temp);
       break;}
         
         case 'T' :
        {cout<<endl<<"Enter a name for the new Trust Account ";
        cin.seekg(0,ios::end);
        cin.clear();
        getline(cin,name);
        cout<<"Enter a starting balance for the new Trust Account ";
        cin>>balance;
        cout<<"Enter a interes rate for the new Trust Account ";
        cin>>rate;
        Account *temp = new Trust_Account(name, balance);
        cout<<"The new account is : "<<endl<<*temp<<endl;
        accounts.push_back(temp);
        break;}
        
        default :
        cout<<"Not a valid option"<<endl;
    }
}

bool searchacc_deposit( string name, int amount){
    for(auto account :accounts){
        if(account -> name == name){
           account -> deposit(amount);
          cout<<"The new balance for "<<account -> name<<" account is now : "<<account -> balance<<endl;
          return true;}
    }
    return false;
    }
    
    void searchacc_withdraw( string name, int amount){
     for(auto account :accounts){
        if(account -> name == name){
           account -> withdraw(amount);
        cout<<"The new balance for "<<account -> name<<" account is now : "<<account -> balance<<endl;}
        }
    }
    
bool search_acc(string name){
     int check {0};
     for(auto account :accounts){
        if(account -> name == name){
             cout<<"Account found : "<<*account<<endl;
             check = 1;
             return true;
         }
     } 
         if(check == 0)
          cout<<"Account not found."<<endl;
         return false;
}
    
void depositacc(){
    double amount; string name;
    cout<<"Enter the name of the account : "<<endl;
    cin.seekg(0,ios::end);
    cin.clear();
    getline(cin,name);
    if(search_acc(name)){
    cout<<"Enter the amount of money you want to deposit : "<<endl;
    cin>>amount;
   if(amount > 0 && searchacc_deposit(name ,amount))
       cout<<"Deposit successful"<<endl;
    else
    cout<<"The deposit is not posible."<<endl;}
}

void withdrawacc(){
    double amount; string name;
    cout<<"Enter the name of the account : "<<endl;
    cin.seekg(0,ios::end);
    cin.clear();
    getline(cin,name);
    if(search_acc(name)){
    cout<<"Enter the amount of money you want to withdraw : "<<endl;
    cin>>amount;
    searchacc_withdraw(name ,amount);
    cout<<"Withdraw successful"<<endl;}
}

void transferacc(){
    string name1, name2 {}; double amount; int count1 {0}; int count2 {0};
    cout<<"Please enter the name of the paying account : "; 
    cin.seekg(0,ios::end);
    cin.clear();
    getline(cin,name1);
    cout<<"Please enter the name of the receiving account : "; 
    cin.seekg(0,ios::end);
    cin.clear();
    getline(cin,name2);
    if(search_acc(name1) && search_acc(name2)){
        cout<<"Enter the amount you want to transfer : ";
        cin>>amount;
        for (auto account: accounts){
            if(account->name == name1)
            break;
            else
            count1++; }
        for (auto account: accounts){
            if(account->name == name2)
            break;
            else
            count2++; }
       if( accounts.at(count1) ->transfer(accounts.at(count2), amount)){
       cout<<"Transfer succesful, the updated accounts are : "<<*accounts.at(count1)<<endl<<*accounts.at(count2)<<endl;}
       else{
       cout<<"Transfer failed ,amount invalid"<<endl;}
    }else{
    cout<<"Invalid accounts, transfer failed."<<endl;}
}