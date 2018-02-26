// Name :- Namra Fanse
// Student ID :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Workshop 4 in_lab
// Date :- 12/2/2018



#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

namespace sict{
    
Passenger::Passenger(){
		passengerName_[0] = '\0';
		destination_[0] = '\0';
	}

Passenger::Passenger(const char *passengerName,const char *destination){
        if((passengerName != '\0') && (destination != '\0')){
            strcpy(passengerName_,passengerName);
            strcpy(destination_,destination);
        }else{
            passengerName_[0] = '\0';
            destination_[0] = '\0';
        }
    }
    
    bool Passenger::isEmpty() const{
        bool examine = false;
        if(passengerName_[0] == '\0' || destination_[0] == '\0'){
            examine = true;
        }
        return examine;
    }
    
    void Passenger::display() const{
        if(!isEmpty()){
            cout << passengerName_ << " - " << destination_ << endl;
        }else{
            cout << "No passenger!" << endl; 
        }
    }
    
    
}
