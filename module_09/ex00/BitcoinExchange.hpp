#ifndef	BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

# include <string>
# include <vector>
# include <deque>
# include <algorithm>
# include <iostream>
# include <fstream>
# include <cstdlib> 
# include <cctype>
# include <ctime>
# include <cerrno>
# include <climits> 
# include "Debug.hpp"

# define EXCHANGERATE_CSV  "data.csv"

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string & exchangeRateDb);
		void	printHistory(void);
		~BitcoinExchange();

	private:
		BitcoinExchange(const BitcoinExchange & other);
		BitcoinExchange & operator=(const BitcoinExchange & other);
		BitcoinExchange();

		std::deque< std::deque<std::string> >	_accountData;
		std::deque<std::deque<std::string> >	_exchangeRates;

		std::deque<std::deque<std::string> >	readDb(const std::string & db, const char sep);
		static bool validDateFormat(const std::string & date);
		static bool isValidValue(const std::string & value);

		struct Date {
			int year;
			int month;
			int day;
			bool validDate;

			Date(const std::string& dateStr); 

			bool operator<(const Date& other) const; 
			bool operator==(const Date& other) const; 
			bool operator>(const Date& other) const; 
			bool operator>=(const Date& other) const; 
			bool operator<=(const Date& other) const; 
		};


};

#endif