#include "Zombie.hpp"

int	main(void) {
	Zombie *zombie = newZombie("Herbert");
	zombie->announce();
	delete zombie;
	randomChump("Alfredo");
}