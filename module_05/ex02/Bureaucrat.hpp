#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Debug.hpp"
#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	public:
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat & other);
		Bureaucrat & operator=(const Bureaucrat & other);
		~Bureaucrat();

		void				incrementGrade();
		void				decrementGrade();
		const std::string	getName() const;
		unsigned int		getGrade() const;
		void				signForm(AForm &form);
		void				executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				debug("GradeTooHighException called.")
				return "Grade is too high!";
			}
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				debug("GradeTooLowException called.")
				return "Grade too low!";
			}
		};

	private:
		const std::string	_name;
		unsigned int		_grade;
		Bureaucrat();

};


std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
std::ostream& operator<<(std::ostream& os, const Bureaucrat::GradeTooHighException& ex);
std::ostream& operator<<(std::ostream& os, const Bureaucrat::GradeTooLowException& ex);

#endif