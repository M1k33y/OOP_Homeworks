#pragma once

class Number
{
	// add data members
	char* strNumber;
	int nrBase;
	int lg;
public:


	Number(const char* value, int base); // where base is between 2 and 16
	~Number();

	Number(Number &n1);
	Number(Number&& n1);

	unsigned int GetBase10Value() const;
	bool operator < (const Number& otherNumber);
	bool operator > (const Number& otherNumber);
	bool operator <= (const Number& otherNumber);
	bool operator >= (const Number& otherNumber);
	bool operator == (const Number& otherNumber);
	char operator [] (int index);
	friend Number operator+ (const Number& n1,const Number& n2);
	friend Number operator- (const Number& n1,const Number& n2);
	Number& operator= (Number&& othernumber);
	Number& operator --();
	Number operator --(int);
	Number(const int n);
	Number& operator =(const char* s);
	Number& operator +=(const Number& otherNumber);


	// add operators and copy/move constructor

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase() const; // returns the current base
};
