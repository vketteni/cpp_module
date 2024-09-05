#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Debug.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();
	void makeSound() const;
	std::string getType() const;

};

#endif // CAT_HPP