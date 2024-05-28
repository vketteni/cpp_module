#include "Zombie.hpp"

int	main(void) {
	int	N = 3;
	Zombie *horde = zombieHorde(N, "Alfredos");

	int	i = 0;
	while (i < N) {
		horde[i].announce();
		i++;
	}
	delete[] horde;
}