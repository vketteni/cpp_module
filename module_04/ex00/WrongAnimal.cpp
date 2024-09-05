#include "WrongAnimal.hpp"
#include "Debug.hpp"

WrongAnimal::WrongAnimal() : type("")
{
	debug("Default constructor called.")
}

WrongAnimal::~WrongAnimal()
{
	debug("Destructor called.")
}

void WrongAnimal::makeSound() const
{
	debug("makeSound called.")
	std::cout <<  "Weeuuhaaoofffrrrr.." << std::endl;
}

std::string WrongAnimal::getType() const
{
	debug("getType called.")
	return this->type;
}
