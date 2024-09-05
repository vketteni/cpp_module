#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Debug.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();
	std::string getType() const;
	void makeSound() const;
};

#endif // DOG_HPP