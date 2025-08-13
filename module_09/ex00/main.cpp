#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>

bool	isFile(char *filename)
{
	std::ifstream file(filename);
	return file.is_open();
}

bool	hasFileExtension(const std::string & filename, const std::string & extension)
{
	size_t dotPos = filename.rfind('.');
	if (dotPos == std::string::npos)
	{
		return false;
	}
	std::string fileExtension = filename.substr(dotPos + 1);
	return fileExtension == extension;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	if (!isFile(argv[1]))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange b(argv[1]);
	b.printHistory();
}