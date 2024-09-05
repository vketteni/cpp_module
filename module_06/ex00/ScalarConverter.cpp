#include "ScalarConverter.hpp"

bool isFractionalPartTooSmallDouble(const std::string &s) {

    double parsedValue;

    std::istringstream iss(s);
    iss >> parsedValue;
	debug(parsedValue);
    std::string::size_type decimalPos = s.find('.');
    if (decimalPos == std::string::npos) {
        return false;
    }

    std::string integerPart = s.substr(0, decimalPos);
    std::string fractionalPart = s.substr(decimalPos + 1);

	if (fractionalPart.length() > 15)
	{
		debug(fractionalPart.length());
		return true;
	}
	return false;
}

bool isFractionalPartTooSmallFloat(const std::string &s) {
    std::istringstream iss(s);
    float parsedValue;
    iss >> parsedValue;
	debug(parsedValue);
    std::string::size_type decimalPos = s.find('.');
    if (decimalPos == std::string::npos) {
        return false;
    }

    std::string integerPart = s.substr(0, decimalPos);
    std::string fractionalPart = s.substr(decimalPos + 1);
	if (fractionalPart.length() > 5)
	{
		return true;
	}
    if (fractionalPart.find_first_not_of('0') == std::string::npos) {
        return false;
    }

    float reconstructedValue;
    std::istringstream issInteger(integerPart);
    issInteger >> reconstructedValue;

    float fractionalValue = parsedValue - reconstructedValue;
    if (std::abs(fractionalValue) < std::numeric_limits<float>::denorm_min()) {
        return true;
    }
    return false;
}

static bool isChar(const std::string &s)
{
	if (s.length() != 1 || !isprint(s[0]))
	{
		return false;
	}
	return true;
}

static bool isInt(const std::string &s)
{
	char *end;
	long val = std::strtol(s.c_str(), &end, 10);

    if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
	{
        return false;
    }
	return *end == '\0';
}

static bool isFloat(const std::string &s)
{
	if (isFractionalPartTooSmallFloat(s))
	{
		return false;
	}
	char *end;
	errno = 0;
	std::strtof(s.c_str(), &end);
	debug(std::strtof(s.c_str(), &end));
	if ((*end == '\0' || *end == 'f') && end != s.c_str() && errno == 0)
	{
		return true;
	}
	return false;
}

static bool isDouble(const std::string &s)
{
	if (isFractionalPartTooSmallDouble(s))
	{
		return false;
	}
	char *end;
	std::strtod(s.c_str(), &end);

	if (*end == '\0' && end != s.c_str())
	{
		return true;
	}
	return false;
}

static int findType(std::string literal)
{
	if (isInt(literal))
	{
		return INT;
	}
	else if (isChar(literal))
	{
		return CHAR;
	}
	else if (isFloat(literal))
	{
		return FLOAT;
	}
	else if (isDouble(literal))
	{
		return DOUBLE;
	}
	return NUM_TYPES;
}
// 9876.000000000001
static std::string formatDouble(double value, unsigned int precision) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision) <<  value;
    std::string str = out.str();

    std::string::size_type pos = str.find_last_not_of('0');

    if (pos != std::string::npos) {
        if (str[pos] == '.') {
            str.erase(pos);
        } else {
            str.erase(pos + 1);
        }
    }

    return str;
}

static void print_char(int c)
{
	debug("print_char called.");
	if (c < 0 || c >= 128)
	{
		std::cout << "char:\t" << "impossible" << std::endl;
	}
	else if (!isprint(c))
	{
		std::cout << "char:\t" << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char:\t'" << static_cast<char>(c) << "'" << std::endl;
	}
}

static void print_int(long int i)
{
	debug("print_int called.");
	if (i >= INT_MIN && i <= INT_MAX)
	{
		std::cout << "int:\t" 	<< i <<	std::endl;
	}
	else
	{
		std::cout << "int:\t" << "impossible" << std::endl;
	}
}

static void print_float(float f, unsigned int precision, std::string literal)
{
	debug("print_float called.");
	if (std::isnan(f) || std::isinf(f))
	{
		std::cout << "float:\t" << std::fixed << f << "f" << std::endl;
	}
	else if (f <= std::numeric_limits<float>::max()
		&& f >= -std::numeric_limits<float>::max()
		&& !isFractionalPartTooSmallFloat(literal))
	{
		if (f - static_cast<int>(f) > 0)
		{
			std::cout << "float:\t" << std::fixed << formatDouble(f, precision) << "f" << std::endl;
		}
		else
		{
			std::cout << "float:\t" << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		}
		std::cout << std::resetiosflags(std::ios::fixed);
	}
	else
	{
		std::cout << "float:\t" << "impossible" << std::endl;
	}
}

static void print_double(long double d, unsigned int precision)
{
	debug("print_double called.");
	if (std::isnan(d) || std::isinf(d))
	{
		std::cout << "double:\t" << std::fixed << d << std::endl;
	}
	else if (d <= std::numeric_limits<double>::max()
		&& d >= -std::numeric_limits<double>::max())
	{
		if (d - static_cast<int>(d) > 0)
		{
			std::cout << "double:\t" << std::fixed << formatDouble(d, precision) <<	std::endl;
		}
		else
		{
			std::cout << "double:\t" << std::fixed << std::setprecision(1) << d <<	std::endl;
		}
		std::cout << std::resetiosflags(std::ios::fixed);
	}
	else
	{
		std::cout << "double:\t" << "impossible" << std::endl;
	}
}

static unsigned int getPrecision(const std::string & s)
{
	std::string::size_type decimalPos = s.find('.');
	if (decimalPos == std::string::npos)
	{
        return 0;
    }
	return s.substr(decimalPos + 1).length();
}

void ScalarConverter::convert(std::string literal)
{
	char c;
	int i;
	float f;
	double d;
	unsigned int precision;

	switch (findType(literal))
	{
		case CHAR:
		{
			debug("CHAR");
			c = literal[0];
			print_char(static_cast<int>(c));
			print_int(static_cast<long int>(c));
			print_float(static_cast<float>(c), 0, literal);
			print_double(static_cast<long double>(c), 0);
			break;
		}
		case INT:
		{
			debug("INT");
			i = std::strtol(literal.c_str(), NULL, 10);
			print_char(static_cast<int>(i));
			print_int(static_cast<long int>(i));
			print_float(static_cast<double>(i), 0, literal);
			print_double(static_cast<long double>(i), 0);
			break;
		}
		case FLOAT:
		{
			debug("FLOAT");
			precision = getPrecision(literal);
			f = std::strtof(literal.c_str(), NULL);
			print_char(static_cast<int>(f));
			print_int(static_cast<long int>(f));
			print_float(static_cast<float>(f), precision, literal);
			print_double(static_cast<long double>(f), precision);
			break;
		}
		case DOUBLE:
		{
			debug("DOUBLE");
			precision = getPrecision(literal);
			d = std::strtold(literal.c_str(), NULL);
			debug(d);
			print_char(static_cast<int>(d));
			print_int(static_cast<long int>(d));
			print_float(static_cast<double>(d), precision, literal);
			print_double(static_cast<long double>(d), precision);
			break;
		}
		default:
		{
			std::cout << "Error" << std::endl;
			break;
		}
	}
}
