#pragma once
#include <string>

class Complex {
private:
	double Re, Im;

public:
	// construct
	// ==================================================================================
	Complex();
	Complex(double a);
	Complex(double a, double b);

	// set get
	// ==================================================================================
	double getRe();
	void setRe(double a);
	double getIm();
	void setIm(double b);

	// debug
	// ==================================================================================
	void print();

	// sub
	// ==================================================================================
	Complex &operator-();
	Complex &operator-(double a);
	Complex &operator-(Complex &a);

	// add
	// ==================================================================================
	Complex &operator+(double a);
	Complex &operator+(Complex &a);
	Complex& Complex::operator+=(double a);  //
	Complex& Complex::operator+=(Complex &a);//

	// mul
	// ==================================================================================
	Complex& Complex::operator*(double a);
	Complex& Complex::operator*(Complex &a);

	// div
	// ==================================================================================
	Complex& Complex::operator/(double a);
	Complex& Complex::operator/(Complex &a);

	// math
	// ==================================================================================
	double abs();

	// casting
	// ==================================================================================
	operator string();
	std::string toString();
};