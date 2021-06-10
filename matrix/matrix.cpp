#pragma once
#include "matrix.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

// ----------------------------------------------
// C&D
// ----------------------------------------------
matrix::matrix() {
	m_dRows = 0;
	m_dCols = 0;
	p = NULL;
}

matrix::matrix(int a, int b) {
	if(a>0 && b>0) {
		m_dRows = a; m_dCols = b;
		p = new double* [m_dRows];
		for(int i=0; i<m_dRows; i++) p[i] = new double[m_dCols];
	}
}

matrix::~matrix() {
	if(!p) {
		for(int i=0; i<m_dCols; i++)
			delete[] p[i];

		delete[] p;
	}
}

// ----------------------------------------------
// 
// ----------------------------------------------
void matrix::null() {
	for(int i=0; i<m_dRows; i++)
		for(int j=0; j<m_dCols; j++)
			p[i][j] = 0;
}

void matrix::irand(int f, int t) {
	for(int i=0; i<m_dRows; i++)
		for(int j=0; j<m_dCols; j++)
			p[i][j] = rand()%(t-f+1)+f;
}

double matrix::det() {
	int det = 0;
	if(m_dRows == m_dCols) {
		int n = m_dCols;
		for(int i=0; i<n-1; i++)
			for(int j=i+1; j<n; j++)
				for(int k=i+1; k<n; k++)
					p[j][k] = p[j][i] / p[i][i] * p[i][k];
      
		det = 1;
		for(int i=0; i<n; i++) det *= p[i][i];
	}

	return det;
}

void matrix::print() {
	for(int i=0; i<m_dRows; i++) {
		for(int j=0; j<m_dCols; j++)
			printf("%.2f ", p[i][j]);
		printf("\n");
	}
}

matrix matrix::T() {
	matrix tmp(m_dRows, m_dCols);
	for(int i=0; i<m_dRows; i++)
		for(int j=0; j<m_dCols; j++)
			tmp.p[i][j] = p[j][i];
	return tmp;
}

matrix matrix::subRows(int w) {
	matrix tmp(m_dRows-1, m_dCols);
	for(int i=0; i<m_dRows; i++)
		for(int j=0; j<m_dCols; j++)
			if(i != w)
				(i > w) ? tmp.p[i-1][j] = p[i][j] : tmp.p[i][j] = p[i][j]; 
	
	return tmp;
}

matrix matrix::subCols(int k) {
	matrix tmp(m_dRows, m_dCols-1);
	for(int i=0; i<m_dRows; i++)
		for(int j=0; j<m_dCols; j++)
			if(j != k)
				(j > k) ? tmp.p[i][j-1] = p[i][j] : tmp.p[i][j] = p[i][j]; 

	return tmp;
}

matrix matrix::subMatrix(int w, int k) {
	return (subRows(w)).subCols(k);
}

matrix matrix::swapRows(int a, int b) {
	matrix tmp(m_dRows, m_dCols);
	for(int i=0; i<m_dRows; i++) {
		for(int j=0; j<m_dRows; j++) {
			if(i != a && i != b) tmp.p[i][j] = p[i][j];
			else {
				if(i == a) tmp.p[i][j] = p[b][j];
				else tmp.p[i][j] = p[a][j];
			}
		}
	}
	return tmp;
}

matrix matrix::swapCols(int a, int b) {
	matrix tmp(m_dRows, m_dCols);
	for(int i=0; i<m_dRows; i++) {
		for(int j=0; j<m_dRows; j++) {
			if(j != a && j != b) tmp.p[i][j] = p[i][j];
			else {
				if(j == a) tmp.p[i][j] = p[i][b];
				else tmp.p[i][j] = p[i][a];
			}
		}
	}
	return tmp;
}

matrix matrix::rev() {
	int n = m_dCols;
	matrix tmp(n,n);
	for(int i=0;i<n;i++) 
  { 
     tmp.p[i][i] = 1/p[i][i];    
        for(int j=0;j<n;j++) if(j!=i) 
           { 
             tmp.p[j][i] = p[j][i] * p[i][i]; 
                  for (int k=0;k<n;k++) if(k!=i) 
                  { 
                    tmp.p[j][k]-= p[j][i] * p[i][k]; 
                    if(j==(n-1)) 
                      tmp.p[i][k] = -( p[i][k] * p[i][i] ); 
                  } 
            } 
   }
	return tmp;
}

