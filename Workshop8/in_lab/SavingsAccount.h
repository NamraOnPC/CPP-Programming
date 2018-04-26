// Name :- Namra Fanse 
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 27/3/2018
// Workshop 8 in_lab


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
