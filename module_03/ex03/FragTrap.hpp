#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

private:
public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();
    void highFivesGuys();
};

#endif // FRAGTRAP_HPP
