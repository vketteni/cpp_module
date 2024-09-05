#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->set_hitpoints(100);
	this->set_energypoints(100);
	this->set_attackdamage(30);
	std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	this->set_hitpoints(100);
	this->set_energypoints(100);
	this->set_attackdamage(30);
	//	Initialize attributes with the provided string
	std::cout << "FragTrap: Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	//	Copy each attribute from the 'other' object
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this == &other)
	{
		return (*this);
	}
	this->set_name(other.get_name());
	this->set_hitpoints(other.get_hitpoints());
	this->set_energypoints(other.get_energypoints());
	this->set_attackdamage(other.get_attackdamage());
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (get_energypoints() > 0 && get_hitpoints() > 0)
	{
		set_energypoints(get_energypoints() - 10);
		std::cout << "ScavTrap: highFivesGuys called. FragTrap requests high five." << std::endl;
	}
	else if (get_hitpoints() <= 0)
	{
		std::cout << "Arggh ohhwuhh.." << std::endl;
	}
	else
	{
		std::cout << "Phew I'm out of energy points.." << std::endl;
	}
}
