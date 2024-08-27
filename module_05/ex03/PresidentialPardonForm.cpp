#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", PARDON_SIGN, PARDON_EXECUTE), _target(target)
{
	debug("Parameterized constructer called.");
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	debug("Destructor called.");
}

void PresidentialPardonForm::action(const Bureaucrat &bureaucrat) const
{
	debug("action called.");
	(void) bureaucrat;

	std::cout
		<< "Intergalactic overlord Zaphod Beeblebrox hereby pardon's "
		<< this->_target
		<< " of his pancake stealing crimes."
		<< std::endl;
}
