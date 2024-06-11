#ifndef	PHONEBOOK_HPP
#define	PHONEBOOK_HPP

# define PHONEBOOK_SIZE 8

#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

class PhoneBook
{
	public:
		enum Option {
							ADD = 1,
							SEARCH,
							EXIT
		};
	private:
		Contact 			contacts[PHONEBOOK_SIZE];
		int					num_contacts;
		void				add(Contact& contact);
		std::string			getInput(std::string option);
	public:
		PhoneBook();
		~PhoneBook();
		void				search();
		void				add();
};

bool						isAlphaNumString(std::string input);
bool						isDigitString(std::string input);
std::string 				truncateString(const std::string& str, std::size_t maxLength);
void						clear_screen();

#endif