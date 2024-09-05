#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Debug.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  private:
	const std::string	_name;
	const unsigned int	_grade_sign;
	const unsigned int	_grade_execute;
	bool				_signed;
	Form();
	Form & operator=(const Form & other);
	Form(const Form & other);

  public:
	Form(const std::string name, const unsigned int grade_sign, const unsigned int grade_execute);
	~Form();

	const std::string	getName() const;
	unsigned int	getGradeSign() const;
	unsigned int	getGradeExecute() const;
	bool			getSigned() const;
	void				beSigned(const Bureaucrat & bureaucrat);

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				debug("GradeTooLowException called.")
				return "Grade is too low!";
			} 
	};
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				debug("GradeTooHighException called.")
				return "Grade is too high!";
			} 
	};
};

std::ostream &operator<<(std::ostream & os, const Form &obj);
std::ostream &operator<<(std::ostream & os, const Form::GradeTooHighException & ex);
std::ostream &operator<<(std::ostream & os, const Form::GradeTooLowException & ex);

#endif