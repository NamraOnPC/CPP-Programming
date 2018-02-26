// Name :- Namra Fanse
// Student Number :- 112219175
// Email :- nrfanse@myseneca.ca
// Workshop 3 in_lab
// Date :- 6/2/2018






#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H

namespace sict{

const int max_name_length = 40;
const int min_sin = 100000000;
const int max_sin = 999999999;


class CRA_Account{

private:
	char familyName_[max_name_length];
	char givenName_[max_name_length];

	int SIN_;
	
public:
       void set(const char* familyName, const char* givenName, int SIN);
       bool isEmpty() const;
       void display() const;



};
}

#endif	






















