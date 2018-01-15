//
//  Account.cpp
//  Assigment 1
//
//  Created by Addiel Almonte on 10/2/17.
//  Copyright © 2017 Addiel Almonte. All rights reserved.
//

#include "Account.hpp"
#include <iostream>
#include <string>
using namespace std;

Account::Account(){
    AccountNumber = 0;
    AccountBalance = 0;
}
void Account::setAccountNumber(long int AccountN){AccountNumber = AccountN;}
void Account::setAccountName(std::string name){AccountName = name;}
void Account::setAccountBalance(double Balance){AccountBalance = Balance;}

Bank::Bank(){
    Credit = 0;
    Debit = 0;
    RoutingNumber = 0;
    
}
void Bank::setCredit(double c){Credit = c;}
void Bank::setDebit(double d){Debit = d;}
void Bank::setRoutingNumber(int rn){RoutingNumber = rn;}

CreditCard::CreditCard(){
    Limit = 0;
    Charge = 0;
    CreditCardNumber = 0;
}
void CreditCard::setlimit(int l){Limit = l;}
void CreditCard::setcharge(double ch){Charge = ch;}
void CreditCard::setCreditCardNumber(int ccn){CreditCardNumber = ccn;}

void CreditCardExept::setError(std::string Error){errMSG = Error;} //CC Exception

Saving::Saving(){
    MonthlyFee = 0;
    Deposit = 0;
}
void Saving::setMonthlyFee(int mf){MonthlyFee = mf;}
void Saving::setDeposit(double d1){Deposit = d1;}

Checking::Checking(){
    deposit = 0;
    withdraw = 0;
}
void Checking::setdeposit(double d2){deposit = d2;}
void Checking::setwithdraw(double w){withdraw = w;}

