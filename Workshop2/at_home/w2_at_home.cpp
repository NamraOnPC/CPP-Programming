//Workshop 2 
//Name :- Namra Fanse 
//Date :- 2/2/2018
//Student Number :- 112219175
//Email id :- nrfanse@myseneca.ca


#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
int count = 0; // the number of kingdoms in the array
       
// TODO: declare the pKingdom pointer here (don't forget to initialize it)
Kingdom* pKingdom = nullptr;

cout << "==========\n"
<< "Input data\n"
<< "==========\n"
<< "Enter the number of Kingdoms: ";
cin >> count;
cin.ignore();

if (count < 1) return 1;

// TODO: allocate dynamic memory here for the pKingdom pointer
pKingdom = new Kingdom[count];

for (int i = 0; i < count; ++i) {
	cout << "Kingdom #" << i + 1 << ": " << endl;
 // TODO: add code to accept user input for Kingdom i
   read(pKingdom[i]);
    

}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st Kingdom entered is" << endl
		<< "------------------------------" << endl;
	sict::display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

  // for (int x = 0; x < count; x++){
//    * ( pKingdom + count  ) = ;
// }
Kingdom* newpKingdom = nullptr;
 newpKingdom = new Kingdom[count];
std::copy(pKingdom, pKingdom + count, newpKingdom); 
	// TODO: deallocate the dynamic memory here
        delete[] pKingdom; 
    pKingdom = newpKingdom;    
	
	
cout << "==========\n"
     << "Input data\n"
     << "==========\n"
	 << "Kingdom #" << count + 1 << ": " << endl;
	 
	 read(newpKingdom[count]);
	 count++;
	 cout << "==========\n" << endl;
	 
	 display(newpKingdom, count);
	 cout << endl;
	 
//	 delete [] newpKingdom;
	
	return 0;
	
}

// read accepts data for a Kingdom from standard input
//
void read(sict::Kingdom& kingdom) {

	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
};
