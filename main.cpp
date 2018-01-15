//
//  main.cpp
//  Assigment 1
//
//  Created by Addiel Almonte on 9/26/17.
//  Copyright © 2017 Addiel Almonte. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include "Account.hpp"

int main(int argc, const char * argv[]) {
    using std::toupper;
    
    std::string option;
    std::cout<<"Welcome to your main menu. Please input *Account* for Account information, *Savings* for Savings information, *Checking* for checking information or *Credit* for Credit Card information"<<std::endl;
    std::cin>>option;
    if (option == "Account" or option == "account") {
        
    std::string name;
    long int AccountN;
    int Balance;
    
    std::cout<<"Please input the name of the account ";
    std::cin>>name;
    srand(time(NULL));
    AccountN = rand() % 199999999 + 1000000000;
    Balance = rand() % 500;
    Account myAccount1;
    
    myAccount1.setAccountName(name);
    myAccount1.setAccountNumber(AccountN);
    myAccount1.setAccountBalance(Balance);
    
    std::cout<<"Account Name: "<<myAccount1.getAccountName()<<" ** "<<"Account number: "<<myAccount1.getNumber()<<" ** "<<"Current Account Balance: "<<myAccount1.getAccountBalance()<<std::endl;
    }
//
    else if (option == "Savings" or option == "savings"){
        
    int mf;
    double d1;
    
    std::cout<<"*Note* All savings account start with $199 USD "<<std::endl;
    std::cout<<"Please input the amount deposited into the account ";
    std::cin>>d1;
    srand(time(NULL));
    mf = rand() % 15 + 1;
    d1 = d1 + 199;
    
    Saving mySaving1;
    
    mySaving1.setMonthlyFee(mf);
    mySaving1.setDeposit(d1);
    
    std::cout<<"Account's total present value: "<<mySaving1.getDeposit()<<" ** "<<"Your current montly fee: "<<mySaving1.getMonthlyFee()<<std::endl;
    }
//
    else if (option =="Checking" or option=="checking"){
        
    double d2,d3,w;
    std::cout<<"*Note* Every checking account has received a $525 USD bonus! "<<std::endl;
    std::cout<<"Please input the amount you wish to deposit to your checking Account ";
    std::cin>>d2;
    std::cout<<"Please input another amount you wish to deposit ";
    std::cin>>d3;
    std::cout<<"PLease input the amount you wish to withdraw from your checking account ";
    std::cin>>w;
    d2 = d2 + d3 + 525;
    w= d2 - w;
    
    Checking mychecking1;
    
    mychecking1.setdeposit(d2);
    mychecking1.setwithdraw(w);
    
    std::cout<<"Present account balance: "<<mychecking1.getwithdraw()<<std::endl;
    }
//
    else if (option=="Credit" or option == "credit"){
    int l,ccn;
    double ch;
        
    srand(time(NULL));
    l = rand() % 10000 + 500;
    ccn = rand() % 1999999 + 1000000;
    std::cout<<"Your approved credit line is: "<<l<<std::endl;
    std::cout<<"Input the charge value needed to be processed ";
    std::cin>>ch;
    l = l - ch;
    CreditCard mycreditcard1;
    
    mycreditcard1.setlimit(l);
    mycreditcard1.setcharge(ch);
        mycreditcard1.setCreditCardNumber(ccn);
    
//CreditCard Exception
    
    std::string Error = "Unable to be proccesed! Excides Credit Line...";
    std::string Answer;
    
    try {
        if (l <= -1)
            throw CreditCardExept(Error);
    } catch (CreditCardExept& me) {
        std::cout<<"Unable to be proccessed! Excides Credit Line..."<<std::endl;
    }
    
    if (l >= -1) {
        std::cout<<"Available Credit limit: "<<mycreditcard1.getLimit()<<" ** "<<"Charge due: "<<mycreditcard1.getCharge()<<" ** "<<"Your Credit Card Number is : "<<mycreditcard1.getCreditCardNumber()<<std::endl;
    } else{
        std::cout<<"Credit Line Excited.."<<std::endl;
    }
        
    std::cout<<"Would you like to make a payment to your credit card? Pleaee input *Yes* or *No*"<<std::endl;
    std::cin>>Answer;
        if (Answer=="Yes" or Answer== "yes"){
            
            int payment,rem;
            std::cout<<"Please input the payment amount you wish to process "<<std::endl;
            std::cin>>payment;
            rem = ch - payment;
            // Question 3b - Payment exides charge
            try {
                if (payment > ch)
                    throw CreditCardExept(Error);
            } catch (CreditCardExept& me) {
                std::cout<<"Unable to process payment. Your attempted payment excided balance due. "<<std::endl;
            }
        //Question 3c - Negative payment
        try{
            if (payment <= -1)
                throw CreditCardExept(Error);
        } catch (CreditCardExept& me){
            
            std::cout<<"You have entered a negative value as your payment account... PAYMENT DENIED!"<<std::endl;
        }
            if (rem > 0 & rem < ch ) {
                std::cout<<"Remaining charge: "<<rem<<std::endl;
            }
        }
        
        else if (Answer == "No" or Answer == "no"){
            int randay;
            randay = rand() % 30 + 1;
            
            std::cout<<"Thank You for using our Customer Portal..."<<std::endl;
            std::cout<<"Friendly Reminder. Your payment is due in "<<randay<<" days"<<std::endl;
            
        }
    
    }
    return 0;
}
