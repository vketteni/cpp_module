#ifndef SPAN_HPP
#define SPAN_HPP

# include <cstdlib>
# include <climits>
# include <algorithm>
# include <vector>
# include <cstddef>
# include "Debug.hpp"

# include <iostream>
# include <ctime>
# include <stdexcept>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span & other);
		Span & operator=(const Span & other);
		~Span();
		const int				N;

		const std::vector<int>	getSpan(void) const;
		unsigned int			shortestSpan(void) const;
		unsigned int			longestSpan(void) const;
		void					addNumber(int n);
		void					addRangeInclusive(int start, int end);
	private:
		std::vector<int>		_span;
};

#endif