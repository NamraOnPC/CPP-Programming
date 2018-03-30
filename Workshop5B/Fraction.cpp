// Name :- Namra Fanse
// Student ID :- 112219175
// Student Email :- nrfanse@myseneca.ca
// Workshop 5 in_lab;



#include <iostream>
#include "Fraction.h"
using namespace std;

namespace sict {

Fraction::Fraction(){
    numerator_ = 0;
    denominator_ = 0;
}

Fraction::Fraction(int numerator, int denominator){
    if(numerator >= 0 && denominator > 0){
        numerator_ = numerator;
        denominator_ = denominator;
        reduce();
    }else{
        *this = Fraction();
    }
}

int Fraction::max() const{
    return std::max(numerator_, denominator_);
}

int Fraction::min() const{
    return std::min(numerator_, denominator_); 
}

int Fraction::gcd() const {
    int mn = min();  // min of numerator and denominator
    int mx = max();  // max of numerator and denominator
    int g_c_d = 1;
    bool found = false;

    for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
        if (mx % x == 0 && mn % x == 0) {
            found = true;
            g_c_d = x;
            }
        }
        return g_c_d;
    }

void Fraction::reduce(){
    int GCD = gcd();
    
    numerator_ /= GCD;
    denominator_ /= GCD;
}

void Fraction::display() const{
    if(isEmpty()){
        cout << "no fraction stored";
    }else if(denominator_ == 1){
        cout << numerator_;
    }else{
        cout << numerator_ << "/" << denominator_;
    }
}    

bool Fraction::isEmpty() const{
    bool valid = false;
    if(numerator_ == 0 || denominator_ == 0){
        valid = true;
    }
    return valid;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    Fraction foo;
    if(lhs.isEmpty() == false && rhs.isEmpty() == false){
        foo.numerator_ = (lhs.numerator_ * rhs.denominator_) + (lhs.denominator_ * rhs.numerator_);
        foo.denominator_ = (lhs.denominator_ * rhs.denominator_);
    }else{
        foo.numerator_ = 0;
        foo.denominator_ = 0;
    }
    return foo;
}  
}
