// Name :- Namra Fanse 
// Student No :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Date :- 4/4/2018
// Milestone 3 





#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <limits>
#include "Product.h"
using namespace std;
using namespace AMA;

namespace AMA {
   
    Product::Product(char type){
        
        productType_ = type;
        
        productSku_[0] = '\0';
        
        productUnit_[0] = '\0';
        
        nameOfProduct_ = nullptr;
        
        productQuantityOnHand_ = 0;
        
        productQuantityRequired_ = 0;
        
        priceBeforeTax_ = 0.0;
        
        taxable_ = false;
    }
   
   
   
   
//This function recieves the address of the string which holds the name of the product. Checks and allocates, stores and deallocates accordingly. 

    void Product::name(const char* address){
    
       if( ! (this->nameOfProduct_ == nullptr)){
           
           delete[] nameOfProduct_;
           
       }
       
       if( address == nullptr){
           
           nameOfProduct_ =  new char[1];
           
           strcpy(nameOfProduct_,"");
           
       }else{
           
           nameOfProduct_ = new char[strlen(address) + 1];
           
           strcpy(nameOfProduct_, address);
           
       }
       
    }   
    
//This function returns the address of the string that holds the name of the product.

    const char * Product::name() const{
        
       return nameOfProduct_;
        
    }

//This function returns the address of the string that holds the sku of the product.
    
    const char* Product::sku() const{
        
        return productSku_;
        
    }

//This function returns the address of the string that holds the unit of the product.    
    
    const char* Product::unit() const{
        
        return productUnit_;
        
    }
    
//This function return whether the item is taxable or not (true/false).

    bool Product::taxed() const{
        
        return taxable_;
        
    }
    
//This function returns the price of the item.
    
    double Product::price() const{
        
        return priceBeforeTax_;
        
    }

//This function returns the price of the item with tax if that item is taxed.
    
    double Product::cost() const{
        
        double result;
        
        if(this->taxable_){
        
            result = priceBeforeTax_ + (priceBeforeTax_ * TAX_RATE);
            
        }else{
            
            result = priceBeforeTax_; 
            
        }
        
        return result;
        
    }
    
//This function recieves address to the string holding an error message and stores that message in errorState object.

    void Product::message(const char * address){
        
        error_.message (address);
    
    }

//This function returns true if error state objecr is clear or it returns false.    
    
    bool Product::isClear() const{
        
       return error_.isClear();
       
    } 

//This constructor uses Setter function to set the recieved values inside the object.
    
    Product::Product(const char* productSku,const char* nameOfProduct,const char* productUnit, int productQuantityOnHand, bool taxable, double priceBeforeTax, int productQuantityRequired){
    
        Setter(productSku,nameOfProduct,productUnit,productQuantityOnHand,taxable,priceBeforeTax,productQuantityRequired);
      
    }

//This function recieves values and data and sets it to the object.

    void Product::Setter(const char* productSku, const char* nameOfProduct,const char* productUnit, int productQuantityOnHand, bool taxable, double priceBeforeTax, int productQuantityRequired){
        
        nameOfProduct_ = nullptr;
        
        this->name(nameOfProduct);
        
        strcpy(productSku_ , productSku);
        
        strcpy(productUnit_ , productUnit);
        
        productQuantityOnHand_ = productQuantityOnHand;
        
        productQuantityRequired_ = productQuantityRequired;
        
        priceBeforeTax_ = priceBeforeTax;
        
        taxable_ = taxable;
          
        
    }
    
 
//This construtor recieves an unmodifiable reference to a product object and copies that object(its data) to the current object using the Setter function.

    Product::Product(const Product& object){
        
        Setter(object.productSku_,object.nameOfProduct_,object.productUnit_,object.productQuantityOnHand_,object.taxable_,object.priceBeforeTax_,object.productQuantityRequired_);
        
    }

//This operator

    
    Product & Product::operator=(const Product& object){
        
        Setter(object.productSku_,object.nameOfProduct_,object.productUnit_,object.productQuantityOnHand_,object.taxable_,object.priceBeforeTax_,object.productQuantityRequired_);
        
        return *this;
        
    }
  
//this  Destructor deaalocates the dynamic memory that has been allocated 

