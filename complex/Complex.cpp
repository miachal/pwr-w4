#pragma once

// includes
// ==================================================================================
#include <iostream>
#include <sstream>
#include <string>
#include "Complex.h"

// namespaces
// ==================================================================================
using namespace std;

// construct
// ==================================================================================
Complex::Complex()						{ Re=0; Im=0; }
Complex::Complex(double a)				{ Re=a; Im=0; }
Complex::Complex(double a, double b)	{ Re=a; Im=b; }

// set get
// ==================================================================================
double Complex::getRe() { return Re; }
void Complex::setRe(double a) { Re=a; }
double Complex::getIm() { return Im; }
void Complex::setIm(double b) { Im=b; }

// debug
// ==================================================================================
void Complex::print() { cout << "(" << this->Re << ", " << this->Im << "i)\n"; }

// sub
// ==================================================================================
Complex& Complex::operator-() { return Complex(-Re, -Im); }
Complex& Complex::operator-(double a) { return Complex(Re-a, Im); }
Complex& Complex::operator-(Complex &a) { return Complex(Re-a.Re, Im-a.Im); }

// add
// ==================================================================================
Complex& Complex::operator+(double a) { return Complex(Re+a, Im); }
Complex& Complex::operator+(Complex &a) { return Complex(Re+a.Re, Im+a.Im); }
Complex& Complex::operator+=(double a) { Re+=a; return *this; }
Complex& Complex::operator+=(Complex &a) { Re+=a.Re; Im+=a.Im; return *this; }

// mul
// ==================================================================================
Complex& Complex::operator*(double a) { return Complex(Re*a, Im*a); }
Complex& Complex::operator*(Complex &a) { return Complex(Re*a.Re-Im*a.Im, Re*a.Im+Im*a.Re); }

// div
// ==================================================================================
Complex& Complex::operator/(double a) { return Complex(Re/a, Im/a); }
Complex& Complex::operator/(Complex &a) { 
	double f = 1 / a.abs();
	return Complex(f*(Re*a.Re+Im*a.Im), f*(Im*a.Re-Re*a.Im));
}

// math
// ==================================================================================
double Complex::abs() { return sqrt(Re*Re+Im*Im); }

// casting
// ==================================================================================
Complex::operator string() { return toString(); }
string Complex::toString() {
	ostringstream out;
    out << Re << ( Im < 0 ? " - I*" : " + I*" ) << Im * ( Im < 0 ? -1 : 1 );
    return out.str();
}