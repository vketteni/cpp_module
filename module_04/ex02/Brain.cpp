#include "Brain.hpp"

Brain::Brain()
{
	debug("Default constructor called.")
}

Brain::Brain(const Brain &other)
{
	debug("Copy constructor called.")
	*this = other;	
}

Brain &Brain::operator=(const Brain &other)
{
	debug("Assignment constructor called.")
	if (this == &other)
		return *this;
	for (int i = 0; i < BRAIN_SIZE; i++) {
		this->ideas[i] = other.ideas[i];	
	}
	return *this;
}


Brain::~Brain()
{
	debug("Destructor called.")
}
