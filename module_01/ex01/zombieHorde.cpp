#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	if (N <= 0) {
		return (NULL);
	}
	Zombie* horde= new Zombie[N];
	int	i = 0;
	while (i < N) {
		horde[i++].setName(name);
	}
	return (horde);
}