#include "Animal.hpp"
#include "Debug.hpp"

AAnimal::AAnimal() : type("")
{
	debug("Default constructor called.")
}

AAnimal::AAnimal(const AAnimal& other)
{
	(void)other;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	(void)other;
	return *this;
}

AAnimal::~AAnimal()
{

}

void AAnimal::makeSound() const
{
	debug("makeSound called.")
	std::cout <<  "Weeuuhaaoofffrrrr.." << std::endl;
}

std::string AAnimal::getType() const
{
	debug("getType called.")
	return this->type;
}
