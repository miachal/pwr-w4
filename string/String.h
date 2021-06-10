#pragma once

class String {
private:
	char *str;

public:
	String(void);
	String(int n);
	String(char c);
	String(char *s);
	~String();
	
	//
	int length(void);
	void print(void);

	//
	void add(char *s);
	void add(String &s);

	void operator<<(char *s);
	void operator<<(String &a);

	//
	String& operator=(char c);
	String& operator=(char *s);
	String& operator=(String &a);

	//
	friend String operator+(char *s, String &a);
	friend String operator+(String &a, char *s);
	friend String operator+(String &a, String &b);


};