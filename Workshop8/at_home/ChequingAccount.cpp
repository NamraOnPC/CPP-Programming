// Name :- Namra Fanse 
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 30/3/2018
// Workshop 8 at_home



#include <iostream>
#include "ChequingAccount.h"
#include <iomanip>

using namespace std;

namespace sict {
    
    ChequingAccount::ChequingAccount(double initialBalance, double transaction, double monthEndFee) : Account(initialBalance){
        if(transaction > 0){
            
            transaction_ = transaction;
        
        }else{
        
            transaction_ = 0.0;
        
        }
        
        if(monthEndFee > 0){
        
            monthEndFee_ = monthEndFee;
        
        }else{
            
            monthEndFee_ = 0.0;
        
        }
    }
    
    bool ChequingAccount::credit(double amountToCredit){
        
        Account::debit(transaction_);
        
        return Account::credit(amountToCredit);

    }
    
    bool ChequingAccount::debit(double amountToDebit){
        
        return Account::debit(amountToDebit + transaction_);
        
    }
    
    
    void ChequingAccount::monthEnd(){
        
        Account::debit(monthEndFee_ + transaction_);
        
    }
    
    void ChequingAccount::display(std::ostream& ostr) const{
        
        ostr.setf(std::ios::fixed);
        
        ostr << std::setprecision(2);
        
        ostr << "Account type: Chequing" << std::endl;
        
        ostr << "Balance: $" << this->balance() << std::endl;
        
        ostr << "Per Transaction Fee: " << transaction_ <<  std::endl;
        
        ostr << "Monthly Fee: " << monthEndFee_ << std::endl;
        
        ostr.unsetf(std::ios::fixed);
        
    }
}