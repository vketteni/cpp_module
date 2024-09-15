#ifndef RPN_HPP
#define RPN_HPP

# include <string>
# include <sstream>
# include <iostream>
# include <stack>
# include <climits>
# include <cstring>
# include <cstdlib>
# include "Debug.hpp"

class RPN
{
	private:
		RPN();
		RPN & operator=(const RPN & other);
		RPN(const RPN & other);
		~RPN();

		static bool isOperant(const std::string & input);
		static bool isOperation(const std::string & input);

	public:
		static void	compute(std::string input); 
};

#endif