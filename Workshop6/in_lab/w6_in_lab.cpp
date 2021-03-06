// Name :- Namra Fanse
// Student ID :- 112219175
// Student Email :- nrfanse@myseneca.catch
// Date :- 12/3/2018
// Workshop 6 in_lab


#include <iostream>
#include "Contact.h"

using namespace std;
using namespace sict;

int main() {
    cout << "----------------------------------------" << endl;
    cout << "Testing the default constructor!" << endl;
    cout << "----------------------------------------" << endl;
    sict::Contact empty; // sict:: intentional
    empty.display();
    cout << "----------------------------------------" << endl << endl;

    cout << "----------------------------------------" << endl;
    cout << "Testing an invalid contact!" << endl;
    cout << "----------------------------------------" << endl;
    Contact bad(nullptr, nullptr, 0);
    bad.display();
    Contact alsoBad("", nullptr, 0);
    alsoBad.display();
    cout << "----------------------------------------" << endl << endl;

    cout << "----------------------------------------" << endl;
    cout << "Testing the constructor with parameters!" << endl;
    cout << "----------------------------------------" << endl;
    Contact temp("A contact with a very looooong name!", nullptr, 0);
    temp.display();
    cout << "----------------------------------------" << endl << endl;

    cout << "----------------------------------------" << endl;
    cout << "Testing a valid contact!" << endl;
    cout << "----------------------------------------" << endl;
	long long phoneNumbers[] = { 1416123456LL, 14161234567LL, 1416234567890LL,
		14162345678LL, -1LL, 124163456789LL,
		14161230002LL };
	Contact someContact("John Doe", phoneNumbers, 7);
    someContact.display();
    cout << "----------------------------------------" << endl << endl;

    return 0;
}