#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <cstring>

class Weapon {
private:
    std::string type;

public:
    Weapon();
    Weapon(std::string type);
    Weapon(const Weapon& other);
    Weapon& operator=(const Weapon& other);
    ~Weapon();

    std::string getType() const;
    void setType(const std::string type);
};

#endif // WEAPON_HPP
