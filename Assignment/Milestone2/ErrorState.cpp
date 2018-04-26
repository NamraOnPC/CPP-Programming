// Name :- Namra Fanse
// Student ID :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Date :- 18/3/2018
// Milestone 2 

#include <iostream>
#include <cstring>
#include "ErrorState.h"
using namespace std;

namespace AMA {
    // receives address of a null terminated string that has error message
	// if address is a null pointer it puts the object in safe empty state
	// if it is not a null pointer meaning it points to a message then this function allocates memory for that message
	// and then copies the message into the allocated memory 

	ErrorState::ErrorState(const char* errorMessage) {

		if (errorMessage == nullptr) {

			errorMessage_ = nullptr;


		}
		else {

			errorMessage_ = new char[strlen(errorMessage) + 1];

			strcpy(errorMessage_, errorMessage);

		}

	}
	// this function cleans any message stored in the current objects and initializes the object to safe empty state.

	void ErrorState::clear() {

		delete[] this->errorMessage_;

		errorMessage_ = nullptr;

	}

	// this function return true if the the object is in safe empty state
	
	bool ErrorState::isClear() const {

		if (errorMessage_ == nullptr) {

			return true;

		}
		else {

			return false;

		}

	}

	// deallocates any memory for a message that was stored before
	// allocates dynamic memory to store copy of str
	//copies the string for address str to the allocated memory region
	
	void ErrorState::message(const char* str) {

		delete[] errorMessage_;

		errorMessage_ = new char[strlen(str) + 1];

		strcpy(errorMessage_, str);

	}

	//this function returns address of the message stored in the current object 

	const char* ErrorState::message() const {
		
		return errorMessage_;
	
	}

	//if there is an error message for ostream object it returns a reference to the ostream object
	//else the operator wont send anything to ostream and would return a reference to the ostream object 

    std::ostream& operator<<(std::ostream& ostr,const ErrorState& Obj){
        
        if(!Obj.isClear()){
            
            ostr << Obj.message();
            
        }
        
        return ostr;
    
    }

	//this function deallocates dynamic memory allocated by current object
	// and sets current object to a safe empty state
    
    ErrorState::~ErrorState(){
        
        delete[] errorMessage_;
        
        errorMessage_ = nullptr;
        
    }
}
