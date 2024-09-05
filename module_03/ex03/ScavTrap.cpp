#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->set_hitpoints(100);
	this->set_energypoints(50);
	this->set_attackdamage(20);
	std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->set_hitpoints(100);
	this->set_energypoints(50);
	this->set_attackdamage(20);

	//	Initialize attributes with the provided string
	std::cout << "ScavTrap: Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	//	Copy each attribute from the 'other' object
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this == &other)
	{
		return (*this);
	}
	this->set_name(other.get_name());
	this->set_hitpoints(other.get_hitpoints());
	this->set_energypoints(other.get_energypoints());
	this->set_attackdamage(other.get_attackdamage());
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	return (*this);
}

void ScavTrap::guardGate()
{
	if (get_energypoints() > 0 && get_hitpoints() > 0)
	{
		set_energypoints(get_energypoints() - 10);
		std::cout << "ScavTrap: GuardGate called. ScavTrap is now in Gatekeeper mode." << std::endl;
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

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
}
