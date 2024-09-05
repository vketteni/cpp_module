#include "Dog.hpp"

Dog::Dog()
{
	debug("Default constructor called.")
	
	type = "Dog";
}

Dog::Dog(const Dog &other)
{
	debug("Copy constructor called.")
	
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	debug("Assignment constructor called.")
	if (this == &other)
		return (*this);
	this->type = other.type;
	return *this;
}

Dog::~Dog()
{
	debug("Destructor called.")
}

std::string Dog::getType() const
{
	debug("getType called.")
	return this->type;
}

void Dog::makeSound() const
{
	debug("makeSound called.")
	std::cout <<  "Wuffwufff.." << std::endl;
}
