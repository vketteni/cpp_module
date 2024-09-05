#include "Cat.hpp"

Cat::Cat()
{
	debug("Default constructor called.")

	type = "Cat";
}

Cat::Cat(const Cat &other)
{
	*this = other;
	debug("Copy constructor called.")
}

Cat &Cat::operator=(const Cat &other)
{
	debug("Assignment constructor called.")

	if (this == &other)
		return (*this);
	this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	debug("Destructor called.")
}

void Cat::makeSound() const
{
	debug("makeSound called.")
	std::cout <<  "Miiaaauu.." << std::endl;
}

std::string Cat::getType() const
{
	debug("getType called.")
	return this->type;
}
