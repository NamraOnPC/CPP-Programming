// Name :- Namra Fanse 
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 30/3/2018
// Workshop 8 at_home


#include <iostream>
#include "Account.h"
using namespace std;

namespace sict{
    
    Account::Account(double balance){
        
        if(balance > 0){
            
            balance_ = balance;
        
        }else{
            
            balance_ = 0.0;
        
        }
        
    }
    
    bool Account::credit(double amountToAdd){
        
        if(amountToAdd > 0){
            
            balance_ += amountToAdd;
            
            return true;
        
        }else{
            
            return false;
        
        }

    }
    
    bool Account::debit(double amountToSubtract){
        
        if(amountToSubtract > 0){
            
            balance_ -= amountToSubtract;
            
            return true;
        
        }else{
            
            return false;
    
        }
    
    }
    
    double Account::balance() const{
        
        return balance_;
    
    }

}