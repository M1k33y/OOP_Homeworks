#include <exception>
#include <string>
#include <vector>
using namespace std;

#include "AddressBook.h"
#include "Contact.h"

bool AddressBook::searchContactByName(string aName) {
	//throw "Not yet implemented";
	for (auto i : contacts)
		if (i->_name == aName)
			return true;
	return false;
}

vector<Contact*> AddressBook::getFriends() {
	//throw "Not yet implemented";
	vector<Contact*> friends;
	for (auto i : contacts)
		if (i->_contactType == ContactType::Friend)
			friends.push_back(i);
	return friends;
}

void AddressBook::deleteContactByName(string aName) 
{
	//throw "Not yet implemented";
	vector<Contact*> newContacts;
	for (int i = 0; i < contacts.size(); i++)
		if (contacts[i]->_name != aName)
			newContacts.push_back(contacts[i]);
	contacts = newContacts;
}

void AddressBook::addContact(Contact* aContact) {
	//throw "Not yet implemented";
	contacts.push_back(aContact);
}

