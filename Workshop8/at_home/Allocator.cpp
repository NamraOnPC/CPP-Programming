// Name :- Namra Fanse 
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 30/3/2018
// Workshop 8 at_home


#include "SavingsAccount.h" 
#include "ChequingAccount.h"
#include <iostream>

namespace sict {

    const double interest = 0.05;
    
    const double transaction = 0.50;
    
    const double monthly = 2.00;

    iAccount* CreateAccount(const char* type, double initialBalance){
        
        iAccount* point = nullptr;
        
        if(type[0] == 'S'){
            
            point = new SavingsAccount(initialBalance,interest);
            
        }else if(type[0] == 'C'){
            
            point = new ChequingAccount(initialBalance,transaction,monthly);
        
        }
	
	    return point;
    
    }

}
