#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	public:

	Contact(std::string	firstName, std::string	lastName,
	std::string	nickname, std::string	phoneNumber, std::string	darkestSecret);
	// ~Contact(void);
	std::string save_contact_field(void);

	private:

	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
};

#endif
