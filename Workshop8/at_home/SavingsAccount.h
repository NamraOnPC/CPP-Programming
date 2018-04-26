// Name :- Namra Fanse 
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 30/3/2018
// Workshop 8 at_home


#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {

        double interest_;
	
	public:
	
        SavingsAccount(double initialBalance, double interestRate);

        void monthEnd();
		
        void display(std::ostream& ostr) const;
        
	};
}
#endif