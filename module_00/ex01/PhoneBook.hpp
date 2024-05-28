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
		Contact contacts[PHONEBOOK_SIZE];
		int		num_contacts;
	public:
		PhoneBook();
		void	search();
		void	add();
};

std::string truncateString(const std::string& str, std::size_t maxLength);
void	clear_screen();

#endif