#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int	main(void)
{
	header("Animal Test")
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	newLine()
	header("WrongAnimal Test")
	const WrongAnimal* wrong_cat = new WrongCat();
	const WrongCat* wrong_cat2 = new WrongCat();
	std::cout << wrong_cat->getType() << " " << std::endl;
	std::cout << wrong_cat2->getType() << " " << std::endl;
	wrong_cat->makeSound();
	wrong_cat2->makeSound();
	delete wrong_cat;
	delete wrong_cat2;
}