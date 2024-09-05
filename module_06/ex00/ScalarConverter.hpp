#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <string>
# include <map>
# include <climits>
# include <limits>
# include <cerrno>
# include <cstdlib>
# include <cmath>
# include "Debug.hpp"

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SCIENCE,
	NUM_TYPES
};

class ScalarConverter {
	private:
		ScalarConverter();
	public:
		static void convert(std::string literal);
};

#endif