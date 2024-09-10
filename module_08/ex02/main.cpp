#include "MutantStack.hpp"

int main(void)
{
// 	std::stack<int> s;
// 	MutantStack<int> m;


// 	header("push");
// 	m.push(42);
// 	s.push(42);
// 	debug(s.size());
// 	debug(m.size());

// 	header("top");
// 	debug(m.top());
// 	debug(s.top());

// 	header("empty");
// 	debug(m.empty());
// 	debug(s.empty());

// 	header("size");
// 	debug(s.size());
// 	debug(m.size());

// 	header("pop");
// 	s.pop();
// 	m.pop();
// 	debug(s.size());
// 	debug(m.size());



	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}