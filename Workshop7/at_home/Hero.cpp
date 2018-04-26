// Name :- Namra Fanse
// Student ID :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Date :- 22/3/2018
// Workshop 7 at_home

#include <iostream>
#include "Hero.h"
#include <cstring>

using namespace std;

namespace sict{
    
    Hero::Hero(){
        name_[0] = '\0';
        health_ = 0;
        attackStrength_ = 0;
    }
    
    Hero::Hero(const char* name, const int health, const int attackStrength){
        
        bool checkName = (name[0] != '\0' && name != nullptr);
        bool checkHealth = (health > 0);
        bool checkAttackStrength = (attackStrength > 0);
        
        if(checkName && checkHealth && checkAttackStrength){
            
            strcpy(name_, name);
            health_ = health;
            attackStrength_ = attackStrength;
        }else{
            *this = Hero();
        }
        
    }
    
    bool Hero::isAlive() const{
        if(health_ > 0){
            return true;
        }else{
            return false;
        }
    }
    
    int Hero::attackStrength() const{
        if(attackStrength_ > 0){
            return attackStrength_;
        }else{
            return 0;
        }
    }
    
    void Hero::operator-=(int attack){
        if(attack > 0 && health_ > 0){
            health_ -= attack;
            if(health_ < 0){
                health_ = 0;
            }
        }
    }
    
    std::ostream& operator<<(std::ostream& os, const Hero& hero){
        if(hero.name_[0] != '\0' && hero.health_ != -1 && hero.attackStrength_ != -1){
            os << hero.name_;
        }else{
            os << "No hero";
        }
        return os;
    }
    
    const char* Hero::getName() const{
        return name_;
    }
    
    const Hero& operator*(const Hero& first, const Hero& second){
        Hero player1 = first;
        Hero player2 = second;
        Hero winner;
        
        int round = 0;
        
        for(int i = 0; i < max_rounds && (player1.isAlive() && player2.isAlive() ); i++){
            
            player1 -= player2.attackStrength();
            player2 -= player1.attackStrength();
            round = i;
            
        }
        
        round++;
        
        if(!player1.isAlive() && !player2.isAlive()){
        
        winner = player1;
        
        cout << "Ancient Battle! " << first.getName() << " vs " << second.getName() << " : " 
        << "Winner is " << winner.getName() << " in " << round << " rounds." << endl;
        
        return first;
        
        }else if(!player1.isAlive()){
           
            winner = player2;
            
            cout << "Ancient Battle! " << first.getName() << " vs " << second.getName() << " : " 
            << "Winner is " << winner.getName() << " in " << round << " rounds." << endl;
        
            return second;
        
        }else if(!player2.isAlive()){
            
            winner = player1;
            
            cout << "Ancient Battle! " << first.getName() << " vs " << second.getName() << " : " 
            << "Winner is " << winner.getName() << " in " << round << " rounds." << endl;
        
            return first;
        }else{
            return first;
        }
    }
}
