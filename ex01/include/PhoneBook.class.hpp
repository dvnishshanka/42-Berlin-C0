#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class PhoneBook
{
	public:

	PhoneBook(void);
	~PhoneBook(void);
	void	saveContactToPhoneBook(Contact contact);
	void	searchContact(void) const;


	private:

	Contact	_contacts[8];
	static void	_formatFieldCol(std::string fieldData);
	void	_displayAllContacts(void) const;
};

#endif
