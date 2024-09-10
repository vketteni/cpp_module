#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <deque>
# include <stack>
# include "Debug.hpp"

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T>
{
  public:
	MutantStack()
	{
	}
	~MutantStack()
	{
	}
	MutantStack(const MutantStack &stack) : std::stack<T>() 
	{
		*this = stack;
	}
	typedef typename container::iterator iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};

#endif
