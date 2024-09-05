#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

# define TEMPLATE_SIZE 4

class MateriaSource : public IMateriaSource {
	private:
		AMateria* templates[TEMPLATE_SIZE];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource & other);
		MateriaSource & operator=(const MateriaSource & other);
		~MateriaSource();
		void learnMateria(AMateria* temp);
		AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE