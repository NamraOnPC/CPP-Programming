// Name :- Namra Fanse
// Student ID :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Date :- 22/3/2018
// Workshop 7 at_home


#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"
using namespace std;

namespace sict{
    
    class SuperHero : public Hero {
        
        private:
        
        int bonus_;
        int defend_;
        
        public:
        
        SuperHero();
        SuperHero(const char* name, int health, int attackStrength,int bonus, int defend);
        
        int attackStrength() const;
        int defend() const;
        
        
    };
    
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
    
}

#endif