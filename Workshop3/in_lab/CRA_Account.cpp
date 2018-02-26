// Name :- Namra Fanse
// Student Number :- 112219175
// Email :- nrfanse@myseneca.ca
// Workshop 3 in_lab
// Date :- 6/2/2018

#include <iostream>
#include "CRA_Account.h"
#include <cstring>

namespace sict {
using namespace std;

void CRA_Account::set(const char* familyName, const char* givenName, int SIN){

if( SIN >= min_sin && SIN <= max_sin ){

strncpy(familyName_,familyName,max_name_length);
strncpy(givenName_,givenName,max_name_length);
SIN_ = SIN;





}else{
	familyName_[0] = '\0';
	givenName_[0] = '\0';
	SIN_ = 0;


}
}





bool CRA_Account::isEmpty() const{

bool examine = false;

	if(SIN_ == 0 ){
		examine = true;
	}
	return examine;
}

void CRA_Account::display() const{


        if(SIN_ != 0)
	{
	        cout << "Family Name: " << familyName_ << endl;
		cout << "Given Name : " << givenName_ << endl;
		cout << "CRA Account: " << SIN_ << endl;
	}else{
	        cout << "Account object is empty!" << endl;
	}

	
}
}

