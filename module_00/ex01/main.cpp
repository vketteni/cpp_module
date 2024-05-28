#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <limits>

int	main(void)
{
	PhoneBook	phonebook;
	int			option;

	while (true)
	{
		clear_screen();
		std::cout
			<< "Welcome, enter next command option:" << std::endl
			<< "1. Add contact" << std::endl
			<< "2. Search contacts" << std::endl
			<< "3. Exit" << std::endl;
		while (!(std::cin >> option)) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
        }
		switch (option) {
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
		if (option == PhoneBook::EXIT)
			break;
	}


}