// Name :- Namra Fanse
// Student Number :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 2/2/2018

#include <iostream>
#include "Kingdom.h"

namespace sict {
using namespace std;
	void display(Kingdom& kingdom){

	cout << kingdom.m_name << ", " << "population " << kingdom.m_population << endl;

	}
	
	void display(const Kingdom kingdom[], int count){
	    int totalPopulation = 0;
	    cout << "------------------------------" << endl;
	    cout << "Kingdoms of SICT" << endl;
	    cout << "------------------------------" << endl;
	    
	    for(int i = 0; i <= count-1; i++){
	        
	    
	    cout << i+1 << ". " << kingdom[i].m_name << ", " << "population " << kingdom[i].m_population << endl;
	    }
    cout << "------------------------------" << endl;
	
	for(int x = 0; x <= count; x++){
	    totalPopulation += kingdom[x].m_population;
	}
	
	cout << "Total population of SICT: " << totalPopulation << endl;
        cout << "------------------------------" << endl;	
	    }
	    
}



