#include "../include/PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>

#define PHONEBOOK_EMPTY_MSG "Phonebook is empty."
#define REQUEST_INDEX_MSG "Please provide the index of the contact you are looking for."
#define ERROR_MSG "Invalid Index Number."

PhoneBook::PhoneBook(void) {
	std::cout << "Creating PhoneBook......" << std::endl;
	
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::saveContactToPhoneBook(Contact contact) {
	this->_contacts[contact.getIndex()] = contact;
}

void	PhoneBook::_formatFieldCol(std::string fieldData) {
	if (fieldData.length() > 10)
	{
		std::cout <<  fieldData.substr(0,9);
		std::cout << ".";
	}
	else
		std::cout <<  std::setw(10) << fieldData;

}

void	PhoneBook::_displayAllContacts(void) const {
	int	i = 0;

	std::cout << std::setw(10) <<  "index" << "|"
	<< std::setw(10) << "first name" << "|"
	<< std::setw(10) << "last name" << "|"
	<< std::setw(10) << "nickname" << std::endl;

	if (this->_contacts[i].getIndex() == -1)
	{
		std::cout << PHONEBOOK_EMPTY_MSG << std::endl;
		return ;
	}

	while (i < 8 && this->_contacts[i].getIndex() != -1)
	{
		std::cout <<  std::setw(10) <<  this->_contacts[i].getIndex() << "|";
		PhoneBook::_formatFieldCol(this->_contacts[i].getFirstName());
		std::cout << "|";
		PhoneBook::_formatFieldCol(this->_contacts[i].getLastName());
		std::cout << "|";
		PhoneBook::_formatFieldCol(this->_contacts[i].getNickName());
		std::cout << std::endl;
		i ++;
	}
	return ;
}

void	PhoneBook::searchContact(void) const {
	int searchIndex = -2;
	this->_displayAllContacts();
	std::cout << REQUEST_INDEX_MSG << std::endl;
	std::cin >> searchIndex;
	while (searchIndex < 0 || searchIndex > Contact::getIndexTracker())
	{
		std::cout << ERROR_MSG << std::endl;
		std::cin >> searchIndex;
	}
	std::cout << "Contact Details are as follows" << std::endl;
	std::cout << "first name : " << this->_contacts[searchIndex].getFirstName() << std::endl;
	std::cout << "last name : " << this->_contacts[searchIndex].getLastName() << std::endl;
	std::cout << "nick name : " << this->_contacts[searchIndex].getNickName() << std::endl;
	std::cout << "phone number : " << this->_contacts[searchIndex].getPhoneNumber() << std::endl;
	std::cout << "darkest secret : " << this->_contacts[searchIndex].getDarkestSecret() << std::endl;
}