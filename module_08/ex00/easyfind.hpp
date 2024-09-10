#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

# include <algorithm>

template <typename T>
int easyfind(T & container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);

	if (it != container.end())
		return std::distance(container.begin(), it);
	return -1;
}

#endif