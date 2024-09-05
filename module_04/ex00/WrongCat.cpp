#include "WrongCat.hpp"

WrongCat::WrongCat() : type("WrongCat")
{
	debug("Default constructor called.")
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	debug("Copy constructor called.")
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	debug("Assignment constructor called.")

	if (this == &other)
		return (*this);
	this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	debug("Destructor called.")
}

void WrongCat::makeSound() const
{
	debug("makeSound called.")
	std::cout <<  "Miiaaauu.." << std::endl;
}

std::string WrongCat::getType() const
{
	debug("getType called.")
	return this->type;
}
