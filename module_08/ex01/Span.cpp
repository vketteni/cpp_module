#include "Span.hpp"

Span::Span() : N(0), _span(std::vector<int>())
{
}

Span::Span(unsigned int N) : N(N), _span(std::vector<int>())
{
}

Span::Span(const Span &other) : N(other.N),
	_span(std::vector<int>(other.getSpan()))
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		*this = Span(other.N);
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
	if (std::distance(_span.begin(), _span.end()) < N)
	{
		_span.insert(_span.end(), num);
	}
	else
		throw std::exception();
}

void Span::addRangeInclusive(int start, int end)
{
	int random;
	std::srand(std::time(0));
	for (int i = 0; i < N; ++i)
	{
		random = start + std::rand() % (end - start + 1);
		addNumber(random);
	}
}

const std::vector<int> Span::getSpan(void) const
{
	return (_span);
}

unsigned int Span::shortestSpan(void) const
{
	if (_span.size() < 2)
		throw std::exception();
	unsigned int shortestSpan = INT_MAX;
	std::vector<int> span_cpy;
	std::copy(_span.begin(), _span.end(), std::back_inserter(span_cpy));
	std::sort(span_cpy.begin(), span_cpy.end());
	for (std::vector<int>::const_iterator numIt = span_cpy.begin()
		+ 1; numIt != span_cpy.end(); ++numIt)
	{
		unsigned int current_span = std::abs(*(numIt - 1) - *numIt);
		shortestSpan = current_span < shortestSpan ? current_span : shortestSpan;
	}
	return (shortestSpan);
}

unsigned int Span::longestSpan(void) const
{
	if (_span.size() < 2)
		throw std::exception();
	unsigned int longestSpan = 0;
	for (std::vector<int>::const_iterator spanStart = _span.begin(); spanStart != _span.end(); ++spanStart)
	{
		for (std::vector<int>::const_iterator spanEnd = spanStart
			+ 1; spanEnd != _span.end(); ++spanEnd)
		{
			unsigned int current_span = std::abs(*spanStart - *spanEnd);
			if (current_span > longestSpan)
				longestSpan = current_span;
		}
	}
	return (longestSpan);
}