// ----------------------------------------------
// operator+
// ----------------------------------------------
matrix operator+(matrix& a, matrix& b) {
	if(a.m_dCols == b.m_dCols && a.m_dRows == b.m_dRows) {
		matrix tmp(a.m_dRows, a.m_dCols);
		for(int i=0; i<a.m_dRows; i++)
			for(int j=0; j<a.m_dCols; j++)
				tmp.p[i][j] = a.p[i][j] + b.p[i][j];
		return tmp;
	}
}

matrix operator+(matrix& a, double d) {
		matrix tmp(a.m_dRows, a.m_dCols);
		for(int i=0; i<a.m_dRows; i++)
			for(int j=0; j<a.m_dCols; j++)
				tmp.p[i][j] = a.p[i][j] + d;
		return tmp;
	
}

matrix operator+(double d, matrix& b) {
	return (b+d);
}

// ----------------------------------------------
// operator-
// ----------------------------------------------
matrix matrix::operator-() {
	matrix tmp(m_dRows, m_dCols);
	for(int i=0; i<m_dRows; i++)
			for(int j=0; j<m_dCols; j++)
				p[i][j] == 0 ? tmp.p[i][j] = p[i][j] : tmp.p[i][j] = -p[i][j];
	return tmp;
}

matrix operator-(matrix& a, matrix& b) {
	if(a.m_dCols == b.m_dCols && a.m_dRows == b.m_dRows) {
		matrix tmp(a.m_dRows, a.m_dCols);
		for(int i=0; i<a.m_dRows; i++)
			for(int j=0; j<a.m_dCols; j++)
				tmp.p[i][j] = a.p[i][j] - b.p[i][j];
		return tmp;
	}
}
// ----------------------------------------------
// operator*
// ----------------------------------------------
matrix operator*(matrix& a, double d) {
	matrix tmp(a.m_dRows, a.m_dCols);
	for(int i=0; i<a.m_dRows; i++)
		for(int j=0; j<a.m_dCols; j++)
			tmp.p[i][j] = a.p[i][j] * d;
	return tmp;
	
}

matrix operator*(double d, matrix& a) { 
	return (a * d); 
}

matrix operator*(matrix& a, matrix& b) {
	if(a.m_dCols == b.m_dRows) {
		matrix tmp(a.m_dRows, b.m_dCols);
		tmp.null();
		for(int i=0; i<a.m_dRows; i++)
			for(int j=0; j<b.m_dCols; j++)
				for(int e=0; e<a.m_dCols; e++)
					tmp.p[i][j] += (a.p[i][e] * b.p[e][j]); 

		return tmp;
	} else {
		matrix tmp(1,1); tmp.null();
		return tmp;
	}
}

// ----------------------------------------------
// operator=
// ----------------------------------------------
matrix& matrix::operator=(matrix& a) {
	if(this != &a) {
		if(m_dCols != a.m_dCols || m_dRows != a.m_dRows) {
			// del
			for(int i=0; i<m_dCols; i++)
				delete[] p[i];

			delete[] p;

			// new
			m_dRows = a.m_dRows; m_dCols = a.m_dCols;
			p = new double* [a.m_dRows];
			for(int i=0; i<a.m_dRows; i++) p[i] = new double[a.m_dCols];
		}

		// cp
		//memcpy();
		for(int i=0; i<a.m_dRows; i++)
			for(int j=0; j<a.m_dCols; j++)
				p[i][j] = a.p[i][j];
	}
	return *this;
}
// ----------------------------------------------
// operator()
// ----------------------------------------------
double matrix::operator()(int w, int k) {
	return p[w][k];
}

void matrix::operator()(int w, int k, double val) {
	p[w][k] = val;
}
// ----------------------------------------------
// operator~
// ----------------------------------------------
double matrix::operator~() {
	return det();
}