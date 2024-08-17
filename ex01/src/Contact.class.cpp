#include "../include/Contact.class.hpp"
#include <cctype>

// Check whether the string contains valid characters
bool isFieldEmpty (std::string field)
{
	int	i;

	i = 0;
	while (field[i])
	{
		if (isalnum(field[i]))
		{
			return (false);
		}
		i ++;
	}
	return (true);
}

std::string	validateField(std::string fieldName)
{
	std::string	input;

	std::cout << fieldName << " :" << std::endl;
	std::cin >> input;
	std::cout << input;
	while (isFieldEmpty(input))
	{
		std::cout << "Input is invalid. It should contain atleast one letter/number." << std::endl;
		std::cout << fieldName << " :" << std::endl;
		std::cin >> input;
	}
	return (input);
}


void	Contact::setContactDetails(void)
{
	this->_index = Contact::_sIndex;
	this->_firstName = validateField("first name");
	this->_lastName  = validateField("last name");
	this->_nickname  = validateField("nickname");
	this->_phoneNumber  = validateField("phone number");
	this->_darkestSecret  = validateField("darkest secret");
	if (Contact::_sIndex == 7)
		Contact::_sIndex = 0;
	else
		Contact::_sIndex ++;
	return ;
}

Contact::Contact(void) {}

Contact::~Contact(void) {}

// getters

int		Contact::getIndex(void) const {
	return (this->_index);
}

std::string		Contact::getFirstName(void) const {
	return (this->_firstName);
}

std::string		Contact::getLastName(void) const {
	return (this->_lastName);
}

std::string		Contact::getNickName(void) const {
	return (this->_nickname);
}

std::string		Contact::getPhoneNumber(void) const {
	return (this->_phoneNumber);
}

std::string		Contact::getDarkestSecret(void) const {
	return (this->_darkestSecret);
}

int		Contact::getIndexTracker(void) {
	return (Contact::_sIndex);
}


int Contact::_sIndex = 0;