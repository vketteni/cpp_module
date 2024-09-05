#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	debug("Default constructor called.")
}

Ice::Ice(std::string const &type) : AMateria(type)
{
	debug("Parametized constructor called.")
}

Ice::Ice(const Ice &copy) : AMateria("ice")
{
	debug("Copy constructor called.")
	*this = copy;
}

Ice &Ice::operator=(const Ice &other)
{
	debug("Assignment constructor called.")
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
