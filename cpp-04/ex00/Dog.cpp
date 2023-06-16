#include "Dog.hpp"

Dog::Dog(void) {
	this->type = "Dog";
	std::cout << "Dog... "+ this->type + " constructor is called" << std::endl;
}
Dog::~Dog(void)
{
	std::cout << "Dog " << type << " destructor is called" << std::endl;
}
Dog::Dog(const Dog &obj)
{
	this->type = obj.type;
	std::cout << "Dog class " << this->type << " copy constructor is called" << std::endl;
}
Dog& Dog::operator=(const Dog &obj) {
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << "grrrrr.... bark!!!!!!!!!!!" << std::endl; 
}

std::string Dog::getType(void) const {
	return (this->type);
}