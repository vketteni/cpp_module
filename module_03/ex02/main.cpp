#include "FragTrap.hpp"

int	main(void) {
	FragTrap scav = FragTrap("Vincent");

	scav.highFivesGuys();
	std::cout << "Claptrap energy points: " << scav.get_energypoints() << std::endl;
	
	std::cout << "A little ladybug appears and tackles you: " << std::endl;
	scav.takeDamage(1);
	std::cout << "Claptrap hit points: " << scav.get_hitpoints() << std::endl;

	scav.beRepaired(1);
	std::cout << "Claptrap hit points: " << scav.get_hitpoints() << std::endl;
	std::cout << "Claptrap energy points: " << scav.get_energypoints() << std::endl;

	scav.attack("a little ladybug");
	std::cout << "Claptrap energy points: " << scav.get_energypoints() << std::endl;

	std::cout << "ladybug uses splash:" << std::endl;
	scav.takeDamage(999);
	std::cout << "Claptrap hit points: " << scav.get_hitpoints() << std::endl;

	scav.attack("a little ladybug");
}