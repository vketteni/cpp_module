#include "Base.hpp"

Base	*generate(void)
{
	int	random;

	std::srand(std::time(0));
	random = (std::rand() % 3);
	switch (random)
	{
		case 0:
		{
			Base *a = new A();
			return (a);
		}
		case 1:
		{
			Base *b = new B();
			return (b);
		}
		case 2:
		{
			Base *c = new C();
			return (c);
		}
		default:
		{
			return NULL;
		}
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "class indentified as A" << std::endl;
	}
	else if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "class indentified as B" << std::endl;
	}
	else if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "class indentified as C" << std::endl;
	}
}

void	identify(Base &p)
{

	try 
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "class indentified as A" << std::endl;
	}
	catch (const std::exception & e)
	{
		;
	}
	try 
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "class indentified as B" << std::endl;
	}
	catch (const std::exception & e)
	{
		;
	}
	try 
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "class indentified as C" << std::endl;
	}
	catch (const std::exception & e)
	{
		;
	}
}

Base::~Base()
{
	
}
