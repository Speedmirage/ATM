//
//  Account.hpp
//  Assigment 1
//
//  Created by Addiel Almonte on 10/2/17.
//  Copyright © 2017 Addiel Almonte. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <string>
#include <iostream>


//Base class Account
class Account
{
private:
    int AccountNumber;
    std::string AccountName;
    double AccountBalance;
    
public:
    int getNumber(){return AccountNumber;}
    std::string getAccountName() {return AccountName;}
    double getAccountBalance() {return AccountBalance;}
    Account();
    void setAccountNumber(long int);
    void setAccountName(std::string);
    void setAccountBalance(double);
};
    
//Derived Classs Bank

class Bank : public Account
{
private:
    double Credit;
    double Debit;
    int RoutingNumber;
    
public:
    double getCredit(){return Credit;}
    double getDebit(){return Debit;}
    int getRoutingNumber() {return RoutingNumber;}
    void setCredit(double);
    void setDebit(double);
    void setRoutingNumber(int);
    Bank();
};

//Derived Class Credit Card


class CreditCard : public Account
{
private:
    int Limit;
    double Charge;
    int CreditCardNumber;
public:
    int getLimit(){return Limit;}
    double getCharge(){return Charge;}
    int getCreditCardNumber(){return CreditCardNumber;}
    void setlimit(int);
    void setcharge(double);
    void setCreditCardNumber(int);
    CreditCard();
};

//Credit Card Exception Handling

class CreditCardExept : public CreditCard //RuntimeExpt
{
private:
    std::string errMSG;
public:
    CreditCardExept(const std::string& err):errMSG(err){}
    std::string getError(){return errMSG;}
    void setError(std::string);
    
};

//Savings Sub-class

class Saving : public Bank
{
private:
    int MonthlyFee;
    double Deposit;
public:
    int getMonthlyFee(){return MonthlyFee;}
    double getDeposit(){return Deposit;}
    void setMonthlyFee(int);
    void setDeposit(double);
    Saving();
    
};

//Checking Sub-Class


class Checking : public Bank
{
private:
    double deposit;
    double withdraw;
public:
    double getdeposit(){return deposit;}
    int getwithdraw() {return withdraw;}
    void setdeposit(double);
    void setwithdraw(double);
    Checking();
    
};




#endif /* Account_hpp */
