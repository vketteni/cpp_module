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
	if (input.length() != 1)
		return false;
	return (input[0] >= '0' && input[0] <= '9');
}

bool RPN::isOperation(const std::string & input)
{
	return (input.length() == 1 && std::strchr("+-*/", input[0]) != NULL);
}

void RPN::compute(std::string calculation)
{
	std::istringstream iss(calculation);
	std::string token;
	std::stack<double> operants;

	while (iss >> token)
	{
		if (isOperant(token))
		{
			double num = std::atoi(token.c_str());
			operants.push(num);
		}
		else if (isOperation(token))
		{
			if (operants.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return;
			}

			double operant_a = operants.top();
			operants.pop();
			double operant_b = operants.top();
			operants.pop();

			double result = 0;
			switch (token[0])
			{
				case '+':
					result = operant_b + operant_a;
					break;
				case '-':
					result = operant_b - operant_a;
					break;
				case '*':
					result = operant_b * operant_a;
					break;
				case '/':
					if (operant_a == 0)
					{
						std::cerr << "Error" << std::endl;
						return;
					}
					result = operant_b / operant_a;
					break;
			}
			operants.push(result);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}

	if (operants.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return;
	}

	std::cout << operants.top() << std::endl;
}
