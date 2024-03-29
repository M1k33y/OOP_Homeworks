#include "Number.h"
#include <iostream>
#include <cstring>

using namespace std;
	
Number::Number(const char* value, int base)
{
	strNumber = new char[100] {}; //{} ca sa imi initializeze automat cu NULL
	//strNumber = (char*)malloc(100 * sizeof(char)); //sau asa pt baietii cu c
	strcpy(strNumber, value);
	nrBase = base;
	lg = strlen(strNumber);

}

Number::Number(Number& n1)
{
	strNumber = new char[100] {};
	strcpy(strNumber, n1.strNumber);
	nrBase = n1.nrBase;
	lg = n1.lg;
}

Number::Number(Number&& n1)
{
	strNumber = n1.strNumber;
	nrBase = n1.nrBase;
	lg = n1.lg;
}


void Number::Print()
{
	cout << "Numar: " << strNumber << " cu baza " << nrBase<<endl;
}

unsigned int Number::GetBase10Value() const
{
	unsigned int result=0,power=1;
	int i;

	for (i = lg - 1; i >= 0; i--)
	{
		if (strNumber[i] >= '0' && strNumber[i] <=  '9') {
			result = result + (strNumber[i] - '0') * power;
			
		}
		else
		{
			result = result + (strNumber[i] - 'A' + 10) * power;
		}
		power = power * nrBase;
	}
	return result;

}
bool Number::operator < (const Number& otherNumber)
{
	return GetBase10Value() < otherNumber.GetBase10Value();
}
bool Number::operator > (const Number& otherNumber)
{
	return GetBase10Value() > otherNumber.GetBase10Value();
}
bool Number::operator <= (const Number& otherNumber)
{
	return GetBase10Value() <= otherNumber.GetBase10Value();
}
bool Number::operator >= (const Number& otherNumber)
{
	return GetBase10Value() >= otherNumber.GetBase10Value();
}
bool Number::operator == (const Number& otherNumber)
{
	return GetBase10Value() == otherNumber.GetBase10Value();
}
char Number::operator [] (int index )
{
	if(index>=0 &&index<lg)
	return strNumber[index];
}

int Number::GetBase() const
{
	return nrBase;
}
Number& Number::operator +=(const Number& otherNumber)
{

	unsigned int result = 0, p = 1;
	int i = 0, r = 0;
	unsigned int sum = GetBase10Value() + otherNumber.GetBase10Value();
	int bazamax = 0;

	if (GetBase() >= otherNumber.GetBase())
		bazamax = GetBase();
	else
		bazamax = otherNumber.GetBase();

	char aux[100];

	while (sum)
	{
		r = sum % bazamax;
		sum = sum / bazamax;

		if (r <= 9)
			aux[i++] = (char)(r + '0');
		else
			aux[i++] = (char)(r + 'A');

		p = p * 10;
	}
	aux[i] = '\0';
	reverse(aux, aux + i);
	strcpy(strNumber, aux);
	this->nrBase = bazamax;
	return *this;

}
Number operator+ (const Number &n1,const Number &n2)
{

	unsigned int result = 0, p = 1;
	int i = 0, r = 0;
	unsigned int sum = n1.GetBase10Value() + n2.GetBase10Value();
	int bazamax = 0;

	if (n1.GetBase() >= n2.GetBase())
		bazamax = n1.GetBase();
	else
		bazamax = n2.GetBase();

	char aux[100];
	
	while (sum)
	{
		r = sum % bazamax;
		sum = sum / bazamax;

		if (r <= 9)
			aux[i++] = (char)(r + '0');
		else
			aux[i++] = (char)(r + 'A');

		p = p * 10;
	}
	aux[i] = '\0';
	reverse(aux, aux + i);
	
	return Number(aux, bazamax);

}

Number operator- (const Number& n1,const Number& n2)
{

	unsigned int result = 0, p = 1;
	int i = 0, r = 0;
	unsigned int sum = n1.GetBase10Value() - n2.GetBase10Value();
	int bazamax = 0;

	if (n1.GetBase() >= n2.GetBase())
		bazamax = n1.GetBase();
	else
		bazamax = n2.GetBase();

	char aux[100];

	while (sum)
	{
		r = sum % bazamax;
		sum = sum / bazamax;

		if (r <= 9)
			aux[i++] = (char)(r + '0');
		else
			aux[i++] = (char)(r + 'A');

		p = p * 10;
	}
	aux[i] = '\0';
	reverse(aux, aux + i);
	Number n3(aux, bazamax);
	return n3;

}

Number& Number::operator --()
{
	strcpy(this->strNumber, this->strNumber + 1);
	return *this;
}
	
Number Number::operator --(int)
{
	this->strNumber[strlen(this->strNumber) - 1] = '\0';
	return *this;
}
Number& Number::operator= (Number&& othernumber)
{

	if (this != &othernumber) 
	{
		//delete[] strNumber;

		strNumber = othernumber.strNumber;
		nrBase = othernumber.nrBase;
		lg = othernumber.lg;

		//delete[] othernumber.strNumber;
	}

	return *this;

}Number::Number(const int n)
{

	 _itoa(n, this->strNumber, 10);
	 nrBase = 10;
}

Number& Number::operator =(const char* s)
{
	strNumber = new char[100];
	strcpy(this->strNumber, s);
	nrBase = 10;
	return *this;
}

void Number::SwitchBase(int newBase)
{
	
	
	unsigned int sum = this->GetBase10Value();

	unsigned int result = 0, p = 1;
	int i = 0, r = 0;
	int bazamax = 0;
	char aux[100];

	while (sum)
	{
		r = sum % newBase;
		sum = sum / newBase;

		if (r <= 9)
			aux[i++] = (char)(r + '0');
		else
			aux[i++] = (char)(r + 'A');

		p = p * 10;
	}
	aux[i] = '\0';
	reverse(aux, aux + i);
	strcpy(strNumber, aux);
	nrBase = newBase;
}
int  Number::GetDigitsCount()
{
	return lg;
}
Number::~Number() 
{
	//delete[] strNumber;//cu paranteze patrate ca sa nu imi stearga doar ultimul caract
	strNumber = nullptr;
}