    Product::~Product(){
      
      if(nameOfProduct_ != nullptr){
          
          delete[] nameOfProduct_;
          
          nameOfProduct_ = nullptr;
          
      }
      
    }
    
//recieves a reference to an fstream object and and a bool.It manipulates with the fstream object and returns a reference to the fstream object.


    std::fstream & Product::store(std::fstream& file, bool newLine) const{
        
       // if(file.is_open()){
        
     file << productType_ << ',' << productSku_ << ',' << nameOfProduct_ << ',' << productUnit_ << ',' << taxable_ << ',' << priceBeforeTax_ << ','  << productQuantityOnHand_ << ',' << productQuantityRequired_;
	
       if(newLine){
            
           file << std::endl;
            
      }
   
   
        return file;
    }

//recieves reference to an fstream object.extracts the data from the object and stores in a temporary created object and then return areference to the fstream object 
    
    
    std::fstream & Product::load(std::fstream & file){
        
        char sku_[max_sku_length];
        
        char name_[max_name_length];
        
        char unit_[max_unit_length];
        
        double price;
        
        int quantity;
        
        int needed;
        
        char tax;
        
        bool taxable;
            
        if(file.is_open()){
            
            file.getline(sku_,max_sku_length, ',');
		    sku_[strlen(sku_)] = '\0';

		    
		    file.getline(name_, max_name_length, ',');
		    name_[strlen(name_)] = '\0';

			
			file.getline(unit_, max_unit_length, ',');
			unit_[strlen(unit_)] = '\0';

			
			file >> tax;

			if (tax == '1'){
				
				taxable = true;
				
			}else if (tax == '0'){
				
				taxable = false;

			}
			
			file.ignore();

			file >> price;
			file.ignore();

			
			file >> quantity;
			file.ignore();

			
			file >> needed;
			file.ignore();
			
			*this = Product(sku_, name_, unit_, quantity, taxable, price, needed);
		
        }

		return file;
    
    }
    
//recieves reference to an ostream object and a boolean. It inserts the data and returns the reference to an ostream object.

    std::ostream & Product::write(std::ostream & os, bool linear) const{
        
        if(!(error_.isClear())){
         
            os << error_.message();
            
        }else if(linear){
            
            os <<  setfill(' ') <<setw(max_sku_length) << left << productSku_ << "|";
               
            os << setw(20) << left << nameOfProduct_ << "|";
               
            os << setw(7)  << right << setprecision(2) << fixed << cost() << "|";
               
            os << setw(4) << right << productQuantityOnHand_ << "|";
               
            os << setw(10) << left << productUnit_ << "|";
               
            os << setw(4)  << right << productQuantityRequired_ << "|";

        }else{
            
            os << " Sku: " << productSku_ << endl;
			
			os << " Name (no spaces): " << nameOfProduct_ << endl;
			
			os << " Price: " << priceBeforeTax_ << endl;
			
			if (taxable_) {
				
				os << " Price after tax: " << cost() << endl;
			
			}
			else {
			
				os << " Price after tax:  N/A" << endl;
			
			}
			
			os << " Quantity on Hand: " << productQuantityOnHand_  << ' ' << productUnit_ << endl;
			
			os << " Quantity needed: " << productQuantityRequired_;
		   


        }
  
        return os;
        
    }

//recieves a reference of an istream object extracts the data and returns the reference to an istream object.
    
