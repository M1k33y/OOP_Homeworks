#include <string>
using namespace std;

#ifndef __Acquaintance_h__
#define __Acquaintance_h__

#include "Contact.h"

// class Contact;
class Acquaintance;

class Acquaintance: public Contact
{
	private: string _phoneNumber;
};

#endif
