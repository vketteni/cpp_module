#include "Iter.hpp"

void	print(std::string & s)
{
	std::cout << s << std::endl;
}

void	add_p(std::string & s)
{
	s.append("p");
}

int	main(void)
{
	std::string arr[3];
	arr[0] = std::string("jum");
	arr[1] = std::string("loo");
	arr[2] = std::string("swoo");

	iter(arr, 3, print);
	iter(arr, 3, add_p);
	iter(arr, 3, print);
}

