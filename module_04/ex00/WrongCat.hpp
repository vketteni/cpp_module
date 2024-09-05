#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Debug.hpp"

class WrongCat : public WrongAnimal {
protected:
	std::string type;
public:
	WrongCat();
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat& other);
	~WrongCat();
	void makeSound() const;
	std::string getType() const;

};

#endif // WRONGCAT_HPP