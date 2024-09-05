#include "Base.hpp"

int	main(void)
{
	 Base *random_class = generate();

	 identify(random_class);
	 identify(*random_class);
}