#include "Span.hpp"
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

bool isNumber(const std::string& s) {
    std::istringstream iss(s);
    double num;
    iss >> num;

    return !iss.fail() && iss.eof();
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !isNumber(argv[1]))
		return EXIT_FAILURE;
    std::istringstream iss(argv[1]);
    double N;
    iss >> N;
	Span s(N);
														// s.addRange(50, 100);	
	int random;
	std::srand(std::time(0));
	for (int i = 0; i < N; ++i)
	{
		random = std::rand();
		s.addNumber(random);
		std::cout << random;
														// std::cout << s.getSpan().at(i);
		if (i < N - 1)
			std::cout << " ";
	}
		std::cout << std::endl;
		
	header("shortest span");
	debug(s.shortestSpan());
	header("longest span");
	debug(s.longestSpan());

	return EXIT_SUCCESS;
}

// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }