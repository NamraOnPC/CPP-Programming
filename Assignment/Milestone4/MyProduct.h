// Name :- Namra Fanse
// Student No :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Date :- 10/4/2018
// Milestone 4



#ifndef AMA_MYPRODUCT_H__
#define AMA_MYPRODUCT_H__
#include "iProduct.h"

namespace AMA {
  class MyProduct : public iProduct {
    char text_[10000];
	char sku[4];
	char name_[20];
	int value;
  public:
    MyProduct(const char* name);
    std::fstream& store(std::fstream& file, bool addNewLine)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& is);
	bool operator==(const char*) const;
	double total_cost() const;
	const char* name() const;
	void quantity(int);
	int qtyNeeded() const;
	int quantity() const;
	int operator+=(int);
	bool operator>(const iProduct&) const;
  };
}
#endif
