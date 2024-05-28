#include <iostream>
#include <string>

int	main(void) {
	std::string		stringConstant = "HI THIS IS BRAIN";
	std::string*	stringPointer = &stringConstant;
	std::string&	stringReference = stringConstant;

	std::cout << &stringConstant << std::endl;
	std::cout << stringPointer << std::endl;
	std::cout << &stringReference << std::endl;

	std::cout << stringConstant << std::endl;
	std::cout << *stringPointer << std::endl;
	std::cout << stringReference << std::endl;
}