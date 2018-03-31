#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

#include <iostream>
using namespace std;

namespace sict{
	
class Contact{
    
  //  const int areaCodeLen = 3;
  //  const int phoneNumberLen = 7;
   // const int onePartOfNo = 3;
 //   const int secondPartOfNo = 4;
    
    
    private:
    
    char name_[20+1];
    long long  *pPhoneNumbers;
    int noOfPhoneNumbers_;
    bool phoneNumberIsValid(const long long phoneNumber);
    
    public:
    
    Contact();
    Contact(const char *name ,const long long *phoneNumbers,const int noOfPhoneNumbers);
    ~Contact();
    
    bool isEmpty() const;
    void display() const;
    
};
    

}

#endif
