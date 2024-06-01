#include "HumanB.hpp"

HumanB::HumanB() : name("default"), weapon(0) {}

HumanB::HumanB(const std::string& name) : name(name), weapon(0) {}

HumanB::HumanB(const HumanB& other) : name(other.name), weapon(other.weapon) {}

HumanB& HumanB::operator=(const HumanB& other) {
    if (this == &other) {
        return *this;
    }

    // TODO: Free existing resources and copy each attribute from the 'other' object

    // std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

HumanB::~HumanB() {
    // TODO: Clean up any allocated resources
    // delete weapon;
    // std::cout << "Destructor called" << std::endl;
}

Weapon HumanB::getWeapon() {
    return *weapon;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
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
