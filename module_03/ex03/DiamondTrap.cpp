#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	ClapTrap::set_name(ClapTrap::get_name() + "_clap_name");
	ClapTrap::set_hitpoints(FragTrap::get_hitpoints());
	ClapTrap::set_energypoints(ScavTrap::get_energypoints());
	ClapTrap::set_attackdamage(FragTrap::get_attackdamage());
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) 
{
	ClapTrap::set_name(name + "_clap_name");
	ClapTrap::set_hitpoints(FragTrap::get_hitpoints());
	ClapTrap::set_energypoints(ScavTrap::get_energypoints());
	ClapTrap::set_attackdamage(FragTrap::get_attackdamage());
	//	Initialize attributes with the provided string
	std::cout << "DiamondTrap: Parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : FragTrap(other)
{
	//	Copy each attribute from the 'other' object
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
	{
		return (*this);
	}
	this->set_name(other.get_name());
	this->set_hitpoints(other.get_hitpoints());
	this->set_energypoints(other.get_energypoints());
	this->set_attackdamage(other.get_attackdamage());
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap: It's me! DiamondPeppy - Official title: " << ClapTrap::get_name() << std::endl;
}

void DiamondTrap::guardGate()
{
	if (get_energypoints() > 0 && get_hitpoints() > 0)
	{
		set_energypoints(get_energypoints() - 10);
		std::cout << "DiamondTrap: GuardGate called. DiamondTrap is now in Gatekeeper mode." << std::endl;
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

void DiamondTrap::highFivesGuys()
{
	if (get_energypoints() > 0 && get_hitpoints() > 0)
	{
		set_energypoints(get_energypoints() - 10);
		std::cout << "DiamondTrap: highFivesGuys called. DiamondTrap requests high five." << std::endl;
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

