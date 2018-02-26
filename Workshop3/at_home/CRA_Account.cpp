// Name :- Namra Fanse
// Student Number :- 112219175
// Email :- nrfanse@myseneca.ca
// Workshop 3 at_home 
// Date :- 9/2/2018

#include <iostream>
#include "CRA_Account.h"
#include <cstring>
#include <cmath>

namespace sict {
using namespace std;

void CRA_Account::set(int year, double balance){
if ( !isEmpty() && noOfYears_ < max_yrs){
    taxReturns_[noOfYears_] = year;
    balanceOwed_[noOfYears_] = balance;
    noOfYears_++;
 }  
}

void CRA_Account::set(const char* familyName, const char* givenName, int SIN){

if('\0'!= familyName && '\0' != givenName && isValid(SIN)){

strncpy(familyName_,familyName,max_name_length);
strncpy(givenName_,givenName,max_name_length);
SIN_ = SIN;
noOfYears_ = 0;

}else{
	familyName_[0] = '\0';
	givenName_[0] = '\0';
	SIN_ = 0;
}
}

bool CRA_Account::isEmpty() const{

bool examine = false;

	if(SIN_ == 0 || SIN_ <= min_sin || SIN_ >= max_sin || '\0' == familyName_[0] || '\0' == givenName_[0]){
		examine = true;
	}
	return examine;
}

bool CRA_Account::isValid(int SIN){
    int sum = 0;
    int evenNumberInSeries[4] = { 
    ((( SIN / 10 ) % 10 ) * 2 ),
    ((( SIN / 1000 ) % 10 ) * 2 ),
    ((( SIN / 100000 ) % 10 ) * 2 ),
    ((( SIN / 10000000 ) % 10 ) * 2 )   
    };
    int oddNumberInSeries[4] = {
    ((( SIN / 100 ) % 10 )),
    ((( SIN / 10000 ) % 10 )),
    ((( SIN / 1000000 ) % 10 )),
    ((( SIN / 100000000 ) % 10 ))
    };
    
    for ( int x = 0; x < 4; x++){
        sum += (((evenNumberInSeries[x] / 1) % 10) + ((evenNumberInSeries[x] / 10) % 10));
        sum += oddNumberInSeries[x];
    }
    int checkingInteger = ((sum + 9) / 10) * 10;
    
    if(((checkingInteger - sum) == (SIN / 1) % 10)  && SIN >= min_sin && SIN <= max_sin){
        return true;
    }else{
        return false;
    }

}

void CRA_Account::display() const{

if(0 != SIN_ || '\0' != givenName_ || '\0' != familyName_){
    cout << "Family Name: " << familyName_ << endl;
    cout << "Given Name : " << givenName_ << endl;
    cout << "CRA Account: " << SIN_ << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    
    for(int i=0; i < max_yrs; i++){
            cout << "Year (" << taxReturns_[i] << ") ";
            if(balanceOwed_[i] > 2.00 ){
                cout << "balance owing: " << balanceOwed_[i] << endl;
            }else if(balanceOwed_[i] < -2.00){
                cout << "refund due: " << -balanceOwed_[i] << endl;
            }else{
                cout << "No balance owing or refund due!" << endl;
            }
       
    }
    std::cout.unsetf(std::ios::fixed);
    std::cout.precision(6);
    
}else{
    cout << "Account object is empty!" << endl << endl;
}

}
}

