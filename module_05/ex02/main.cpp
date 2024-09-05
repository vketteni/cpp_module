#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	{
		Bureaucrat animal_lover("Lilly", 145);
		Bureaucrat tree_hugger("Hugo", 137);
		ShrubberyCreationForm shrubbery("peanut");
		
		header("Shrubbery test");
		try {
			shrubbery.execute(animal_lover);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
		try {
			shrubbery.beSigned(animal_lover);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
		try {
			shrubbery.execute(animal_lover);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
		try {
			shrubbery.execute(tree_hugger);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
	}
	newLine();
	{
		Bureaucrat small_fry("Bob", 72);
		Bureaucrat high_up("Zaphod Beeblebrox", 45);
		RobotomyRequestForm robotomy("peanut");

		header("Robotomy test");
		try {
			robotomy.execute(small_fry);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
		try {
			robotomy.beSigned(small_fry);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
		try {
			robotomy.execute(small_fry);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
		try {
			robotomy.execute(high_up);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
	}
	newLine();
	{
		Bureaucrat advisor("Bob", 25);
		Bureaucrat president("Zaphod Beeblebrox", 5);
		PresidentialPardonForm pardon("peanut");

		header("Pardon test");
		try {
			pardon.execute(advisor);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
		try {
			pardon.beSigned(advisor);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
		try {
			pardon.execute(advisor);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
		try {
			pardon.execute(president);
		}
		catch ( std::exception & e) {
			debug(e.what());
		}
	}
	newLine()
	{
		Bureaucrat advisor("Bob", 25);
		Bureaucrat president("Zaphod Beeblebrox", 5);
		PresidentialPardonForm pardon("peanut");
		header("executeForm Test")

		advisor.executeForm(pardon);
		advisor.signForm(pardon);

		advisor.executeForm(pardon);
		president.executeForm(pardon);
	}
}