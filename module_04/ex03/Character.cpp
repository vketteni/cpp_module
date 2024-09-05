#include "Character.hpp"

Character::Character()
{
	debug("Default constructor called.");
	_name = "default";
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(const std::string name) : _name(name)
{
	debug("Parametized constructor called.");
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	debug("Copy constructor called.");
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	debug("Assignment constructor called.");
	if (this != &other)
	{
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			try
			{
				this->_inventory[i] = other._inventory[i]->clone();
			}
			catch (const std::bad_alloc &e)
			{
				std::cerr << "Memory allocation failed: " << e.what() << std::endl;
				this->_inventory[i] = NULL;
			}
		}
	}
	return (*this);
}

Character::~Character()
{
	debug("Destructor called.");
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

void Character::equip(AMateria *m)
{
	debug("equip called.");
	if (!m)
		return ;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			try
			{
				this->_inventory[i] = m;
			}
			catch (const std::bad_alloc &e)
			{
				std::cerr << "Memory allocation failed: " << e.what() << std::endl;
				this->_inventory[i] = NULL;
			}
			break ;
		}
	}
	return ;
}

void Character::unenquip(int idx)
{
	debug("unequip called.");
	if (idx < 0 || idx > INVENTORY_SIZE - 1)
		return ;
	this->_inventory[idx] = NULL;
	return ;
}

void Character::use(int idx, ICharacter &target)
{
	debug("use called.");
	if (idx < 0 || idx > INVENTORY_SIZE - 1 || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
	return this->_name;
}
