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
    
//This constructor creates safe empty object by using Setter function in order to use it.

    Product::Product(){
        
        Setter("", "", "");
    
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
        
        file << productSku_ << ",";
        
        file << productUnit_ << ",";
        
        file << productQuantityOnHand_ << ",";
        
        file << taxable_ << ",";
        
        file << priceBeforeTax_ << ",";
        
        file << productQuantityRequired_ << ",";
        
        file << nameOfProduct_ << ",";
        
        if(newLine == true){
            
            file << '\n';
            
        }
   
        return file;
    }

//recieves reference to an fstream object.extracts the data from the object and stores in a temporary created object and then return areference to the fstream object 
    
    
    std::fstream & Product::load(std::fstream & file){
        
        Product object; 

		file.getline(object.productSku_, max_sku_length, ',');
		
		file.getline(object.productUnit_, max_unit_length, ',');
		
		file.ignore(1);
		
		file >> object.productQuantityRequired_;
		
		file.ignore(1);
		
		file >> object.taxable_;
		
		file.ignore(1);
		
		file >> object.priceBeforeTax_;
		
		file.ignore(1);
		
		file >> object.productQuantityRequired_;
		
		file.getline(object.nameOfProduct_, max_name_length, ',');

		*this = object;

		return file;
    }
    
//recieves reference to an ostream object and a boolean. It inserts the data and returns the reference to an ostream object.

    std::ostream & Product::write(std::ostream & os, bool linear) const{
        
        if(linear){
            
            os << setw(max_sku_length) << left << productSku_ << "|";
               
            os << setw(20) << left << nameOfProduct_ << "|";
               
            os << setw(7)  << right << setprecision(2) << fixed << cost() << "|";
               
            os << setw(4) << right << productQuantityOnHand_ << "|";
               
            os << setw(10) << left << productUnit_ << "|";
               
            os << setw(4)  << right << productQuantityRequired_ << "|";

        }else{
            
            os << "Sku: " << productSku_ << endl;
			
			os << "Name: " << nameOfProduct_ << endl;
			
			os << "Price: " << priceBeforeTax_ << endl;
			
			if (taxable_) {
				
				os << "Price after tax: " << cost() << endl;
			
			}
			else {
			
				os << "N/A" << endl;
			
			}
			
			os << "Quantity on hand: " << productQuantityOnHand_ << endl;
			
			os << "Quantity needed: " << productQuantityRequired_ << endl;

        }
        
        return os;
        
    }

//recieves a reference of an istream object extracts the data and returns the reference to an istream object.
    
    std::istream & Product::read(std::istream & is){
        
        Product object;
        
        char objSku[max_sku_length + 1];
        
        char objName[max_name_length + 1];
        
        char objUnit[max_unit_length + 1];
        
        char objTaxed;
        
        double objPrice;
        
        int objQuantityHave;
        
        int ObjQuantityNeeded;
        
        bool IsTaxed;
        
        ErrorState error;
        
        while(!is.fail()){
        
            cout << " Sku: ";
            cin.getline(objSku,max_sku_length);
        
            cout << " Name (no spaces): ";
            cin.getline(objName,max_name_length);
        
            cout << " Unit: ";
            cin.getline(objUnit,max_unit_length);
            
            cout << " Taxed? (y/n): ";
            is >> objTaxed;
        
        if(objTaxed == 'y' || objTaxed == 'Y'){
        
            IsTaxed = true;
            
            is.clear();
    
        }else{
                
                if(objTaxed == 'N' || objTaxed == 'n'){
                    
                    IsTaxed = false;
                    
                    is.clear();
                    
                }else{
                    
                    error.message("Only (Y)es or (N)o are acceptable");
                    
                    is.setstate(ios::failbit);
                    
                    break;
                    
                }
            
        }
        
        cout << " Price: ";
       
        if(is >> objPrice){
            
            is.clear();
            
        }else{
            
            error.message("Invalid Price Entry");
            
            break;
            
        }
        
        cout << " Quantity on hand: ";
        
        if(is >> objQuantityHave){
            
            is.clear();
            
        }else{
            
            error.message("Invalid Quantity Entry");
            
            break;
            
        }
        
        
        cout << " Quantity needed: ";
        
        if(is >> ObjQuantityNeeded){
            
            is.clear();
            
        }else{
            
            error.message("Invalid Quantity Needed Entry");
            
            break;
            
        }
       
       is.clear();
     
       cin.ignore(numeric_limits<streamsize>::max(), '\n');

       break;
    }
     
    if(error.isClear()){
        
        strcpy(object.productSku_, objSku);
        
        object.name(objName);
        
        strcpy(object.productUnit_, objUnit);
        
        object.taxable_ = IsTaxed;
        
        object.priceBeforeTax_ = objPrice;
        
        object.productQuantityOnHand_ = objQuantityHave;
        
        object.productQuantityRequired_ = ObjQuantityNeeded;
        
        object.error_.message(error.message());
        
        *this = object;
    }
    
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

//recieves an unmodifiable address of a string that holds sku. returns true if the sku of the current object is greater than the string of the recieved.     
    
    
    bool Product::operator>(const char* productSku) const{
     
        return strcmp(productSku_, productSku) > 0;
        
    }

//recieves an unmodifiable reference to a product object and returns true if the name of the current object is greater than the name of referenced object.    
    
    bool Product::operator>(const Product& object) const{
        
        return strcmp(nameOfProduct_, object.name()) > 0;
        
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
    
    std::ostream& operator<<(std::ostream& ostr, Product& object){
        
        return ostr;
        
    }

// receieves a reference to an istream object and  referene to a product object and return a reference to the istream object.
    
    std::istream& operator>>(std::istream& istr, Product& object){
        
        return istr;
        
    }

//recieves reference to a double and an unmodifiable reference to a Product object. returns a double.    
    
    double operator+=(double& total, const Product& object){
        
        return (total + object.total_cost());
        
    }
    
    
    
    
}
