#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	debug("Default constructor called.")
	for (int i = 0; i < TEMPLATE_SIZE; i++) {
			this->templates[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	debug("Copy constructor called.")
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	debug("Assignment constructor called.")
	if (this != &other)
	{
		for (int i = 0; i < TEMPLATE_SIZE; i++) {
			this->templates[i] = other.templates[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{

	debug("Destructor called.")
	for (int i = 0; i < TEMPLATE_SIZE; i++) {
		if (this->templates[i])
			delete this->templates[i];
	}
}

void MateriaSource::learnMateria(AMateria *temp)
{
	debug("learnMateria called.")
	if (!temp)
		return ;
	for (int i = 0; i < TEMPLATE_SIZE; i++) {
		if (this->templates[i] == NULL) {
			try {
				this->templates[i] = temp;
			}
			catch (const std::bad_alloc & e) {
				std::cerr << "Memory allocation failed: " << e.what() << std::endl;
				this->templates[i] = NULL;
			}
			break;
		}
		if (i == TEMPLATE_SIZE - 1) {
			std::cout << "All template slots taken." << std::endl;
		}
	}
	return ;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	debug("createMateria called.")
	for (int i = 0; i < TEMPLATE_SIZE; i++) {
		AMateria *temp = this->templates[i];
		if (!temp)
			break;
		if (temp->getType() == type) {
			return temp->clone();
		}
	}
	return NULL;
}
