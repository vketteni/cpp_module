#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Debug.hpp"

int main()
{
	header("IMateriaSource")
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	header("ICharacter")
	ICharacter* me = new Character("me");

	header("AMateria")
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	header("Character->use")
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	header("Destruction")
	delete bob;
	delete me;
	delete src;
	
return 0;
}