#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <sstream>


int	main(int argc, char **argv)
{
    std::string str = "03.0912837123236512313123222222222222222222";
    double d;

    std::istringstream iss(str);
    iss >> d;

    std::cout << "Parsed double: " << d << std::endl;
	
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
	}
}