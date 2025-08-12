#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"<RPN expression>\"" << std::endl;
		return 1;
	}
	RPN::compute(argv[1]);
	return 0;
}
