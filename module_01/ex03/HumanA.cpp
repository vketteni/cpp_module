#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}
HumanA::HumanA(const HumanA& other) : name(other.name), weapon(other.weapon) {}

HumanA& HumanA::operator=(const HumanA& other) {
    if (this == &other) {
        return *this;
    }
    this->name = other.name;
    this->weapon = other.weapon;
    // std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

HumanA::~HumanA() {
    // TODO: Clean up any allocated resources
    // std::cout << "Destructor called" << std::endl;
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
