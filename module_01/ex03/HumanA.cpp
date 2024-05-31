#include "HumanA.hpp"

HumanA::HumanA(const char *name, Weapon weapon)
{
    this->name = name;
    this->weapon = weapon;
	// TODO: Initialize attributes with the provided string
    std::cout << "Parameterized constructor called" << std::endl;
}

HumanA::HumanA(const HumanA& other) {
    *this = other;
    // TODO: Copy each attribute from the 'other' object
    std::cout << "Copy constructor called" << std::endl;
}

HumanA& HumanA::operator=(const HumanA& other) {
    if (this == &other) {
        return *this;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

HumanA::~HumanA() {
    // TODO: Clean up any allocated resources
    std::cout << "Destructor called" << std::endl;
}

Weapon HumanA::getWeapon() {
    return weapon;
}

void HumanA::setWeapon(Weapon& weapon) {
    this->weapon = weapon;
}

std::string HumanA::getName() const {
    return name;
}

void HumanA::setName(const std::string& name) {
    this->name = name;
}

void HumanA::attack()
{
    std::cout << this->getName() 
        << " attacks with their " 
        << this->getWeapon().getType() 
        << std::endl;
}
