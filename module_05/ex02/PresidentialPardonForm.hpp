#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Debug.hpp"
# include "Bureaucrat.hpp"

# define PARDON_SIGN 25
# define PARDON_EXECUTE 5

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & other);
		~PresidentialPardonForm();

		void		action(const Bureaucrat & bureaucrat) const;

	private:
		const std::string	_target;
};

std::ostream &operator<<(std::ostream & os, const PresidentialPardonForm &obj);

#endif