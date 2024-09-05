#include "Animal.hpp"
#include "Debug.hpp"

Animal::Animal() : type("")
{
	debug("Default constructor called.")
}

Animal::Animal(const Animal& other)
{
	(void)other;
}

Animal& Animal::operator=(const Animal& other)
{
	(void)other;
	return *this;
}

Animal::~Animal()
{

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
