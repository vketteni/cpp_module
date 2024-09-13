#include "BitcoinExchange.hpp"
#include <unistd.h>
#include <cmath>

std::vector<std::vector<std::string> > BitcoinExchange::readDb(const std::string &db,
	const char sep)
{
	size_t	pos;

	std::ifstream file(db.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open internal database.\n";
		return std::vector<std::vector<std::string> >();
	}
	std::vector<std::vector<std::string> > dbParsed;
	std::string line;
	while (std::getline(file, line))
	{
		std::vector<std::string> row;
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

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	Date dbDate(date);
	return dbDate.validDate;
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
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
/* 	if (!isValidFormat(_exchangeRates))
	{	
		std::cerr << "Warning: Exchange rates data doesn't comply with required format.\n";
		return ;
	} */
	_accountData = readDb(accountDb, '|');
	for (std::vector<std::vector<std::string> >::const_iterator it = _accountData.begin(); it != _accountData.end(); ++it)
	{
		std::cout << (*it).at(0) << " " << (*it).at(1) << std::endl;
	}
/* 	if (!isValidFormat(_accountData))
	{
		std::cerr << "Warning: Account data doesn't comply with required format.\n";
		return ;
	} */
}

void BitcoinExchange::printHistory(void)
{
	for (std::vector<std::vector<std::string> >::const_iterator accountRow = _accountData.begin(); accountRow != _accountData.end(); ++accountRow)
	{
		const std::string & dateAccountRow = (*accountRow).at(0);
		const std::string & valueAccountRow = (*accountRow).at(1);
		if (!isValidDate(dateAccountRow) || !isValidValue(valueAccountRow))
			continue;

		Date dateAccount(dateAccountRow);
		for (std::vector<std::vector<std::string> >::const_iterator exchangeRateRow = _exchangeRates.begin(); exchangeRateRow != _exchangeRates.end(); ++exchangeRateRow)
		{
			const std::string & dateExchangeRateStr = (*exchangeRateRow).at(0);
			const std::string & valueExchangeRateStr = (*exchangeRateRow).at(1);
			Date dateExchangeRate(dateExchangeRateStr);
			if (!isValidDate(dateExchangeRateStr) || !isValidValue(valueExchangeRateStr))
				continue ;	
			float valueAccount = strtof(valueAccountRow.c_str(), NULL);
			if (dateExchangeRate == dateAccount)
			{
				float valueExchangeRate = strtof(valueExchangeRateStr.c_str(), NULL);
				std::cout << dateAccountRow << " => " << valueAccount << " * " << valueExchangeRate << " = " << valueAccount * valueExchangeRate << std::endl;
				break;
			}
			else if (dateExchangeRate > dateAccount && exchangeRateRow != _exchangeRates.begin())
			{

				float valueExchangeRate = strtof((*(exchangeRateRow - 1)).at(1).c_str(), NULL);
				std::cout << dateAccountRow << " => " << valueAccount << " * " << valueExchangeRate << " = " << valueAccount * valueExchangeRate << std::endl;
				break;
			}

/* 			const std::string & dateExchangeRateStr = (*exchangeRateRow).at(0);
			const std::string & valueExchangeRateStr = (*exchangeRateRow).at(1);
			Date dateExchangeRate((*exchangeRateRow).at(0));
			if (!isValidDate(dateExchangeRateStr) || !isValidValue(valueExchangeRateStr))
				continue ;	
			if (dateExchangeRate < dateAccount)
				continue ;
			else if (dateExchangeRate == dateAccount)
			{
				float valueAccount = strtof(valueAccountRow.c_str(), NULL);
				float valueExchangeRate = strtof(valueExchangeRateStr.c_str(), NULL);
			}
			else if (exchangeRateRow != _exchangeRates.begin())
			{
				float valueAccount = strtof((*(exchangeRateRow - 1)).at(0).c_str(), NULL);
				float valueExchangeRate = strtof((*(exchangeRateRow - 1)).at(1).c_str(), NULL);
			}
			else 
				continue; */

			// std::cout << dateAccountRow << " => " << valueAccountRow << " = " << valueAccount * valueExchangeRate << std::endl;
		}
	}
}

BitcoinExchange::~BitcoinExchange()
{
}
