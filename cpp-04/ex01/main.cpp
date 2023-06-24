#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::string str;
	Animal *meta[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}
	std::cout << std::endl;
	
	for (size_t i = 0; i < 10; i++)
		delete meta[i];
	std::cout << std::endl;
	

	Dog *d = new Dog();
	Dog *d2 = new Dog();
	std::cout << std::endl; // 하나의 idea만 갖고와서 비교하게?
	str = d->getBrain()->getOneIdea(0);
	std::cout << "Before Dog1's first idea is "<< str << std::endl;

	d->getBrain()->setIdeas("something", 0);
	str = d->getBrain()->getOneIdea(0);
	std::cout << "After Dog1's first idea is "<< str << std::endl;

	// *d2 = *d;
	// str = d2->getBrain()->getIdeas(0);
	// std::cout << "Dog2's first idea is "<< str << std::endl;

	// std::cout << std::endl;
	// delete d;
	// d = NULL;
	// delete d2;
	// d2 = NULL;

	return 0;
}