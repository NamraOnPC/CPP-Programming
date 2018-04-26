// Name :- Namra Fanse 
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 30/3/2018
// Workshop 8 at_home


#ifndef SICT_CHEQUINGACCOUNT_H_
#define SICT_CHEQUINGACCOUNT_H_
#include "Account.h"

namespace sict {
    
    class ChequingAccount : public Account {
        
        double transaction_;
        double monthEndFee_;
        
        public:
        
            ChequingAccount(double initialBalance, double transaction, double monthEndFee);
            
            bool credit(double amountToCredit);
            
            bool debit(double amountToDebit);
            
            void monthEnd();
            
            void display(std::ostream& ostr) const;
    };
    
}

#endif