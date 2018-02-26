// Name :- Namra Fanse
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Workshop 4 in_lab
// Date :- 12/2/2018




#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

using namespace std;

namespace sict {
    class Passenger{
        private:
        char passengerName_[32];
        char destination_[32];
        
        public:
        Passenger();
        Passenger(const char *passengerName, const char *destination);
	
        
        bool isEmpty() const;
        void display() const;
        
    };
}

#endif 
