#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstring>

class ClapTrap {
private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    const std::string& get_name() const;
    void set_name(const std::string& _name);
    unsigned int get_hitpoints() const;
    void set_hitpoints(const unsigned int& _hitPoints);
    unsigned int get_energypoints() const;
    void set_energypoints(const unsigned int& _energyPoints);
    unsigned int get_attackdamage() const;
    void set_attackdamage(const unsigned int& _attackDamage);
};

#endif // CLAPTRAP_HPP
