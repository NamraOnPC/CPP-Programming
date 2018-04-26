// Name :- Namra Fanse
// Student No :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Date :- 10/4/2018
// Milestone 4


#include "MyProduct.h"

namespace AMA {

	iProduct* CreateProduct() {
		return new MyProduct("Product");
	}
	iProduct* CreatePerishable() {
		return new MyProduct("Perishable");
	}
	
}