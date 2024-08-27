#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXECUTE), _target(target)
{
	debug("Parameterized constructer called.");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	debug("Destructor called.");
}

void ShrubberyCreationForm::action(const Bureaucrat &bureaucrat) const
{
	debug("action called.");
	(void) bureaucrat;
	saveAsciiTreeToFile(this->_target + "_shrubbery");
}

void ShrubberyCreationForm::saveAsciiTreeToFile(const std::string &filename) const
{
	std::string asciiTree =
		"       *\n"
		"      ***\n"
		"     *****\n"
		"    *******\n"
		"   *********\n"
		"  ***********\n"
		" *************\n"
		"      |||\n";
	std::ofstream outFile(filename.c_str());

	if (outFile.is_open())
	{
		outFile << asciiTree;
		outFile.close();
	}
	else
	{
		std::cerr << "Error" << std::endl;
	}
}
