#ifndef	ITER_HPP
#define	ITER_HPP

# include <string>
# include <iostream>

template <typename A, typename L, typename F>
void iter(A &array, L length, F function)
{
	for (unsigned int i = 0; i < length; i++)
	{
		function(array[i]);
	}
};

#endif