// Name :- Namra Fanse
// Student Number :- 112219175
// Email :- nrfanse@myseneca.ca
// Date :- 2/2/2018

#ifndef SICT_KINGDOM_H_
#define SICT_KINGDOM_H_

namespace sict {

	struct Kingdom{
		char m_name[32];
		int m_population;
	};
	
	void display(Kingdom & );

    void display(const Kingdom[], int count);
}



#endif
