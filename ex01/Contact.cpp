#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact(std::string	firstName, std::string	lastName,
	std::string	nickname, std::string	phoneNumber, std::string	darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
	std::cout << "NEW CONTACT CREATED." << std::endl;
}

