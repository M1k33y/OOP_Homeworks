#include <iostream>
#include <vector>
#include <string>
#include "AddressBook.h"
#include "Acquaintance.h"
#include "Colleague.h"
#include "Contact.h"
#include "ContactType.h"
#include "Friend.h"
using namespace std;


int main()
{
	AddressBook	addressBook;
    Contact* contact1;
    Contact* contact2;
    contact2.nume= "Calinul"
    contact1.nume = "Mihaitza";
    addressBook.addContact(contact1);
    addressBook.addContact(contact2);

    if (addressBook.searchContactByName("Mihaitza")) 
        cout << "Mihaitza apare in contacte" << endl;

}
