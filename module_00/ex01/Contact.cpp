#include "Contact.hpp"

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string ds,
	int p) : first_name(fn), last_name(ln), nickname(nn), dark_secret(ds),
		phone_number(p) {}

Contact::Contact(const Contact &other) : first_name(other.first_name), last_name(other.last_name), nickname(other.nickname), dark_secret(other.dark_secret),
		phone_number(other.phone_number) {}

Contact &Contact::operator=(const Contact &other)
{
	if (this != &other)~
	{
		first_name = other.first_name;
		last_name = other.last_name;
		nickname = other.nickname;
		dark_secret = other.dark_secret;
		phone_number = other.phone_number;
	}
	return (*this);
}

std::string Contact::getFirstName() const
{
	return (std::string());
}
void Contact::setFirstName(std::string n)
{
	first_name = n;
}
std::string Contact::getLastName() const
{
	return (last_name);
}
void Contact::setLastName(std::string n)
{
	last_name = n;
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
	return (dark_secret);
}
void Contact::setDarkSecret(std::string n)
{
	dark_secret = n;
}
int Contact::getPhoneNumber() const
{
	return (phone_number);
}
void Contact::setPhoneNumber(int pn)
{
	phone_number = pn;
}
void Contact::displayContact() const
{
	std::cout << "TODO" << std::endl;
}
