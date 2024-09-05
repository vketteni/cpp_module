#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	debug("Default constructor called.")
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	debug("Parameterized constructor called.")
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade())
{
	debug("Copy constructor called.")
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &other)
{
	debug("Assignment constructor called.")
	if (this != &other)
	{
		this->_grade = other.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	debug("Destructor called.")
}

void Bureaucrat::incrementGrade()
{
	debug("incrementGrade called.")
	if (_grade <= 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	debug("decrementGrade called.")
	if (_grade >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat::GradeTooHighException &ex)
{
	return os << ex.what();
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat::GradeTooLowException &ex)
{
	return os << ex.what();
}

void Bureaucrat::signForm(Form &form)
{
	debug("signForm called.");
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	}
	catch (const Form::GradeTooLowException e)
	{
		std::cerr << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}
