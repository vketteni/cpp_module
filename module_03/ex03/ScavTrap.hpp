#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

private:
public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();
    void guardGate();
};

#endif // SCAVTRAP_HPP
