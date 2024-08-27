#include "Intern.hpp"

int	main(void)
{
	Intern someRandomIntern;
	AForm* rrf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	Bureaucrat theOffice("michael", 1);

	theOffice.signForm(*rrf);
	theOffice.executeForm(*rrf);

	delete rrf;
}