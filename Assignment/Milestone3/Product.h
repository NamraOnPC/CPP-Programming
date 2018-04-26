// Name :- Namra Fanse 
// Student No :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Date :- 4/4/2018
// Milestone 3 





#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <iostream>
#include "ErrorState.h"
#include <fstream>

namespace AMA {
    
    const int MAX_SKU = 7;
    
    const int MAX_UNIT= 10;
    
    const int MAX_NAME= 75;
    
    const double TAX_RATE = 0.13;
    
    const int max_sku_length = MAX_SKU;
    
    const int max_name_length = MAX_NAME;
    
    const int max_unit_length = MAX_UNIT;
    
    class Product{
        
        private: 
        
            char productType_;
            
            char productSku_[MAX_SKU + 1];
            
            char productUnit_[MAX_UNIT + 1];
            
            char* nameOfProduct_;
            
            int productQuantityOnHand_;
            
            int productQuantityRequired_;
            
            double priceBeforeTax_;
            
            bool taxable_;
            
            ErrorState error_;
            
        protected:
        
            void name(const char* address);
            
            const char* name() const;
            
            const char* sku() const;
            
            const char* unit() const;
            
            bool taxed() const;
            
            double price() const;
            
            double cost() const;
            
            void message(const char*);
            
            bool isClear() const;
            
            void Setter(const char* productSku, const char* nameOfProduct,const char* productUnit, int productQuantityOnHand = 0, bool taxable = true, double priceBeforeTax = 0.0, int productQuantityRequired = 0);
        
        public:
        
            Product();
            
            Product(const char* productSku, const char* nameOfProduct,const char* productUnit, int productQuantityOnHand = 0, bool taxable = true, double priceBeforeTax = 0.0, int productQuantityRequired = 0);
            
            Product(const Product& object);
            
            Product& operator=(const Product& object);
            
            ~Product();
            
            std::fstream& store(std::fstream& file, bool newLine = true) const;
            
            std::fstream& load(std::fstream& file);
            
            std::ostream& write(std::ostream& os, bool linear) const;
            
            std::istream& read(std::istream& is);
            
            bool operator==(const char* address)const;
            
            double total_cost() const;
            
            void quantity(int productQuantityOnHand);
            
            bool isEmpty() const;
            
            int qtyNeeded() const;
            
            int quantity() const;
            
            bool operator>(const char* productSku) const;
            
            bool operator>(const Product& object) const;
            
            int operator+=(int unitsToBeAdded);
      
    };
    
        std::ostream& operator<<(std::ostream& ostr, Product& object);
        
        std::istream& operator>>(std::istream& istr, Product& object);
        
        double operator+=(double& total, const Product& object);
    
}

#endif
