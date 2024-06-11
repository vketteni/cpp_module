#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    // TODO: Initialize attributes with the provided string
    std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    // TODO: Copy each attribute from the 'other' object
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this == &other) {
        return *this;
    }

    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    // TODO: Free existing resources and copy each attribute from the 'other' object

    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    // TODO: Clean up any allocated resources
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    // TODO: Implement attack
    
    std::cout << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    // TODO: Implement attack

    _hitPoints -= amount;
    std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    // TODO: Implement attack
    _hitPoints += amount;
    std::cout << _name << " repairs itself by " << amount << " points of hit points!" << std::endl;
}

const std::string& ClapTrap::get_name() const {
    return _name;
}

void ClapTrap::set_name(const std::string& _name) {
    this->_name = _name;
}

unsigned int ClapTrap::get_hitpoints() const {
    return _hitPoints;
}

void ClapTrap::set_hitpoints(const unsigned int& _hitPoints) {
    this->_hitPoints = _hitPoints;
}

unsigned int ClapTrap::get_energypoints() const {
    return _energyPoints;
}

void ClapTrap::set_energypoints(const unsigned int& _energyPoints) {
    this->_energyPoints = _energyPoints;
}

unsigned int ClapTrap::get_attackdamage() const {
    return _attackDamage;
}

void ClapTrap::set_attackdamage(const unsigned int& _attackDamage) {
    this->_attackDamage = _attackDamage;
}

