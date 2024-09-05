#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat animal_lover("Bob", 150);
	Bureaucrat president("Peter", 1);

	Form harz4("Arbeitslosengeld IV", 10, 100);

	header("Grade Too Low Test");
	animal_lover.signForm(harz4);
	try
	{
		harz4.beSigned(animal_lover);
	}
	catch ( std::exception & e) { debug(e.what()) }

	header("Grade Sufficient Test");
	president.signForm(harz4);
	try
	{
		harz4.beSigned(president);
	}
	catch ( std::exception & e) { debug(e.what()) }
}