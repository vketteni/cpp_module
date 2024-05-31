#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <cstring>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon weapon;

public:
    HumanB();
    HumanB(std::string name);
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
