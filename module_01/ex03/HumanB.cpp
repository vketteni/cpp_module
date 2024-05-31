#include "HumanB.hpp"

HumanB::HumanB() : name("default"), weapon("a woobly noodle")
{
	// TODO: Initialize attributes with the provided string
    std::cout << "Parameterized constructor called" << std::endl;
}

HumanB::HumanB(std::string name)
{
    Weapon weapon;
    weapon = Weapon("a woobly noodle");
    this->name = name;
    this->weapon = weapon;
	// TODO: Initialize attributes with the provided string
    std::cout << "Parameterized constructor called" << std::endl;
}

HumanB::HumanB(const HumanB& other) {
    *this = other;
    // TODO: Copy each attribute from the 'other' object
    std::cout << "Copy constructor called" << std::endl;
}

HumanB& HumanB::operator=(const HumanB& other) {
    if (this == &other) {
        return *this;
    }

    // TODO: Free existing resources and copy each attribute from the 'other' object

    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

HumanB::~HumanB() {
    // TODO: Clean up any allocated resources
    std::cout << "Destructor called" << std::endl;
}

Weapon HumanB::getWeapon() {
    return weapon;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = weapon;
}

std::string HumanB::getName() const {
    return name;
}

void HumanB::setName(const std::string& name) {
    this->name = name;
}

void HumanB::attack()
{
    std::cout << this->getName() 
        << " attacks with their " 
        << this->getWeapon().getType() 
        << std::endl;
}
