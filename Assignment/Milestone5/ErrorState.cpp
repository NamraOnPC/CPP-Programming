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
 
    void ErrorState::Setter(const char* errorMessage){
        
        if(errorMessage == nullptr){
            
            this->errorMessage_ = new char[5];
            
            strcpy(this->errorMessage_, "GOOD");
            
        }else{
            
                if(this->errorMessage_ != nullptr){
                    
                    delete[] this->errorMessage_;
                    
                }
            
            this->errorMessage_ = new char[strlen(errorMessage) + 1];
            
            strcpy(this->errorMessage_, errorMessage);
            
        }
        
        
    }



	ErrorState::ErrorState(const char* errorMessage) {

		this->errorMessage_ = nullptr;
		
		Setter(errorMessage);

	}
	// this function cleans any message stored in the current objects and initializes the object to safe empty state.

	void ErrorState::clear() {

		delete[] this->errorMessage_;

		this->errorMessage_ = new char[5];

		strcpy(this->errorMessage_, "GOOD");

	}

	// this function return true if the the object is in safe empty state
	
	bool ErrorState::isClear() const {
		bool isClear = false;

		if (strcmp(this->errorMessage_, "GOOD") == 0 ) {

			isClear = true;

		}
		
		return isClear;

	}

	// deallocates any memory for a message that was stored before
	// allocates dynamic memory to store copy of str
	//copies the string for address str to the allocated memory region
	
	void ErrorState::message(const char* str) {

		delete[] this->errorMessage_;

		this->errorMessage_ = new char[strlen(str) + 1];

		strcpy(this->errorMessage_, str);

	}

	//this function returns address of the message stored in the current object 

	const char* ErrorState::message() const {
		
		return this->errorMessage_;
	
	}



    std::ostream& operator<<(std::ostream& ostr,const ErrorState& Obj){
        
        if(Obj.isClear() == false){
            
            cout << Obj.message();
            
        }
        
        return ostr;
    
    }

	//this function deallocates dynamic memory allocated by current object
	// and sets current object to a safe empty state
    
    ErrorState::~ErrorState(){
        
        delete[] this->errorMessage_;
        
    }
}