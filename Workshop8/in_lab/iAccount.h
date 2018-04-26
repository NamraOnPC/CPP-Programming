// Name :- Namra Fanse 
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 27/3/2018
// Workshop 8 in_lab


#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__

#include <iostream>

namespace sict {

	class iAccount {

	public:
	
	  virtual bool credit(double) = 0;

  	  virtual bool debit(double) = 0;
    
  	  virtual void monthEnd() = 0;

	 virtual void display(std::ostream&) const = 0;

	};

	iAccount* CreateAccount(const char* type , double initialBalance);

}
#endif
