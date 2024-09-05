#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <cstring>
# include "Brain.hpp"

class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& other);
	virtual Animal& operator=(const Animal& other);
	virtual ~Animal();
	virtual void makeSound() const;
	virtual std::string getType() const;
};

#endif // ANIMAL_HPP