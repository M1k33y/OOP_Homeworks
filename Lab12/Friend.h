#include <exception>
#include <string>
using namespace std;

#ifndef __Friend_h__
#define __Friend_h__

#include "Contact.h"

// class Contact;
class Friend;

class Friend: public Contact
{
	private: string _dateOfBirth;
	private: string _phoneNumber;
	private: string _address;

	public: void setDateOfBirth(string aNewDateOfBirth);
};

#endif
