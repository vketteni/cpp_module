#include "PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook() : num_contacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::search() {
    const int width = 10;

    std::cout << std::setw(width) << "Index" << "|"
              << std::setw(width) << "First Name" << "|"
              << std::setw(width) << "Last Name" << "|"
              << std::setw(width) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < PHONEBOOK_SIZE; ++i) {
        std::string firstName = truncateString(contacts[i].getFirstName(), width - 1);
        std::string lastName = truncateString(contacts[i].getLastName(), width - 1);
        std::string nickname = truncateString(contacts[i].getNickname(), width - 1);

        std::cout << std::setw(width) << std::right << i << "|"
                  << std::setw(width) << std::right << firstName << "|"
                  << std::setw(width) << std::right << lastName << "|"
                  << std::setw(width) << std::right << nickname << "|"
                  << std::endl;
    }

    std::cout << std::endl << "Enter Index to continue..." << std::endl;

    int index;
    while (!(std::cin >> index) || index < 0 || index >= PHONEBOOK_SIZE || !contacts[index].isValid()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index. Please enter a valid index: ";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    clear_screen();
    std::cout << std::setw(width) << std::left << "First Name" << std::endl
              << std::setw(width) << contacts[index].getFirstName() << std::endl
              << std::setw(width) << std::left << "Last Name" << std::endl
              << std::setw(width) << contacts[index].getLastName() << std::endl
              << std::setw(width) << std::left << "Nickname" << std::endl
              << std::setw(width) << contacts[index].getNickname() << std::endl
              << std::setw(width) << std::left << "Phone Number" << std::endl
              << std::setw(width) << contacts[index].getPhoneNumber() << std::endl
              << std::setw(width) << std::left << "Dark Secret" << std::endl
              << std::setw(width) << contacts[index].getDarkSecret() << std::endl;

    std::cout << std::endl << "Press Enter to end search..." << std::endl;
    std::cin.get();
}

std::string PhoneBook::getInput(std::string option)
{
	std::string input;

	while (1) {
		std::cout << ">> ";
		std::getline(std::cin, input);
		if (option.compare("digit") == 0) {
			if (isDigitString(input)) return (input);
		} else {
			if (isAlphaNumString(input)) return (input);
		}
		std::cout << "Invalid input. Check your answer again." << std::endl;
	}
}

void PhoneBook::add(Contact& contact)
{
	int	i;

	i = 0;
	while (i < PHONEBOOK_SIZE - 1 && contacts[i].isValid())
		i++;
	this->contacts[i] = contact;
}

void PhoneBook::add()
{
	Contact	newContact;
	std::string input;

	newContact = Contact();
	clear_screen();
	std::cout << "Enter first name:" << std::endl;
	input = getInput("alphanum");
	newContact.setFirstName(input);
	clear_screen();
	std::cout << "Enter last name:" << std::endl;
	input = getInput("alphanum");
	newContact.setLastName(input);
	clear_screen();
	std::cout << "Enter phone number:" << std::endl;
	input = getInput("digit");
	newContact.setPhoneNumber(input);
	clear_screen();
	std::cout << "Enter nickname:" << std::endl;
	input = getInput("alphanum");
	newContact.setNickname(input);
	clear_screen();
	std::cout << "Enter dark secret:" << std::endl;
	input = getInput("alphanum");
	newContact.setDarkSecret(input);
	clear_screen();
	newContact.setValid(true);
	add(newContact);
}
