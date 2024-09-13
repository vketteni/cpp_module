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

bool checkLineFormat(const std::string & line)
{
	(void)line;
	return true;
}

bool checkDateFormat(const std::string & date)
{
	(void)date;
	return true;
}

bool checkValueFormate(const std::string & value)
{
	(void)value;
	return true;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Please provide a database as an argument.\n";
		return 1;
	}
	BitcoinExchange b(argv[1]);
	b.printHistory();
}