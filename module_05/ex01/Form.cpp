#include "Form.hpp"

Form::Form() : _name(""), _grade_sign(0), _grade_execute(0), _signed(false)
{
	debug("Default constructor called.");
}

Form::Form(const Form &other) : _name(other._name),
	_grade_sign(other._grade_sign), _grade_execute(other._grade_execute),
	_signed(other._signed)
{
	debug("Copy constructor called.");
}

Form &Form::operator=(const Form &other)
{
	debug("Assignment constructor called.") if (this != &other)
	{
		*this = Form(other);
	}
	return (*this);
}

Form::Form(const std::string name, const unsigned int grade_sign,
	const unsigned int grade_execute) : _name(name), _grade_sign(grade_sign),
	_grade_execute(grade_execute), _signed(false)
{
	debug("Parameterized constructor called.");
}

Form::~Form()
{
	debug("Destructor called.")
}

const std::string Form::getName() const
{
	return (this->_name);
}

unsigned int Form::getGradeSign() const
{
	return (this->_grade_sign);
}

unsigned int Form::getGradeExecute() const
{
	return (this->_grade_execute);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	debug("beSigned called.");
	if (bureaucrat.getGrade() > this->_grade_sign)
	{
		throw Form::GradeTooLowException();
	}
	else
	{
		this->_signed = true;
	}
}

std::ostream &operator<<(std::ostream &os,
	const Form::GradeTooHighException &ex)
{
	return (os << ex.what());
}

std::ostream &operator<<(std::ostream &os, const Form::GradeTooLowException &ex)
{
	return (os << ex.what());
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << obj.getName();
	return (os);
}
