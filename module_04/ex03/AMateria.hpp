#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <string>
# include "Debug.hpp"
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string type;
	public:
		AMateria(void);
		AMateria(const AMateria & other);
		AMateria(const std::string & type);
		std::string const & getType() const;

		virtual ~AMateria(void);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif