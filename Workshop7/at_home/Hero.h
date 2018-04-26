// Name :- Namra Fanse
// Student ID :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Date :- 22/3/2018
// Workshop 7 at_home


#ifndef SICT_HERO_H
#define SICT_HERO_H
using namespace std;

namespace sict{
    
    const int max_rounds = 100;
    
    class Hero{
        
    private:
        
        char name_[40 + 1];
        int  health_;
        int  attackStrength_;
        
    public:
        
        Hero();
        Hero(const char* name, const int health, const int attackStrength);
        
        bool isAlive() const;
        int attackStrength() const;
        const char* getName() const;
        
        void operator-=(int attack);
        friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
    };
    
    const Hero& operator*(const Hero& first, const Hero& second);
}


#endif

