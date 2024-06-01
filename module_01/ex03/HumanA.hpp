#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <cstring>
#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(const std::string& name, Weapon& weapon);
    HumanA(const HumanA& other);
    HumanA& operator=(const HumanA& other);
    ~HumanA();

    Weapon getWeapon();
    void setWeapon(Weapon& weapon);
    std::string getName() const;
    void setName(const std::string& name);

    void    attack();
};

#endif // HUMANA_HPP
