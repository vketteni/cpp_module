#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
//		first name, last name, nickname, phone number, and darkest secret
class Contact
{
  private:
	std::string 	firstName;
	std::string 	lastName;
	std::string 	nickname;
	std::string 	darkSecret;
	std::string 	phoneNumber;
	bool		valid;

  public:
	Contact();
	Contact(const Contact& other);
	Contact& operator=(const Contact& other);
	~Contact() {};

	std::string getFirstName() const;
	void setFirstName(std::string n);
	std::string getLastName() const;
	void setLastName(std::string n);
	std::string getNickname() const;
	void setNickname(std::string n);
	std::string getDarkSecret() const;
	void setDarkSecret(std::string n);
	std::string getPhoneNumber() const;
	void setPhoneNumber(std::string pn);
	void setValid(bool v);
	bool isValid();
};

#endif