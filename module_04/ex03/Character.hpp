#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string>

# define INVENTORY_SIZE 4
class Character : public ICharacter {
  private:
	AMateria *_inventory[INVENTORY_SIZE];
	std::string _name;
  public:
	Character();
	Character(const std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();
	void equip(AMateria *m);
	void unenquip(int idx);
	void use(int idx, ICharacter &target);
	std::string const & getName() const;
};

#endif // CHARCTER_HPP