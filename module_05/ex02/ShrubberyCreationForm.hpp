#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <fstream>
# include "Debug.hpp"
# include "Bureaucrat.hpp"

# define SHRUBBERY_SIGN 145
# define SHRUBBERY_EXECUTE 137

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm();
		void				action(const Bureaucrat & bureaucrat) const;
	
	private:
		const std::string	_target;
		void				saveAsciiTreeToFile(const std::string& filename) const;

};

std::ostream &operator<<(std::ostream & os, const ShrubberyCreationForm &obj);

#endif