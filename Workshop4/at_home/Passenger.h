// Name :- Namra Fanse
// Student ID :- 112219175
// Email :- nrfanse@myseneca.ca
// Workshop 4 at_home
// Date :- 14/2/2018




#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

using namespace std;

namespace sict {
    class Passenger{
        private:
        char passengerName_[32];
        char destination_[32];
        int yearOfDeparture_;
        int monthOfDeparture_;
        int dayOfDeparture_;
        
        public:
        Passenger();
        Passenger(const char *passengerName, const char *destination);
        Passenger(const char *passengerName, const char *destination, int yearOfDeparture, int monthOfDeparture, int dayOfDeparture);
	
        bool isEmpty() const;
        void display() const;
        const char* name() const;
        bool canTravelWith(const Passenger&) const;
    };
}

#endif 
