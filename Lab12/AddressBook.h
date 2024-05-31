#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __AddressBook_h__
#define __AddressBook_h__

#include "Contact.h"

class Contact;
class AddressBook;

class AddressBook
{
	private: vector<Contact*> contacts;
	public: Contact* _unnamed_Contact_;

	public: bool searchContactByName(string aName);

	public: vector<Contact*> getFriends();

	public: void deleteContactByName(string aName);

	public: void addContact(Contact* aContact);
};

#endif
