#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "animal";
	std::cout << "Animal class " << type << " is called" << std::endl;
}
Animal::~Animal(void)
{
	std::cout << "Animal " << type << " destructor is called" << std::endl;
}
Animal::Animal(const Animal &obj)
{
	this->type = obj.type;
	std::cout << "Animal class " << this->type << " copy constructor is called" << std::endl;
}
Animal& Animal::operator=(const Animal &obj) {
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

// void Animal::makeSound(void) const {
// 	std::cout << "just.. animal animal..;;" << std::endl; 
// }

std::string Animal::getType(void) const {
	return (this->type);
}