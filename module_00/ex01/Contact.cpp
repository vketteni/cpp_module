#include "Contact.hpp"

// Default constructor
Contact::Contact() : firstName(""), lastName(""), nickname(""), darkSecret(""),
	phoneNumber(0), valid(false)
{
}

// Copy constructor
Contact::Contact(const Contact &other) : firstName(other.firstName),
	lastName(other.lastName), nickname(other.nickname),
	darkSecret(other.darkSecret), phoneNumber(other.phoneNumber), valid(true)
{
}

// Assignment operator constructor
Contact &Contact::operator=(const Contact &other)
{
	if (this != &other)
	{
		firstName = other.firstName;
		lastName = other.lastName;
		nickname = other.nickname;
		darkSecret = other.darkSecret;
		phoneNumber = other.phoneNumber;
		valid = true;
	}
	return (*this);
}

std::string Contact::getFirstName() const
{
	return (firstName);
}
void Contact::setFirstName(std::string n)
{
	firstName = n;
}
std::string Contact::getLastName() const
{
	return (lastName);
}
void Contact::setLastName(std::string n)
{
	lastName = n;
}
std::string Contact::getNickname() const
{
	return (nickname);
}
void Contact::setNickname(std::string n)
{
	nickname = n;
}
std::string Contact::getDarkSecret() const
{
	return (darkSecret);
}
void Contact::setDarkSecret(std::string n)
{
	darkSecret = n;
}
int Contact::getPhoneNumber() const
{
	return (phoneNumber);
}
void Contact::setPhoneNumber(int pn)
{
	phoneNumber = pn;
}

void Contact::setValid(bool v)
{
	valid = v;
}

bool Contact::isValid()
{
	return (this->valid);
}
