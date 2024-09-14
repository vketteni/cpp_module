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

# define EXCHANGERATE_CSV  "/home/vketteni/42berlin/github/cpp_module/module_09/ex00/data.csv"

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
		bool isValidDate(const std::string & date) const;
		bool isValidValue(const std::string & value) const;

		struct Date
		{
			int year;
			int month;
			int day;
			bool validDate;

			Date(const std::string& dateStr) {
				validDate = true;
				for (unsigned int i = 0; i < dateStr.size(); ++i)
				{
					if (i != 4 && i != 7)
					{
						if (!isdigit(dateStr.c_str()[i]))
							validDate = false;
					}
					else if (dateStr.c_str()[i] != '-') validDate = false;
				}
				if (validDate)
				{
					year = atoi(dateStr.substr(0, 4).c_str());
					month = atoi(dateStr.substr(5, 2).c_str());
					day = atoi(dateStr.substr(8, 2).c_str());

					int daysInMonth;
					if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
						daysInMonth = 28;
					else if (month == 2)
						daysInMonth = 29;
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
			}

			bool operator<(const Date& other) const {
				if (year != other.year) return year < other.year;
				if (month != other.month) return month < other.month;
				return day < other.day;
			}

			bool operator==(const Date& other) const {
				return year == other.year && month == other.month && day == other.day;
			}

			bool operator>(const Date& other) const {
				return !(*this < other || *this == other);
			}

			bool operator>=(const Date& other) const {
				return (*this > other || *this == other);
			}

			bool operator<=(const Date& other) const {
				return (*this < other || *this == other);
			}
		};
};

#endif