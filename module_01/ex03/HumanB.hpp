#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <cstring>

class HumanB {
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB();
    HumanB(const std::string& name);
    HumanB(const HumanB& other);
    HumanB& operator=(const HumanB& other);
    ~HumanB();

    Weapon getWeapon();
    void setWeapon(Weapon& weapon);
    std::string getName() const;
    void setName(const std::string& name);

    void    attack();
};

#endif // HumanB_HPP
