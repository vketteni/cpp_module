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
    Weapon(Weapon& other);
    Weapon& operator=(Weapon& other);
    ~Weapon();

    std::string getType() const;
    void setType(const std::string& type);
};

#endif // WEAPON_HPP
