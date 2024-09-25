#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <cmath>
# include <algorithm>
# include <list>
# include <vector>
# include <string>
# include <iostream>
# include <sstream> 
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <iterator>
# include "Debug.hpp"

# define LIST_TYPE 0
# define VECTOR_TYPE 1

class PmergeMe
{
	public:
		static const std::list<int> sort(std::list<int> & l);
		static const std::vector<int> sort(std::vector<int> & v);

	private:
		PmergeMe();
		PmergeMe(const PmergeMe & other);
		PmergeMe & operator=(const PmergeMe & other);
		~PmergeMe();
};

template <typename T>
void printContainer(T & container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it;
		if (it != --(container.end())) 
			std::cout << " ";
	}
	std::cout << std::endl;
}


#endif