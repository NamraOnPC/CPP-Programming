//Name :- Namra Fanse
//Student No :- 112219175
//Student Email :- nrfanse@myseneca.ca
//Milestone 5




#include <iostream>
#include <fstream>
#include "Perishable.h"
#include "Date.h"
using namespace std;
using namespace AMA;

namespace AMA {
    
    Perishable::Perishable() : Product('P'){
        
    }
    
    const Date& Perishable::expiry() const{
        
        return expiryDate_;
        
    }
    
    void Perishable::expiry(const Date &value){
        
        expiryDate_ = value;
        
    }
    
    std::fstream& Perishable::store(std::fstream& file, bool newLine)const{
        
        Product::store(file,false);
       
        file << "," << expiry() << endl;
           
//	if(newLine){
//	file << std::endl;
//	}
        return file;
        
    }
    
    std::fstream& Perishable::load(std::fstream& file){
        
      Product::load(file);
		expiryDate_.read(file);
		file.ignore();
		return file;
    }
    
    std::ostream& Perishable::write(std::ostream& os, bool linear) const{
        
        Product::write(os,linear);
        
        if(error_.isClear() && !Product::isEmpty()){
            
            if(linear){
                
                os << expiryDate_;
                
            }else{
                
               os << endl;
                
                os << " Expiry date: " << expiryDate_;
                
            }
            
        }
        
        return os;
        
    }
    
    std::istream& Perishable::read(std::istream& is){
        
        Date tmp_;
        
        error_.clear();
        
        Product::read(is);
        
        if (error_.isClear() && is)
        {
            cout << " Expiry date (YYYY/MM/DD): ";
            is >> tmp_;
            if (tmp_.errCode() == CIN_FAILED)
            {
                error_.message("Invalid Date Entry");
                is.setstate(ios::failbit);
            }
            else if (tmp_.errCode() == YEAR_ERROR)
            {
                error_.message("Invalid Year in Date Entry");
                is.setstate(ios::failbit);
            }
            else if (tmp_.errCode() == MON_ERROR)
            {
                error_.message("Invalid Month in Date Entry");
                is.setstate(ios::failbit);
            }
            else if (tmp_.errCode() == DAY_ERROR)
            {
                error_.message("Invalid Day in Date Entry");
                is.setstate(ios::failbit);
            }

        }
        if (error_.isClear())
        {
            expiry(tmp_);
        }
        return is;
    }
    
    
    
    
    
}
