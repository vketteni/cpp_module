#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <cstring>
# include "Brain.hpp"

class AAnimal {
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const AAnimal& other);
	virtual AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();
	virtual void makeSound() const = 0;
	virtual std::string getType() const;
};

#endif // ANIMAL_HPP