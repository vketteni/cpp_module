#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <limits>
#include <sstream>

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;
	int			option;

	while (true)
	{
		clear_screen();
		std::cout
			<< "Welcome, enter next command option:" << std::endl
			<< "1. Add contact" << std::endl
			<< "2. Search contacts" << std::endl
			<< "3. Exit" << std::endl;
		std::getline(std::cin, input);
		std::istringstream iss(input);
		iss >> option;
		switch (static_cast<PhoneBook::Option>(option)) {
				case (PhoneBook::ADD):
					clear_screen();
					phonebook.add();
					break;
				case (PhoneBook::SEARCH):
					clear_screen();
					phonebook.search();
					break;
				default:
					break;
		}
		if (static_cast<PhoneBook::Option>(option) == PhoneBook::EXIT)
			break;
	}
}