#include <string>
using namespace std;

#ifndef __Colleague_h__
#define __Colleague_h__

#include "Contact.h"

// class Contact;
class Colleague;

class Colleague: public Contact
{
	private: string _phoneNumber;
	private: string _company;
	private: string _address;
};

#endif
