//Name :- Namra Fanse
//Student ID :- 112219175
//Email ID :- nrfanse@myseneca.ca
//Date :- 9/3/2018
//Milestone 1 

#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

namespace AMA {

Date::Date(){
    year_ = 0;
    month_ = 0;
    day_ = 0;
    comparator_ = 0;
    errorCode_ = NO_ERROR;
}

Date::Date(const int year, const int month, const int day ){
   
   if((year >= min_year) &&  (year <= max_year) && (month < 13) && (month > 0) &&  mdays(month,year)){
    year_ = year;
    month_ = month;
    day_ = day;
    errorCode_ = NO_ERROR;
    comparator_ = (year * 372) + (month * 13) + day;
   }else{
        year_ = 0;
        month_ = 0;
        day_ = 0;
        comparator_ = 0;
        errorCode_ = NO_ERROR;
   }
}

void Date::dataValidator(){
    if(year_ < min_year || year_ > max_year){
        errorCode_ = YEAR_ERROR;
    }else if(month_ < 1 || month_ > 12){
        errorCode_ = MON_ERROR;
    }else if(day_ < 1 || day_ > mdays(month_,year_)){
        errorCode_ = DAY_ERROR;
    }else{
        errCodeAssign(NO_ERROR);
    }
}

bool Date::yearValidator(const int Year){
    return ((Year <= max_year) && (Year >= min_year));
}

bool Date::monthValidator(const int Month){
    return ((Month >= 1) && (Month <= 12));
}

bool Date::dayValidator(int Year,int Month,int Day){
 int checkDay = this->mdays(Month,Year);
    return (Day >= 1 && Day <= checkDay );
}

int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

void Date::errCodeAssign(int errorCode){
    errorCode_ = errorCode;
}

int Date::errCode()const{
    return errorCode_;
}

bool Date::bad()const{
    return errorCode_ != 0;
}

bool Date::dateIsValid()const{
    return (this->errorCode_ == NO_ERROR);
}

bool Date::operator==(const Date& rhs)const{
    if((this->dateIsValid() == false ) || (rhs.dateIsValid() == false)){
        return false;
    }if(this->comparator_ == rhs.comparator_){
        return true;
    }
    return false;
}

bool Date::operator!=(const Date& rhs)const{
    if((this->dateIsValid() == false) || (rhs.dateIsValid() == false)){
        return false;
    }
    return !(this->operator==(rhs));
}

bool Date::operator<(const Date& rhs)const{
    if((this->dateIsValid() == false) || (rhs.dateIsValid() == false)){
        return false;
    }
    if(this->comparator_ < rhs.comparator_){
        return true;
    }
    return false;
}

bool Date::operator>(const Date& rhs)const{
    if((this->dateIsValid() == false) || (rhs.dateIsValid() == false)){
        return false;
    }
    if(this->comparator_ > rhs.comparator_){
        return true;
    }
    return false;
}

bool Date::operator<=(const Date& rhs)const{
    if((this->dateIsValid() == false) || (rhs.dateIsValid() == false)){
        return false;
    }
    if(this->comparator_ <= rhs.comparator_){
        return true;
    }
    return false;
}

bool Date::operator>=(const Date& rhs)const{
    if((this->dateIsValid() == false) || (rhs.dateIsValid() == false)){
        return false;
    }
    if(this->comparator_ >= rhs.comparator_){
        return true;
    }
    return false;
}

std::istream& Date::read(std::istream& istr){
int Year;
int Month;
int Day;

istr >> Year;
if(istr.get() != '/'){
    this->Setter(0,0,0,CIN_FAILED);
    return istr;
}

istr >> Month;
if(istr.get() != '/'){
    this->Setter(0,0,0,CIN_FAILED);
    return istr;
}

istr >> Day;

this->Checker(Year,Month,Day);

return istr;
}

std::ostream& Date::write(std::ostream& ostr)const{
    ostr << setw(1) << setfill('0') << year_ << '/';
    ostr << setw(2) << setfill('0') << month_ << '/';
    ostr << setw('0') << setw(2) << day_;
	
	return ostr;    
}

std::ostream& operator<<(ostream& ostr, const Date& D) {
    D.write(ostr);
    return ostr;
}

std::istream& operator>>(istream& istr,Date& D){
    D.read(istr);
    return istr;
}

void Date::Checker(const int Year, const int Month, const int Day){
    if(!yearValidator(Year)){
        this->Setter(0,0,0,YEAR_ERROR);
        return;
    }
    if(!monthValidator(Month)){
        this->Setter(0,0,0,MON_ERROR);
        return;
    }
    if(!dayValidator(Year,Month,Day)){
        this->Setter(0,0,0,DAY_ERROR);
        return;
    }
    
    this->Setter(Year,Month,Day,NO_ERROR);
    return;
}

void Date::Setter(const int Year,const int Month,const int Day, const int Error){
    this->day_ = Day;
    this->month_ = Month;
    this->year_ = Year;
    this->errorCode_ = Error;
    if(Error == NO_ERROR){
        this->comparator_ = (Year * 372) + (Month * 13) + Day;
    }else{
        this->comparator_ = 0;
    }
}

}