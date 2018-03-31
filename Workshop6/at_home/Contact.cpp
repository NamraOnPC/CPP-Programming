#include <iostream>
#include <cstring>
#include "Contact.h"
#include <iomanip>
using namespace std;

namespace sict{
    
    Contact::Contact(){
        name_[0] = '\0';
        pPhoneNumbers = nullptr;
        noOfPhoneNumbers_ = 0;
    }
    
    Contact::Contact(const char *name , const long long *phoneNumbers, const int noOfPhoneNumbers){
    if(isEmpty() == false){
        
        strncpy(name_ , name , 19);
        noOfPhoneNumbers_ = noOfPhoneNumbers;
	
        if(noOfPhoneNumbers_ > 0){
            long long *foo = new long long[noOfPhoneNumbers_];
            for(int i = 0; i < noOfPhoneNumbers_; i++){
                foo[i] = phoneNumbers[i];
            }
            pPhoneNumbers = foo;
            }else{
                pPhoneNumbers = nullptr;
            }
    }else{
        for(int i = 0; i < 21; i++){
            name_[i] = '\0';
        }
        pPhoneNumbers = nullptr;
        noOfPhoneNumbers_ = 0;
    }
    }
   
    Contact::Contact(const Contact &Obj){
       if(isEmpty() == false){
        
        strncpy(name_ , Obj.name_ , 19);
        noOfPhoneNumbers_ = Obj.noOfPhoneNumbers_;
	
        if(noOfPhoneNumbers_ > 0){
            long long *foo = new long long[noOfPhoneNumbers_];
            for(int i = 0; i < noOfPhoneNumbers_; i++){
                foo[i] = Obj.pPhoneNumbers[i];
            }
            pPhoneNumbers = foo;
            }else{
                pPhoneNumbers = nullptr;
            }
    }else{
        for(int i = 0; i < 21; i++){
            name_[i] = '\0';
        }
        pPhoneNumbers = nullptr;
        noOfPhoneNumbers_ = 0;
    }
    }

    bool Contact::isEmpty() const{
       return name_[0] == '\0';
    }
    
    void Contact::display() const{
        
        if(isEmpty() == true){
            cout << "Empty Contact!" << endl;
        }else{
            cout << name_ << endl;
            for (int i = 0; i < noOfPhoneNumbers_; i++) {
            if (10000000000 <= pPhoneNumbers[i] &&
            pPhoneNumbers[i] <= 999999999999) {
            cout<< "(+" << pPhoneNumbers[i] / 10000000000 << ") " << pPhoneNumbers[i] % 10000000000 / 10000000 << " " << pPhoneNumbers[i] % 10000000 / 10000 << "-" << std::setw(4) << std::setfill('0') << pPhoneNumbers[i]%10000 << endl;
            }
            
        }
    }
    }
    
    Contact& Contact::operator=(const Contact& Obj){
        if(this != &Obj){
            if(pPhoneNumbers != nullptr){
                delete[] pPhoneNumbers;
                pPhoneNumbers = nullptr;
            }
        
        noOfPhoneNumbers_ = Obj.noOfPhoneNumbers_;    
        strncpy(name_,Obj.name_,19);
        delete[] pPhoneNumbers;
        
        pPhoneNumbers = new long long[noOfPhoneNumbers_ = Obj.noOfPhoneNumbers_];
        for(int i = 0; i < noOfPhoneNumbers_; i++){
            pPhoneNumbers[i] = Obj.pPhoneNumbers[i];
        }
        }
        return *this;
    }
    
    Contact& Contact::operator+=(long long newPhoneNumber){
            long long* foo;
            
            foo = new long long[noOfPhoneNumbers_+1];
            
            for(int i = 0; i < noOfPhoneNumbers_; i++){
                foo[i] = pPhoneNumbers[i];
            }
            noOfPhoneNumbers_++;
        
        
        if(pPhoneNumbers != nullptr){
            delete[] pPhoneNumbers;
        }
        
        pPhoneNumbers = new long long[noOfPhoneNumbers_];
        for(int a = 0; a < noOfPhoneNumbers_; a++){
            pPhoneNumbers[a] = foo[a];
        } 
        pPhoneNumbers[noOfPhoneNumbers_ - 1] = newPhoneNumber;
        
        delete[] foo;
        
        return *this;
    }
    
    Contact::~Contact(){
         delete[] pPhoneNumbers;
    }
        
}
