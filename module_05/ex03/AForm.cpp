#include "AForm.hpp"

AForm::AForm() : _name(""), _grade_sign(0), _grade_execute(0), _signed(false)
{
	debug("Default constructor called.");
}

AForm::AForm(const AForm &other) : _name(other._name),
	_grade_sign(other._grade_sign), _grade_execute(other._grade_execute),
	_signed(other._signed)
{
	debug("Copy constructor called.");
}
/* 
AForm &AForm::operator=(const AForm &other)
{
	debug("Assignment constructor called.");
	if (this != &other)
	{
		*this = AForm(other);
	}
	return (*this);
}
 */
AForm::AForm(const std::string name, const unsigned int grade_sign,
	const unsigned int grade_execute) : _name(name), _grade_sign(grade_sign),
	_grade_execute(grade_execute), _signed(false)
{
	debug("Parameterized constructor called.");
}

AForm::~AForm()
{
	debug("Destructor called.")
}

const std::string AForm::getName() const
{
	return (this->_name);
}

unsigned int AForm::getGradeSign() const
{
	return (this->_grade_sign);
}

unsigned int AForm::getGradeExecute() const
{
	return (this->_grade_execute);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	debug("beSigned called.");
	if (bureaucrat.getGrade() > this->_grade_sign)
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		this->_signed = true;
	}
}

void AForm::execute(Bureaucrat const &executor) const
{
	debug("execute called.")
	if (!this->_signed)
	{
		throw AForm::FormUnsignedException();
	}
	else if (executor.getGrade() > this->_grade_execute)
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		this->action(executor);
	}
}

std::ostream &operator<<(std::ostream &os,
	const AForm::FormUnsignedException &ex)
{
	return (os << ex.what());
}

std::ostream &operator<<(std::ostream &os, const AForm::GradeTooLowException &ex)
{
	return (os << ex.what());
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << obj.getName();
	return (os);
}
