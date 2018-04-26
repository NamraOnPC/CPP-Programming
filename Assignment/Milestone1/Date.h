//Name :- Namra Fanse
//Student ID :- 112219175
//Email ID :- nrfanse@myseneca.ca
//Date :- 9/3/2018
//Milestone 1 


#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>
using namespace std;


namespace AMA {

    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int DAY_ERROR = 4;
    const int min_year = 2000;
    const int max_year = 2030;

class Date {

  private:  
    
    int year_;
    int month_;
    int day_;
    int comparator_;
    int errorCode_;

    int mdays(int month, int year) const;
    int errCode(int errorCode);
    bool dateIsValid()const;
    bool yearValidator(const int Year);
	bool monthValidator(const int Month);
	bool dayValidator(int Month, int Year,  int Day);
	void Setter(const int Year,const int Month,const int Day, const int Error);
	void Checker(const int Year, const int Month, const int Day);

  public:

    Date();
    Date(const int year,const int month,const int day);


    bool operator==(const Date& rhs) const;
    bool operator!=(const Date& rhs) const;
    bool operator<(const Date& rhs) const;
    bool operator>(const Date& rhs) const;
    bool operator<=(const Date& rhs) const;
    bool operator>=(const Date& rhs) const;


    int errCode() const;
    bool bad() const;
    void dataValidator();
    bool checkDays();
    void errCodeAssign(int errorCode);
    
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr) const;
    
};

    std::istream& operator>>(std::istream& istr, Date& D);
    std::ostream& operator<<(std::ostream& ostr, const Date& D);
 
}

#endif
