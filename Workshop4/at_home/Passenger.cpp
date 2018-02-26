// Name :- Namra Fanse
// Student ID :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Workshop 4 at_home
// Date :- 14/2/2018



#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

namespace sict{
    
Passenger::Passenger(){
		passengerName_[0] = '\0';
		destination_[0] = '\0';
	        yearOfDeparture_ = 0;
                monthOfDeparture_ = 0;
                dayOfDeparture_ = 0;
	}

Passenger::Passenger(const char *passengerName,const char *destination){
        if((passengerName != nullptr) && (destination != nullptr)){
            dayOfDeparture_ = 1;
            monthOfDeparture_ = 7;
            yearOfDeparture_ = 2017;
        }
    }
Passenger::Passenger(const char *passengerName, const char *destination, int yearOfDeparture, int monthOfDeparture, int dayOfDeparture){
    
    if(passengerName == nullptr || destination == nullptr || yearOfDeparture > 2020 || yearOfDeparture < 2017 || monthOfDeparture  < 1 || monthOfDeparture > 12 || dayOfDeparture > 31 || dayOfDeparture < 1){
	    *this = Passenger();
    }else{
	    strcpy(passengerName_ , passengerName);
	    strcpy(destination_ , destination);
	    yearOfDeparture_ = yearOfDeparture;
	    monthOfDeparture_ = monthOfDeparture;
	    dayOfDeparture_ = dayOfDeparture;
    }
		    
} 
    
    bool Passenger::isEmpty() const{
        bool examine = strlen(passengerName_) > 0 && strlen(destination_) > 0 && dayOfDeparture_ != 0 && monthOfDeparture_ != 0 && yearOfDeparture_ != 0;
        return !examine;
        
    }
    
    void Passenger::display() const{
        if(isEmpty()){
           cout << "No passenger!" << endl;
        }else{
            if(monthOfDeparture_ > 0 && monthOfDeparture_ < 10){
            cout << passengerName_ << " - " << destination_ << " on " << yearOfDeparture_ << "/0" << monthOfDeparture_ << "/" << dayOfDeparture_ <<endl;
            }else{
            cout << passengerName_ << " - " << destination_ << " on " << yearOfDeparture_ << "/" << monthOfDeparture_ << "/" << dayOfDeparture_ <<endl;
            }
        }
    }
    
    const char* Passenger::name() const{
        return passengerName_;
    }
    
    
    
    bool Passenger::canTravelWith(const Passenger& passengerName) const{
        bool check;
        
        if(strcmp(this->destination_, passengerName.destination_) == 0 
        && this->dayOfDeparture_ == passengerName.dayOfDeparture_
        && this->monthOfDeparture_ == passengerName.monthOfDeparture_
        && this->yearOfDeparture_ == passengerName.yearOfDeparture_){
            check = true;
        }else{
            check = false;
        }
        return check;
        
    }
    
}

