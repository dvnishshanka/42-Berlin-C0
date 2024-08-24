/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:09:15 by dnishsha          #+#    #+#             */
/*   Updated: 2024/08/24 13:09:17 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.class.hpp"
#include <iomanip>

bool isFieldEmpty (std::string field);

#define PHONEBOOK_EMPTY_MSG "Phonebook is empty."
#define REQUEST_INDEX_MSG "Please provide the index of the contact you are looking for."
#define ERROR_MSG "Invalid Index Number.Please enter a valid index number."

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

// Check whether the string contains numbers
bool isDigits (std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
		{
			return (false);
		}
		i ++;
	}
	return (true);
}

// Convert String to Numbers
int	strToNum(std::string str)
{
	int	num = 0;
	int	i = 0;

	while (str[i])
	{
		num = num * 10;
		num += str[i] - '0';
		i ++;
	}
	
	return (num);
}

void	PhoneBook::searchContact(void) const {
	std::string	searchIndexStr;
	int searchIndex = -2;

	if (this->_contacts[0].getIndex() == -1)
	{
		std::cout << PHONEBOOK_EMPTY_MSG << std::endl;
		return ;
	}
	this->_displayAllContacts();
	std::cout << REQUEST_INDEX_MSG << std::endl;
	std::getline(std::cin, searchIndexStr);
	if (isDigits(searchIndexStr) && !isFieldEmpty(searchIndexStr))
		searchIndex = strToNum(searchIndexStr);
	while (searchIndex < 0 || searchIndex >= 8 || (searchIndex > (Contact::getIndexTracker() - 1) && (this->_contacts[7].getIndex() == -1)))
	{
		std::cout << ERROR_MSG << std::endl;
		std::getline(std::cin, searchIndexStr);
		searchIndex = strToNum(searchIndexStr);
	}
	std::cout << "Contact Details are as follows" << std::endl;
	std::cout << "first name : " << this->_contacts[searchIndex].getFirstName() << std::endl;
	std::cout << "last name : " << this->_contacts[searchIndex].getLastName() << std::endl;
	std::cout << "nick name : " << this->_contacts[searchIndex].getNickName() << std::endl;
	std::cout << "phone number : " << this->_contacts[searchIndex].getPhoneNumber() << std::endl;
	std::cout << "darkest secret : " << this->_contacts[searchIndex].getDarkestSecret() << std::endl;
}
