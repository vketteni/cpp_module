#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm",
	ROBOTOMY_SIGN, ROBOTOMY_EXECUTE), _target(target)
{
	debug("Parameterized constructer called.");
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	debug("Destructor called.");
}

void RobotomyRequestForm::action(const Bureaucrat &bureaucrat) const
{
	debug("action called.");
	(void) bureaucrat;

	std::cout
		<< "ZZZZZzzz" << std::endl
		<< "ZZZzzzzzzzzzzzzzZZZZZZZ.." << std::endl;
	std::srand(std::time(0));
	int random = std::rand();
	if (random % 2 == 0)
	{
		std::cout
			<< "BZZZZT!.."
			<< "KRRSHHH!.."
			<< "WHIRRR... SNAP!" <<std::endl
			<< "Every Robotomy carries its own set of risks, Sir. Unfortunately, we're sorry to report that your robot didn't make it. Refunds are, of course, not part of the package. Thank you for your understanding. Have a nice day!" << std::endl;
	}
	else
	{
		std::cout
			<< "Good news! "
			<< this->_target
			<< "'s Robotomy was a success." << std::endl;
	}
}
