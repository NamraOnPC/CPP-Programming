#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

#include <iostream>
using namespace std;

namespace sict{
	
class Contact{
    
    private:
    
    char name_[20+1];
    long long  *pPhoneNumbers;
    int noOfPhoneNumbers_;
    bool phoneNumberIsValid(const long long phoneNumber);
    
    public:
    
    Contact();
    Contact(const char *name ,const long long *phoneNumbers,const int noOfPhoneNumbers);
    Contact(const Contact &obj); 
    ~Contact();
    
    bool isEmpty() const;
    void display() const;
    
    Contact& operator=(const Contact& Obj);
    Contact& operator+=(long long newPhoneNumber);
};
    

}

#endif
