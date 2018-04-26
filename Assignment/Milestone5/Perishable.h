#ifndef AMA_PERISHABLE_H_
#define AMA_PERISHABLE_H_

#include <iostream>
#include "Date.h"
#include "Product.h"
#include "ErrorState.h"

using namespace std;
using namespace AMA;


namespace AMA {
    
    class Perishable : public Product {
        
        private:
            
            Date expiryDate_;
        
        public:
        
            Perishable();
            
            const Date& expiry() const;
        
            std::fstream& store(std::fstream& file, bool newLine=true) const;
        
            std::fstream& load(std::fstream& file);
        
            std::ostream& write(std::ostream& os, bool linear) const;
        
            std::istream& read(std::istream& is);
            
            void expiry(const Date &value);
            
    };
    
        iProduct* CreatePerishable();
    
}


#endif