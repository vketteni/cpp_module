#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperant(const std::string & input)
{
	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
	{
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}

bool RPN::isOperation(const std::string & input)
{
	return std::strchr("+-*/", *(input.c_str()));
}

void RPN::compute(std::string calculation)
{
    std::istringstream iss(calculation);
    std::string token;
	std::stack<std::string> temp;
	std::stack<std::string> tempOperants;

    while (iss >> token)
		temp.push(token);
    std::stack<std::string> RPNInputs;
    while (!temp.empty())
	{
        RPNInputs.push(temp.top());
        temp.pop();
    }

    std::stack<std::string> operants;
	std::string operation = "";
	while (!RPNInputs.empty())
	{
		std::string input = RPNInputs.top();
		if (isOperation(input))//(std::atoi(input.c_str()) <= 10))
		{
			if (operants.size() < 2)
			{
				std::cerr << "Error: Operation queued but not enough operants in stack.\n";
				return ;
			}
			//
			operation = input;
			debug(operants.top());
			double operant_a = std::atoi(operants.top().c_str());
			operants.pop();
			debug(operants.top());
			double operant_b = std::atoi(operants.top().c_str());
			operants.pop();

			double calculation = 0;
			debug(*(operation.c_str()));
			switch (*(operation.c_str()))
			{
				case '+':
					calculation = operant_b + operant_a;
					break;
				case '-':
					calculation = operant_b - operant_a;
					break;
				case '*':
					calculation = operant_b * operant_a;
					break;
				case '/':
					calculation = operant_b / operant_a;
					break;
				default:
					break;
			}
			if (calculation < INT_MIN || calculation > INT_MAX)
			{
				std::cerr << "Error: Result of operation out of integer bounds: " << std::endl;
				return ;
			}

			std::ostringstream oss;
			oss << calculation;
			std::string nextOperant = oss.str();
			operants.push(nextOperant);

			// 
		}
		else if (isOperant(input))
			operants.push(input);
		else
		{
			debug(input);
			std::cerr << "Error\n";
			return ;
		}
		RPNInputs.pop();
	}
	std::cout << operants.top() << std::endl;
}
