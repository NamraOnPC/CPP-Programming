// Name :- Namra Fanse 
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 30/3/2018
// Workshop 8 at_home


#include <iostream>
#include "SavingsAccount.h"
#include <iomanip>

namespace sict {
    
    SavingsAccount::SavingsAccount(double initialBalance, double interestRate) : Account(initialBalance){
        
        if(interestRate > 0 ){
        
            interest_ = interestRate;
        
        }else{
        
            interest_ = 0.0;
        
        }
    }
    
    void SavingsAccount::monthEnd(){
        
        double interestEarned;
        
        interestEarned = (balance() * interest_);
        
        credit(interestEarned);
    }
    
    void SavingsAccount::display(std::ostream& ostr) const{
        
        ostr.setf(std::ios::fixed);
        
        ostr << std::setprecision(2);
        
        ostr << "Account type: Savings" << std::endl;
        
        ostr << "Balance: $" << this->balance() << std::endl;
        
        ostr << "Interest Rate (%): " << ( interest_ * 100 ) << std::endl;
    }
    
}
