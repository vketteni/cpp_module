#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <cstdlib>
# include <ctime>
# include "Debug.hpp"
# include "Bureaucrat.hpp"

# define ROBOTOMY_SIGN 72
# define ROBOTOMY_EXECUTE 45

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();
	
		void		action(const Bureaucrat  & bureaucrat) const;
	private:
		const std::string	_target;

};

std::ostream &operator<<(std::ostream & os, const RobotomyRequestForm &obj);

#endif