#include "Zombie.hpp"

Zombie::Zombie() : name("default")
{
}

Zombie::~Zombie()
{
	std::cout << this->name << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}