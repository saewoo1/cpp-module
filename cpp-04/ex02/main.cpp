#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::string str;
	std::string str2;
	Animal *meta[10];
	// Animal a; abstract class animal -> error!

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2){
			meta[i] = new Dog();
			meta[i]->makeSound();
		}
		else {
			meta[i] = new Cat();
			meta[i]->makeSound();
		}
	}
	std::cout << std::endl;
	
	for (size_t i = 0; i < 10; i++)
		delete meta[i];
	std::cout << std::endl;
	std::cout << "--------------------------- deep / shallow ---------------------------\n";

	Dog *d = new Dog();
	Dog *d2 = new Dog();
	std::cout << std::endl; // 하나의 idea만 갖고와서 비교하게?
	str = d->getBrain()->getOneIdea(0);
	std::cout << "Before Dog1's first idea is "<< str << std::endl;

	d->getBrain()->setIdeas("WOOOOOOOO......", 0);
	str = d->getBrain()->getOneIdea(0);
	std::cout << "After Dog1's first idea is "<< str << std::endl;

	*d2 = *d;
	d->getBrain()->setIdeas("WOW~!!!!!!!!!!!! cut!", 0);
	str = d->getBrain()->getOneIdea(0);
	std::cout << "After Dog1's first idea is changed again!!! " << str << std::endl;
	str2 = d2->getBrain()->getOneIdea(0);
	std::cout << "Dog2's first idea is "<< str2 << std::endl;


	std::cout << std::endl;
	delete d;
	d = NULL;
	delete d2;
	d2 = NULL;

	// system("leaks a.out");
	return 0;
}