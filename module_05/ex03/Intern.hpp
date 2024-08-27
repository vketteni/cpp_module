#ifndef	INTERN_HPP
#define	INTERN_HPP

# include <string>
# include <map>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		AForm *makeForm(std::string name, std::string target);
	private:
		AForm *makePardon(std::string target);
		AForm *makeRobotomy(std::string target);
		AForm *makeShrubbery(std::string target);		
};

#endif