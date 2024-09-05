#include "AMateria.hpp"

AMateria::AMateria(void)
	: type(""){debug("Default constructor called.")}

		AMateria::AMateria(const std::string &type)
	: type(type){debug("Parametized constructor called.")}

		AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

std::string const &AMateria::getType() const
{
	return (type);
}

AMateria::~AMateria(void)
{
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	debug("use called.")
}
