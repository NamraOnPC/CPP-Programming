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
    
	    name_[0] = '\0';
	    pPhoneNumbers = nullptr;
	    noOfPhoneNumbers_ = 0;

	if(name != '\0' && strcmp(name,"") != 0){
    strncpy(name_ , name , 19);
    name_[20] = '\0';
    noOfPhoneNumbers_ = noOfPhoneNumbers;
	}
        if(phoneNumbers){
            pPhoneNumbers = new long long[noOfPhoneNumbers_];
            for(int i = 0; i < noOfPhoneNumbers_; i++){
                pPhoneNumbers[i] = phoneNumbers[i];
            }
        }
        
    }
    
    bool Contact::isEmpty() const{
        return name_[0] == '\0' || strcmp(name_, "") == 0;
    }
    
    void Contact::display() const{
        
        if(isEmpty()){
            cout << "Empty contact!" << endl;
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
    
    Contact::~Contact(){
         delete[] pPhoneNumbers;
    }
        
}
