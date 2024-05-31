#include <string>
using namespace std;

#ifndef __Contact_h__
#define __Contact_h__

#include "ContactType.h"
// #include "AddressBook.h"

// enum ContactType;
class AddressBook;
class Contact;

class Contact
{
	public: string _name;
	public: ContactType _contactType;
	public: AddressBook* _unnamed_AddressBook_;
	public: ContactType* _unnamed_ContactType_;
};

#endif
