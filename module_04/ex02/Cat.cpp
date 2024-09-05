#include "Cat.hpp"

Cat::Cat()
{
	debug("Default constructor called.")
	brain = new Brain();
	type = "Cat";
}

Cat::Cat(const Cat &other)
{
	debug("Copy constructor called.")
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	debug("Assignment constructor called.")
	if (this == &other)
		return (*this);
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	return *this;
}

Cat::~Cat()
{
	debug("Destructor called.")
	delete brain;
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
