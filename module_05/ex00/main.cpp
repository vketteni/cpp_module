#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("Freddy", 150);

		debug(b)
		b.incrementGrade();
		debug(b)
		b.decrementGrade();
		debug(b)
		b.decrementGrade();
	}
	catch ( std::exception & e)
	{
		debug(e.what())
	}
	
	try
	{
		Bureaucrat bb("Bill", 1);
		debug(bb)
		bb.incrementGrade();

	}
	catch ( std::exception & e)
	{
		debug(e.what())
	}



}