#ifndef ICE_HPP
#define ICE_HPP

# include <string>
# include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(std::string const & type);
	Ice(const Ice &copy);
	Ice & operator=(const Ice & copy);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif