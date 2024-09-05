#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include "Debug.hpp"

# define BRAIN_SIZE 100

class Brain {
private:
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();
	std::string ideas[BRAIN_SIZE];
};

#endif // BRAIN_HPP