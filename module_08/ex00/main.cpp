#include "easyfind.hpp"
#include <map>
#include <vector>
#include <list>
#include "Debug.hpp"

template <typename A, typename F>
void iter(A &container, F function) {
    for (typename A::iterator it = container.begin(); it != container.end(); ++it)
	{
        function(*it);
    }
}

template <typename T>
void print(T &value) {
    std::cout << value << std::endl;
}

int	main(void)
{
	header("vector container")
	std::vector<int> v;
	v.insert(v.end(), 0);
	v.insert(v.end(), 1);
	v.insert(v.end(), 2);
	v.insert(v.end(), 3);

	iter(v, print<int>);
	debug(easyfind(v, 3));
	newLine();

	header("list container")
	std::list<int> l;
	l.insert(l.end(), 0);
	l.insert(l.end(), 1);
	l.insert(l.end(), 2);
	l.insert(l.end(), 3);

	iter(l, print<int>);
	debug(easyfind(l, 3));
}