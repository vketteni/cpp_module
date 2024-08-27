#include "Intern.hpp"

AForm *Intern::makePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::map<std::string, AForm *(Intern::*)(std::string)> forms;
	forms["presidental pardon"] = &Intern::makePardon;
	forms["robotomy request"] = &Intern::makeRobotomy;
	forms["shrubbery creation"] = &Intern::makeShrubbery;

	if (forms.find(name) != forms.end())
	{
		std::cout << "Intern creates " << name << "." << std::endl;
		return (this->*forms[name])(target);
	}
	std::cerr << "Form type " << name << " not recognized." << std::endl;
	return NULL;		
}
