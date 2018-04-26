// Name :- Namra Fanse
// Student ID :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Date :- 22/3/2018
// Workshop 7 at_home



#include <iostream>
#include <string>
#include "Hero.h"
#include "SuperHero.h"
using namespace std;
using namespace sict;

namespace sict{
    
    SuperHero::SuperHero() : Hero() {
        
        bonus_ = 0;
        defend_ = 0;
        
    }
    
    SuperHero::SuperHero(const char* name, int health, int attack,int bonus, int defend) : Hero(name,health,attack) {
        
        bonus_ = bonus;
        defend_ = defend;
        
    }
    
    int SuperHero::attackStrength() const{
        
        if(Hero::attackStrength() != -1){
            return Hero::attackStrength() + bonus_;
        }else{
            return 0;
        }
    }
    
    int SuperHero::defend() const{
        
        if(defend_ != -1){
            return defend_;
        }else{
            return 0;
        }
    }
    
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
        
        SuperHero player1 = first;
        SuperHero player2 = second;
        SuperHero winner;
        
        int round = 0;
        
        for(int i = 0; i < max_rounds && (player1.isAlive() && player2.isAlive() ); i++){
            
            player1 -= player2.attackStrength() - player1.defend();
            player2 -= player1.attackStrength() - player2.defend();
            round = i;
            
        }
        
        round++;
        
        if(!player1.isAlive() && !player2.isAlive()){
        
        winner = player1;
        
        cout << "Super Fight! " << first.getName() << " vs " << second.getName() << " : " 
        << "Winner is " << winner.getName() << " in " << round << " rounds." << endl;
        
        return first;
        
        }else if(!player1.isAlive()){
           
            winner = player2;
            
            cout << "Super Fight! " << first.getName() << " vs " << second.getName() << " : " 
            << "Winner is " << winner.getName() << " in " << round << " rounds." << endl;
        
            return second;
        
        }else if(!player2.isAlive()){
            
            winner = player1;
            
            cout << "Super Fight! " << first.getName() << " vs " << second.getName() << " : " 
            << "Winner is " << winner.getName() << " in " << round << " rounds." << endl;
        
            return first;
        }else{
            return first;
        }
    }
    
}