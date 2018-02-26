// Name :- Namra Fanse
// Student ID :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Workshop 5 in_lab;

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
using namespace std;

namespace sict {

	class Fraction {
    
    private:
    
    int numerator_;
    int denominator_;
    
	public:
	
	Fraction();
	Fraction(int numerator, int denominator);
	
	int max() const;
	int min() const;
	void reduce();
	int gcd() const;
	bool isEmpty() const;
	void display() const;
	
	Fraction operator+(const Fraction& rhs) const;

	};

}
#endif