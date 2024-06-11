#include "Fixed.hpp"
#include <iostream>

int	main(void) {
	Fixed a(2.5f);
	
	std::cout << a.toInt() << std::endl;
	std::cout << a << std::endl;

	return 0;
}