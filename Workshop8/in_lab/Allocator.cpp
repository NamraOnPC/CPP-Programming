// Name :- Namra Fanse 
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 27/3/2018
// Workshop 8 in_lab


#include "SavingsAccount.h" 

namespace sict {

    const double interest = 0.05;

    iAccount* CreateAccount(const char* type, double initialBalance){
        
        iAccount* point = nullptr;
        
        if(type[0] == 'S'){
            
            point = new SavingsAccount(initialBalance,interest);
            
            return point;
        }
	return 0;
    }

}
