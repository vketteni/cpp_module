#include "PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook() : num_contacts(0) {}

void PhoneBook::search()
{
	Contact *contacts = this->contacts;
	int		width = 10;
	
	std::cout << std::setw(width) << "Index" << "|"
		<< std::setw(width) << "First Name" << "|"
		<< std::setw(width) << "Last Name" << "|"
		<< std::setw(width) << "Nickname" << "|"
		<< std::endl;
	int	i = 0;
	while (i < PHONEBOOK_SIZE) {
		std::string firstName = truncateString(contacts[i].getFirstName(), width - 1);
		std::string lastName = truncateString(contacts[i].getLastName(), width - 1);
		std::string nickname = truncateString(contacts[i].getNickname(), width - 1);
		std::cout << std::setw(width) << std::right << i << "|"
			<< std::setw(width) << std::right << firstName << "|"
			<< std::setw(width) << std::right << lastName << "|"
			<< std::setw(width) << std::right << nickname << "|"
			<< std::endl;
		i++;
	}
	int	index;
	std::cout << std::endl << "Enter Index to continue..." << std::endl;
	std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (index < 0 || index > PHONEBOOK_SIZE - 1 || contacts[index].isValid() == false)
		;
	else {
			clear_screen();
			std::cout << std::setw(width) << std::right << "First Name" << std::endl
			<< std::setw(width) << std::left << contacts[index].getFirstName() << std::endl
			<< std::setw(width) << std::left << "Last Name" << std::endl
			<< std::setw(width) << std::left << contacts[index].getLastName() << std::endl
			<< std::setw(width) << std::left << "Nickname" << std::endl
			<< std::setw(width) << std::left << contacts[index].getNickname() << std::endl
			<< std::setw(width) << std::left << "Phone Number" << std::endl
			<< std::setw(width) << std::left << contacts[index].getPhoneNumber() << std::endl
			<< std::setw(width) << std::left << "Dark Secret" << std::endl
			<< std::setw(width) << std::left << contacts[index].getDarkSecret() << std::endl;
	}

	std::cout << std::endl << "Press Enter to end search..." << std::endl;
	std::cin.get();
}

void PhoneBook::add()
{
	Contact		newContact;
	int			i = 0;
	std::string	textInput;
	int			phoneNumber;

	while (i < PHONEBOOK_SIZE - 1 && contacts[i].isValid())
		i++;
	newContact = contacts[i];
	system("clear");
	std::cout << "Enter first name:" << std::endl;
	std::cin >> textInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	newContact.setFirstName(textInput);
	system("clear");
	std::cout << "Enter last name:" << std::endl;
	std::cin >> textInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	newContact.setLastName(textInput);

	system("clear");
    std::cout << "Enter phone number:" << std::endl;
    while (!(std::cin >> phoneNumber)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid phone number:" << std::endl;
    }

	system("clear");
	std::cout << "Enter nickname:" << std::endl;
	std::cin >> textInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	newContact.setNickname(textInput);

	system("clear");
	std::cout << "Enter dark secret:" << std::endl;
	std::cin >> textInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	newContact.setDarkSecret(textInput);

	newContact.setValid(true);
	this->contacts[i] = newContact;
	system("clear");
}

