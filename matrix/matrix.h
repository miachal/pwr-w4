#pragma once

class matrix {
private:
	double **p;
	int m_dCols;
	int m_dRows;

public:
	// ----------------------------------------------
	// C&D
	// ----------------------------------------------
	matrix();
	matrix(int, int);
	~matrix();

	// ----------------------------------------------
	// 
	// ----------------------------------------------
	void null();
	void irand(int f, int t);
	double det();
	void print();

	matrix T();

	matrix subRows(int w);
	matrix subCols(int k);
	matrix subMatrix(int w, int k);

	matrix swapRows(int a, int b);
	matrix swapCols(int a, int b);

	matrix rev();

	// ----------------------------------------------
	// operator+
	// ----------------------------------------------
	friend matrix operator+(matrix& a, matrix& b);
	friend matrix operator+(matrix& a, double d);
	friend matrix operator+(double d, matrix& b);

	// ----------------------------------------------
	// operator-
	// ----------------------------------------------
	matrix operator-();
	friend matrix operator-(matrix& a, matrix& b);

	// ----------------------------------------------
	// operator*
	// ----------------------------------------------
	friend matrix operator*(matrix& a, double d);
	friend matrix operator*(double d, matrix& a);
	friend matrix operator*(matrix& a, matrix& b);

	// ----------------------------------------------
	// operator=
	// ----------------------------------------------
	matrix& operator=(matrix& a);

	// ----------------------------------------------
	// operator()
	// ----------------------------------------------
	double operator()(int w, int k);
	void operator()(int w, int k, double val);

	// ----------------------------------------------
	// operator~
	// ----------------------------------------------
	double operator~();
};