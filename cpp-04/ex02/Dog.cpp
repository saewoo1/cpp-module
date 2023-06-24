#include "Dog.hpp"

Dog::Dog(void) {
	this->type = "Dog";
	this->brain = new Brain;
	std::cout << "Dog... constructor is called with new brain" << std::endl;
}
Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destructor is called and brain is gone" << std::endl;
}
Dog::Dog(const Dog &obj)
{
	this->type = obj.type;
	this->brain = new Brain(*(obj.getBrain()));
	std::cout << "Dog class copy constructor is called with new brain" << std::endl;
}
Dog& Dog::operator=(const Dog &obj) {
	this->type = obj.getType();
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*(obj.getBrain()));
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << "grrrrr.... bark!!!!!!!!!!!" << std::endl; 
}

std::string Dog::getType(void) const {
	return (this->type);
}

Brain *Dog::getBrain(void) const {
	return (this->brain);
}
