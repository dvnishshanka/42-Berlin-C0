#include <iostream>
#include <string>

#include "PhoneBook.class.cpp"
#include "Contact.class.cpp"

#define SEARCH "SEARCH"
#define ADD "ADD"
#define EXIT "EXIT"

#define CMD_REQUEST_MSG "Do you want to ADD/SEARCH/EXIT?"
#define CMD_ERR_MSG "Please enter ADD/SEARCH/EXIT."
#define DISPLAY_ERR_MSG "Something went wrong whe displaying phonebook contacts."



int	main(void)
{
	std::string	cmd;
	PhoneBook phonebook;

	std::cout << CMD_REQUEST_MSG << std::endl;
	std::cin >>	cmd;
	while (cmd.compare(EXIT) != 0)
	{
		if (cmd.compare(SEARCH) == 0)
		{
			phonebook.searchContact();
		}
		else if (cmd.compare(ADD) == 0)
		{
			Contact	contact;
			contact.setContactDetails();
			phonebook.saveContactToPhoneBook(contact);
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
