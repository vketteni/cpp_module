#include "PmergeMe.hpp"

static void intializeContainers(int argc, char **argv, std::vector<int> & v, std::list<int> & l)
{
	for (int i = 1; i < argc; ++i)
	{
		const std::string s(argv[i]);
		for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
		{
			if (!std::isdigit(*it))
			{
				std::cout << "Error\n";
				exit(1);
			}
		}
		int num;
		std::istringstream(s) >> num;
		v[i - 1] = num;
		l.push_back(num);
	}
}

template <typename T>
int identify(const std::vector<T>&)
{
    return VECTOR_TYPE;
}

template <typename T>
int identify(const std::list<T>&)
{
    return LIST_TYPE;
}

static void printBeforeAfter(int argc, char **argv)
{
	std::vector<int> v(argc - 1);
	std::list<int> l;

	intializeContainers(argc, argv, v, l);
	std::cout << "Before: ";
	for (int i = 0; i < argc - 1; ++i)
	{
		std::cout << v.at(i);
		if (i < argc - 1) 
			std::cout << " ";
	}
	std::cout << std::endl;
	std::sort(v.begin(), v.end());
	std::cout << "After: ";
	for (int i = 0; i < argc - 1; ++i)
	{
		std::cout << v.at(i);
		if (i < argc - 1) 
			std::cout << " ";
	}
	std::cout << std::endl;
}

static double calculate_time(timespec & start, timespec & end)
{
	return ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec)) / 1e3;
}

template <typename T>
static void run(T & container, timespec & start, timespec & end)
{
    clock_gettime(CLOCK_MONOTONIC, &start);
	container = PmergeMe::sort(container);
    clock_gettime(CLOCK_MONOTONIC, &end);
}

template <typename T>
static void printTime(T & container, timespec & start, timespec & end)
{
	double elapsedSeconds = calculate_time(start, end);
	const std::string containerType = identify(container) == LIST_TYPE ? "list" : "vector";

	std::cout << std::setprecision(3);
	std::cout 
		<< "Time to process a range of " 
		<< container.size() 
		<< " elements with std::[" << containerType << "] : " 
		<< std::fixed << elapsedSeconds
		<< " us" << std::endl;
}

template <typename T>
static bool isSorted(T & container)
{
	int a, b;
	typename T::iterator secondLastIt = --(container.end());
	for (typename T::iterator it = container.begin(); it != secondLastIt; ++it)
	{
		a = *it;
		++it;
		b = *it;
		--it;
		if (a > b)
			return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	std::vector<int> v(argc - 1);
	std::list<int> l;

	intializeContainers(argc, argv, v, l);
	printBeforeAfter(argc, argv);
	(void)printBeforeAfter;
	timespec vStart, vEnd, lStart, lEnd;
	run(v, vStart, vEnd);
	run(l, lStart, lEnd);
	printTime(v, vStart, vEnd);
	printTime(l, lStart, lEnd);
	header("isSorted ? 1 == true");
	debug(isSorted(v));
	debug(isSorted(l));
	header("Vector")
	// printContainer(v);
}