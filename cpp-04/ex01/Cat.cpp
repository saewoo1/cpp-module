#include "Cat.hpp"

Cat::Cat(void) {
	this->type = "Cat";
	this->brain = new Brain;
	std::cout << "Cat... constructor is called with new brain" << std::endl;
}
Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat destructor is called and brain is gone" << std::endl;
}
Cat::Cat(const Cat &obj)
{
	this->type = obj.type;
	this->brain = new Brain(*(obj.getBrain()));
	std::cout << "Cat class copy constructor is called with new brain" << std::endl;
}
Cat& Cat::operator=(const Cat &obj) {
	this->type = obj.getType();
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*(obj.getBrain()));
	return (*this);
}

void Cat::makeSound(void) const{
	std::cout << "nyang nyang nyang~" << std::endl; 
}

std::string Cat::getType(void) const {
	return (this->type);
}

Brain *Cat::getBrain(void) const {
	return (this->brain);
}
