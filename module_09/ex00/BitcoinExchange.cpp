#include "BitcoinExchange.hpp"
#include <unistd.h>
#include <cmath>

std::deque<std::deque<std::string> > BitcoinExchange::readDb(const std::string &db,
	const char sep)
{
	size_t	pos;

	std::ifstream file(db.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open internal database.\n";
		return std::deque<std::deque<std::string> >();
	}
	std::deque<std::deque<std::string> > dbParsed;
	std::string line;
	while (std::getline(file, line))
	{
		std::deque<std::string> row;
		pos = 0;
		while ((pos = line.find(sep)) != std::string::npos)
		{
			std::string field = line.substr(0, pos);
			size_t space = 0;
			while ((space = field.find(' ')) != std::string::npos)
				field.erase(space, 1);
			row.push_back(field);
			line.erase(0, pos + 1);
		}
		row.push_back(line);
		if (line.c_str() && row.size() != 2)
			continue;
		dbParsed.push_back(row);
	}
	file.close();
	return (dbParsed);
}

bool BitcoinExchange::isValidValue(const std::string &value)
{
	if (value.empty())
		return false;
	char *endPtr = NULL;
	errno = 0;
	float dbValue = strtof(value.c_str(), &endPtr);
	if (endPtr == value.c_str())
		return false;
	if (*endPtr != '\0')
		return false;
	if (errno == ERANGE)
	{
        if (dbValue == HUGE_VALF || dbValue == -HUGE_VALF) {
            return false;
        } else if (dbValue == 0.0f) {
            return false;
        }
    }
	if (dbValue < 0 || dbValue > 1000)
		return false;
	return true;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return *this;
}

BitcoinExchange::BitcoinExchange() 
{
}

BitcoinExchange::BitcoinExchange(const std::string &accountDb)
{
	_exchangeRates = readDb(EXCHANGERATE_CSV, ',');

	_accountData = readDb(accountDb, '|');
	// for (std::deque<std::deque<std::string> >::const_iterator it = _accountData.begin(); it != _accountData.end(); ++it)
	// {
	// 	std::cout << (*it).at(0) << " " << (*it).at(1) << std::endl;
	// }

}

void BitcoinExchange::printHistory(void)
{
	std::deque<std::deque<std::string> >::const_iterator accountRow = _accountData.begin();
	for (; accountRow != _accountData.end(); ++accountRow)
	{
		if (accountRow->size() != 2)
		{
			std::cerr << "Error: bad input => " << (accountRow->size() > 0 ? accountRow->at(0) : "") << std::endl;
			continue;
		}

		const std::string & accountDateRaw = (*accountRow).at(0);
		const std::string & accountValueRaw = (*accountRow).at(1);
		
		if (!validDateFormat(accountDateRaw))
		{
			std::cerr << "Error: bad input => " << accountDateRaw << std::endl;
			continue;
		}
		
		if (!isValidValue(accountValueRaw))
		{
			char *endPtr = NULL;
			errno = 0;
			float value = strtof(accountValueRaw.c_str(), &endPtr);
			
			if (endPtr == accountValueRaw.c_str() || *endPtr != '\0')
				std::cerr << "Error: bad input => " << accountValueRaw << std::endl;
			else if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else
				std::cerr << "Error: bad input => " << accountValueRaw << std::endl;
			continue;
		}
		
		Date accountDate(accountDateRaw);
		if (!accountDate.validDate)
		{
			std::cerr << "Error: bad input => " << accountDateRaw << std::endl;
			continue;
		}
		
		float accountValue = strtof(accountValueRaw.c_str(), NULL);
		float rateValue = 0.0f;
		bool foundRate = false;
		
		std::deque<std::deque<std::string> >::const_iterator rateRow = _exchangeRates.begin();
		for (; rateRow != _exchangeRates.end(); ++rateRow)
		{
			const std::string & rateDateRaw = (*rateRow).at(0);
			const std::string & rateValueRaw = (*rateRow).at(1);
			Date dateExchangeRate(rateDateRaw);
			
			if (dateExchangeRate == accountDate)
			{
				rateValue = strtof(rateValueRaw.c_str(), NULL);
				foundRate = true;
				break;
			}
			else if (dateExchangeRate > accountDate && rateRow != _exchangeRates.begin())
			{
				rateValue = strtof((*(rateRow - 1)).at(1).c_str(), NULL);
				foundRate = true;
				break;
			}
		}
		
		if (!foundRate && !_exchangeRates.empty())
		{
			std::deque<std::deque<std::string> >::const_iterator lastRow = _exchangeRates.end() - 1;
			rateValue = strtof(lastRow->at(1).c_str(), NULL);
			foundRate = true;
		}
		
		if (foundRate)
		{
			std::cout << accountDateRaw << " => " << accountValue << " = " << accountValue * rateValue << std::endl;
		}
	}
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::Date::Date(const std::string& dateStr)
{
	if (!validDateFormat(dateStr))
	{
		validDate = false;
		return;
	}

	year = atoi(dateStr.substr(0, 4).c_str());
	month = atoi(dateStr.substr(5, 2).c_str());
	day = atoi(dateStr.substr(8, 2).c_str());

	int daysInMonth;
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		daysInMonth = 29;
	else if (month == 2)
		daysInMonth = 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		daysInMonth = 30;
	else 
		daysInMonth = 31;
	
	if (day <= daysInMonth && month <= 12 && year > 2008)
	{
		std::time_t current_time = std::time(0);
		std::tm* local_time = std::localtime(&current_time);
		int currentDay = local_time->tm_mday;
		int currentMonth = local_time->tm_mon + 1;
		int currentYear = local_time->tm_year + 1900;

		if (year != currentYear) validDate = year < currentYear;
		else if (month != currentMonth) validDate =  month < currentMonth;
		else validDate =  day < currentDay;
	}
	else
		validDate = false;
}

bool BitcoinExchange::Date::operator<(const Date& other) const
{
	if (year != other.year) return year < other.year;
	if (month != other.month) return month < other.month;
	return day < other.day;
}

bool BitcoinExchange::Date::operator==(const Date& other) const
{
	return year == other.year && month == other.month && day == other.day;
}

bool BitcoinExchange::Date::operator>(const Date& other) const
{
	return !(*this < other || *this == other);
}

bool BitcoinExchange::Date::operator>=(const Date& other) const
{
	return (*this > other || *this == other);
}

bool BitcoinExchange::Date::operator<=(const Date& other) const
{
	return (*this < other || *this == other);
}

bool BitcoinExchange::validDateFormat(const std::string & accountDateRaw)
{
	for (unsigned int i = 0; i < accountDateRaw.size(); ++i)
	{
		char currentChar = accountDateRaw.c_str()[i];
		if (i == 4 || i == 7) {
			if (currentChar != '-')
				return false;
		}
		else if (!std::isdigit(currentChar))
			return false;
	}
	return true;
}