#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Debug.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string name, const unsigned int grade_sign, const unsigned int grade_execute);
		~AForm();

		const std::string	getName() const;
		unsigned int		getGradeSign() const;
		unsigned int		getGradeExecute() const;
		bool				getSigned() const;
		
		void				beSigned(const Bureaucrat & bureaucrat);
		void				execute(Bureaucrat const & executor) const;
		
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				debug("GradeTooLowException called.")
				return "Grade is too low!";
			} 
	};
	class FormUnsignedException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				debug("FormUnsignedException called.")
				return "Unsigned form!";
			} 
	};

	protected:
		const std::string	_name;
		const unsigned int	_grade_sign;
		const unsigned int	_grade_execute;
		bool				_signed;
		virtual void		action(const Bureaucrat & bureaucrat) const = 0;

	private:
		AForm();
		AForm & operator=(const AForm & other);
		AForm(const AForm & other);

};

std::ostream &operator<<(std::ostream & os, const AForm &obj);
std::ostream &operator<<(std::ostream & os, const AForm::FormUnsignedException & ex);
std::ostream &operator<<(std::ostream & os, const AForm::GradeTooLowException & ex);

#endif