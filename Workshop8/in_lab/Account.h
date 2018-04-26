// Name :- Namra Fanse 
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 27/3/2018
// Workshop 8 in_lab


#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account : public iAccount{
	    
        double balance_;

	protected:
    
        double balance() const;

	public:

        Account(double initialBalance);

        bool credit(double amountToAdd);

        bool debit(double amoutToSubtract);

	};

    iAccount* CreateAccount(const char* type, double initialBalance);

}
#endif
