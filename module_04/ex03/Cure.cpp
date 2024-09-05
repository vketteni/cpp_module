#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	debug("Default constructor called.")
}

Cure::Cure(std::string const &type) : AMateria(type)
{
	debug("Parametized constructor called.")
}

Cure::Cure(const Cure &copy) : AMateria("ice")
{
	debug("Copy constructor called.")
	*this = copy;
}

Cure &Cure::operator=(const Cure &other)
{
	debug("Assignment constructor called.")
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Cure::~Cure()
{
	debug("Destructor called.")
}

AMateria *Cure::clone() const
{
	debug("clone called.")
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	debug("use called.")
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
