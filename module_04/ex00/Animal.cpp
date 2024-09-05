#include "Animal.hpp"
#include "Debug.hpp"

Animal::Animal() : type("")
{
	debug("Default constructor called.")
}

Animal::Animal(const Animal &other)
{
	debug("Copy constructor called.")
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	debug("Copy constructor called.")
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	debug("Destructor called.")
}

void Animal::makeSound() const
{
	debug("makeSound called.")
	std::cout <<  "Weeuuhaaoofffrrrr.." << std::endl;
}

std::string Animal::getType() const
{
	debug("getType called.")
	return this->type;
}


