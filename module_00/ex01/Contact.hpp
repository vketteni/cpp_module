#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
//		first name, last name, nickname, phone number, and darkest secret
class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string dark_secret;
	int phone_number;

  public:
	Contact(std::string fn, std::string ln, std::string nn, std::string ds,
		int p);
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
	int getPhoneNumber() const;
	void setPhoneNumber(int pn);
	void	displayContact() const;
};

#endif