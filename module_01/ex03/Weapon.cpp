#include "Weapon.hpp"

Weapon::Weapon() : type ("") {
    std::cout << "Default constructor called" << std::endl;
}

Weapon::Weapon(std::string type) {
    this->type = type;
    std::cout << "Parameterized constructor called" << std::endl;
}

Weapon::Weapon(Weapon& other) {

    *this = other;
    // std::cout << "Copy constructor called" << std::endl;
}


Weapon& Weapon::operator=(Weapon& other) {
    if (this == &other) {
        return *this;
    }
    this->type = other.type;
    // std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Weapon::~Weapon() {
    // TODO: Clean up any allocated resources
    std::cout << "Destructor called with type " << this->type << std::endl;
}

std::string Weapon::getType() const {
    return type;
}

void Weapon::setType(const std::string& type) {
    this->type = type;
}

