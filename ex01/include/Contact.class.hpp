#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>

class Contact
{
	public:

	Contact(void);
	~Contact(void);
	void	setContactDetails(void);

	// getters
	int		getIndex(void) const;
	std::string		getFirstName(void) const;
	std::string		getLastName(void) const;
	std::string		getNickName(void) const;
	std::string		getPhoneNumber(void) const;
	std::string		getDarkestSecret(void) const;
	static int		getIndexTracker(void);

	private:

	static int	_sIndex;
	int	_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

};

#endif