    std::istream & Product::read(std::istream & is){
        
        char taxed;
        
        char * address = new char[max_name_length + 1];
        
        int quantityHere;
        
        int neededHere;
        
        double priceHere;
        
        if(!is.fail()){
        
            cout << " Sku: ";
            is >> productSku_;
            cin.ignore();
        
            cout << " Name (no spaces): ";
            is >> address;
            name(address);
        
            cout << " Unit: ";
            is >> productUnit_;
            
            cout << " Taxed? (y/n): ";
            is >> taxed;
        
        if(!is.fail()){
            
            error_.clear();
                
            if(taxed){
        
                bool yesChecker = taxed == 'y' || taxed == 'Y';
                
                bool noChecker = taxed == 'n' || taxed == 'N';
            
                if(yesChecker){
                    
                    taxable_ = true;
                    
                }
                
                if(noChecker){
                    
                    taxable_ = false;
                    
                }
                
                if(!(yesChecker || noChecker)){
                    
                    is.setstate(std::ios::failbit);
                    
                    error_.message("Only (Y)es or (N)o are acceptable");
                    
                    return is;
                    
                }    
      
            }
            
        }else{
            
            is.setstate(std::ios::failbit);
                    
            error_.message("Only (Y)es or (N)o are acceptable");
                    
            return is;
            
        }
            
        
        cout << " Price: ";
        is >> priceHere;
       
        if(is.fail()){
            
            error_.clear();
            
            is.setstate(ios::failbit);
            
            error_.message("Invalid Price Entry");
            
            return is;
            
        }else{
            
            price(priceHere);
            
        }
        
        cout << " Quantity on hand: ";
        is >> quantityHere;
        
        if(is.fail()){
            
            error_.clear();
            
            error_.message("Invalid Quantity Entry");
            
            is.setstate(ios::failbit);
            
            return is;
            
        }else{
            
            quantity(quantityHere);
            
        }
        
        
        cout << " Quantity needed: ";
        is >> neededHere;
     //   cin.ignore();
        
        
        if(is.fail()){
            
            error_.clear();
            
            error_.message("Invalid Quantity Needed Entry");
            
            is.setstate(ios::failbit);
            
        }else{
            
            needed(neededHere);
            
        }
       
       if(!is.fail()){
           
           error_.clear();
           
       }

        }
        is.ignore();
//	is.ignore();
        return is;
  
    }
    
//receives the address of an unmodifiable string and returns true if the string is identical to the sku of the current object


    bool Product::operator==(const char * address) const{
        
        bool comparison;
        
        if(strcmp(productSku_, address) == 0){
            
            comparison = true;
        
        }else{
            
            comparison = false;
            
        }
        
        return comparison;
        
    }

//returns the total cost of all items of the product on hand with taxes included.
    
    double Product::total_cost() const{
    
        return (productQuantityOnHand_ *(this->cost()));

    }
    
//recieves integer holding units of the product on hand sets it to the objects integer.

    void Product::quantity(int productQuantityOnHand){
        
        productQuantityOnHand_ = productQuantityOnHand;
    
    }
    
//returns true if the object is in safe empty state 


    bool Product::isEmpty() const{
        
        if(strcmp(productSku_,"") == 0){
            
            return true;
            
        }else{
            
            return false;
            
        }
        
    }

//returns number of products required.

    
    int Product::qtyNeeded() const{
        
        return productQuantityRequired_;
        
    }

//returns number of products on hand.    
    
    int Product::quantity() const{
        
        return productQuantityOnHand_;
        
    }
    
    void Product::price(double price){
        
        priceBeforeTax_ = price;
        
    }

    void Product::needed(int needed){
        
        productQuantityRequired_ = needed;
        
    }
//recieves an unmodifiable address of a string that holds sku. returns true if the sku of the current object is greater than the string of the recieved.     
    
    
    bool Product::operator>(const char* productSku) const{
     
        return strcmp(productSku_, productSku) > 0;
        
    }

//recieves an unmodifiable reference to a product object and returns true if the name of the current object is greater than the name of referenced object.    
    
    bool Product::operator>(const iProduct& object) const{
        
       if(strcmp(nameOfProduct_, object.name()) > 0){
           
           return true;
           
       }else{
           
           return false;
           
       }
        
    }

//recieves an integer which are the number of units to be added to the product. computes and returns the updated number of units.
    
    int Product::operator+=(int unitsToBeAdded){
        
        if(unitsToBeAdded > 0){
            
            this->productQuantityOnHand_ += unitsToBeAdded;
            
            return this->productQuantityOnHand_;
            
        }else{
            
            return this->productQuantityOnHand_;
            
        }
        
        
    }

//receives a reference to an ostream object and a product object and returns a reference to the ostream object.    
    
    std::ostream& operator<<(std::ostream& os,const iProduct& object){
        
        return object.write(os,true);
        
    }

// receieves a reference to an istream object and  referene to a product object and return a reference to the istream object.
    
    std::istream& operator>>(std::istream& is,iProduct& object){
        
        return object.read(is);
        
    }

//recieves reference to a double and an unmodifiable reference to a Product object. returns a double.    
    
    double operator+=(double& total, const Product& object){
        
        return (total + object.total_cost());
        
    }
    
    
    
    
}
