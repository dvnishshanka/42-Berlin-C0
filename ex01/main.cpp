#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Contact.cpp"

#define SEARCH "SEARCH"
#define ADD "ADD"
#define EXIT "EXIT"

#define CMD_REQUEST_MSG "DO YOU WANT TO ADD/SEARCH/EXIT?"
#define CMD_ERR_MSG "PLEASE ENTER ADD/SEARCH/EXIT"

// Check whether the string is empty
bool isFieldEmpty (std::string field)
{
	int	i;

	i = 0;
	while (field[i])
	{
		if (field[i] < 8 && field[i] > 13 && field[i] != 13)
			return (false);
		i ++;
	}
	return (true);
}

std::string	validateField(void)
{
	std::string	input;

	std::cin >> input;
	while (isFieldEmpty(input))
	{
		std::cout << "INPUT IS INVALID." << std::endl;
		std::cin >> input;
	}
	return (input);
}

void	addNewContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "first name :" << std::endl;
	firstName = validateField();
	std::cout << "last name :" << std::endl;
	lastName = validateField();
	std::cout << "nickname :" << std::endl;
	nickname = validateField();
	std::cout << "phone number :" << std::endl;
	phoneNumber = validateField();
	std::cout << "darkest secret :" << std::endl;
	darkestSecret = validateField();

	Contact newContact(firstName, lastName, nickname, phoneNumber,darkestSecret);

}



int	main(void)
{
	std::string	cmd;
	// PhoneBook phonebook;

	std::cout << CMD_REQUEST_MSG << std::endl;
	std::cin >>	cmd;
	while (cmd.compare(EXIT) != 0)
	{
		if (cmd.compare(SEARCH) == 0)
		{

		}
		else if (cmd.compare(ADD) == 0)
		{
			addNewContact();
		}
		else
		{
			std::cout << CMD_ERR_MSG << std::endl;
		}
		std::cout << CMD_REQUEST_MSG << std::endl;
		std::cin >>	cmd;
	}
	return (0);
}
