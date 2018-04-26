// Name :- Namra Fanse
// Student ID :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Date :- 18/3/2018
// Milestone 2 

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>


using namespace std;

namespace AMA {

	class ErrorState {
	private:

		char* errorMessage_;
		
		void Setter(const char* errorMessage);
	public:

		explicit ErrorState(const char* errorMessage = nullptr); // 

		void clear();
		bool isClear()const;
		void message(const char* str);
		const char* message() const;

		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;

		virtual ~ErrorState();
	};

    std::ostream& operator<<(std::ostream& ostr,const ErrorState& Obj);

}


#endif
