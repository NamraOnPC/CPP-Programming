// Name :- Namra Fanse
// Student Number :- 112219175
// Email :- nrfanse@myseneca.ca
// Workshop 3 at_home
// Date :- 9/2/2018

#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H

namespace sict{

const int max_name_length = 40;
const int min_sin = 100000000;
const int max_sin = 999999999;
const int max_yrs = 4;

class CRA_Account{

private:
	char familyName_[max_name_length + 1];
	char givenName_[max_name_length + 1];

	int SIN_;
	int taxReturns_[max_yrs];
	double balanceOwed_[max_yrs];
	int noOfYears_;
	
public:
       void set(const char* familyName, const char* givenName, int SIN);
       bool isEmpty() const;
       void display() const;
     void set(int year, double balance);
       bool isValid(int);



};
}

#endif	
