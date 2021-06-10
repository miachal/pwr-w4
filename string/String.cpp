#pragma once

#include "String.h"
#include <cstring>
#include <cstdio>

String::String(void) { 
	str = new char[1];
	str[0] = '\0';
}

String::String(int n) {
	str = new char(n+1);
	str[n] = '\0';
}

String::String(char c) {
	str = new char[2];
	str[0] = c;
	str[1] = '\0';
}

String::String(char *s) {
	str = new char[strlen(s)+1];
	strcpy(str, s);
	str[strlen(s)] = '\0';
}

String::~String(void) {
	delete [] str;
}


int String::length(void) { return strlen(str); }

void String::print(void) { printf("%s\n",str); }

void String::add(char *s) {
	char *tmp = new char[strlen(str) + 1];
	strcpy(tmp, str);

	delete [] str;
	str = new char[strlen(tmp) + strlen(s) + 1];

	strcpy(str, tmp);
	strcat(str, s);
	
	delete [] tmp;
}

void String::add(String &s) {
	char *tmp = new char[strlen(str) + 1];
	strcpy(tmp, str);

	if(this != &s) {
		delete [] str;
		str = new char[strlen(tmp) + strlen(s.str) + 1];

		strcpy(str, tmp);
		strcat(str, s.str);
	}
	else
		add(tmp);
	
	delete [] tmp;
}

void String::operator<<(char *s) { add(s); }

void String::operator<<(String &a) { add(a); }

String& String::operator=(char c) {
	delete [] str;
	str = new char[2];
	str[0] = c;
	str[1] = '\0';
	return *this;
}

String& String::operator=(char *s) {
	delete [] str;
	if(s != NULL) {
		str = new char[strlen(str) +1];
		strcpy(str, s);
	} else {
		str = new char[1];
		str[0] = '\0';
	}

	return *this;
}

String& String::operator=(String &a) {
	if(this != &a) {
		delete [] str;
		str = new char[strlen(a.str) + 1];
		strcpy(str, a.str);
	}

	return *this;
}

String operator+(char *s, String &a) {
	String tmp;
	tmp = s;
	tmp.add(a);
	return tmp;
}

String operator+(String &a, char *s) {
	String tmp;
	tmp = a;
	tmp.add(s);
	return tmp;

}

String operator+(String &a, String &b) {
	String tmp;
	tmp = a;
	tmp.add(b);
	return tmp;
}